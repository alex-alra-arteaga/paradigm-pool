#include "../../../include/shared/components/MemoryData.hpp"
#include <cstddef>
#include <iostream> // Include the missing header
#include <fstream>   // For std::ifstream
#include <sstream>
#if defined(__APPLE__) || defined(__MACH__)
#include <mach/mach.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#endif

MemoryData::MemoryData() : totalMemory(0), usedMemory(0), freeMemory(0), swapMemory()
{
    collectData();
}

void MemoryData::collectData()
{
#if defined(__APPLE__)
    struct xsw_usage swapUsage;
    size_t size = sizeof(totalMemory);
    size_t swapSize = sizeof(swapUsage);

    if (sysctlbyname("vm.swapusage", &swapUsage, &swapSize, NULL, 0) < 0) {
        std::cout << "error feching swapUsage" << std::endl;
    }
    swapMemory = swapUsage;
    sysctlbyname("hw.memsize", &totalMemory, &size, NULL, 0);

    vm_size_t pageSize = swapUsage.xsu_pagesize;
    mach_port_t machPort = mach_host_self(); // machPort connect host with mach
    vm_statistics64_data_t vmStats;          // vmStas strucutre of data of the kernel
    mach_msg_type_number_t count =
        sizeof(vmStats) /
        sizeof(natural_t); // cout of elemetns in the stats (natural t -> base data size of kernel)
    if (host_statistics64(machPort, HOST_VM_INFO, (host_info64_t) &vmStats, &count) ==
        KERN_SUCCESS) { // this allow us to get the hsot_vm_info ffrom mach kernel -> can be  useful
                        // for kernell part
        usedMemory =
            (vmStats.active_count + vmStats.inactive_count + vmStats.wire_count) * pageSize;
        freeMemory = vmStats.free_count * pageSize;
    }
    mach_port_deallocate(mach_task_self(), machPort);
#elif defined(__linux__)
    std::ifstream file("/proc/meminfo");
    std::string line;
    unsigned long memTotal = 0, memFree = 0, memAvailable = 0, swapTotal = 0, swapFree = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        unsigned long value;
        std::string unit;
        iss >> key >> value >> unit;

        if (key == "MemTotal:") {
            memTotal = value;
        } else if (key == "MemFree:") {
            memFree = value;
        } else if (key == "MemAvailable:") {
            memAvailable = value;
        } else if (key == "SwapTotal:") {
            swapTotal = value;
        } else if (key == "SwapFree:") {
            swapFree = value;
        }
    }

    totalMemory = memTotal;
    freeMemory = memFree;
    usedMemory = memTotal - memFree;
    swapMemory.xsu_total = swapTotal;
    swapMemory.xsu_avail = swapFree;
    swapMemory.xsu_used = swapTotal - swapFree;
#elif defined(_WIN32)
    std::cerr << "buy a mac" << std::endl;
    auto var = nullptr;
    *var = 1;
#endif
}

unsigned long MemoryData::getTotalMemory() const { return totalMemory; }

unsigned long MemoryData::getUsedMemory() const { return usedMemory; }

unsigned long MemoryData::getFreeMemory() const { return freeMemory; }

float MemoryData::getMemoryUsagePercentage() const
{
    return totalMemory > 0 ? (static_cast<float>(usedMemory) / totalMemory) * 100.0f : 0.0f;
}

MemoryData::xsw_usage MemoryData::getSwapMemory() const { return swapMemory; }

// TEST MAIN TO SE BASIC DATA FO MEMORY (RAM);
// int main()
// {
//     MemoryData* memData = new MemoryData();
//     memData->collectData();
//     std::cout << "totalMemory: " << memData->getTotalMemory() << std::endl; // 16 GB ~=
//      std::cout << "freeMemory: " << memData->getFreeMemory()
//               << std::endl; // 116MB ~= 121864192 bytes
//     std::cout << "Memory usage percentage: " << memData->getMemoryUsagePercentage() << std::endl;
//     std::cout << "Memory swap memory: " << memData->getSwapMemory().xsu_total << std::endl;
//     std::cout << "Memory used memory: " << memData->getUsedMemory()
//               << std::endl; // 8.77 GB ~= 9414213632
// }
