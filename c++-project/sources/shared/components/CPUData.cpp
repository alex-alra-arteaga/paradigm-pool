#include "../../../include/shared/components/CPUData.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#if defined(__APPLE__) || defined(__MACH__)
    #include <mach/mach.h>
    #include <mach/mach_error.h>
    #include <mach/mach_host.h>
    #include <mach/mach_init.h>
    #include <mach/vm_map.h>
    #include <sys/sysctl.h>
    #include <sys/types.h>
#elif defined(__linux__)
    // Linux-specific headers here
#endif

#if defined(__APPLE__)
std::vector<float> CPUData::collectCpuUsagePerCore() const
{
    natural_t numCPUs;
    processor_info_array_t cpuInfo;
    mach_msg_type_number_t numCpuInfo;
    std::vector<float> cpuUsages;

    // the host_processor_info -> get infor form the kernel we get teh numCPU
    kern_return_t err = host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &numCPUs,
                                            &cpuInfo, &numCpuInfo);
    if (err == KERN_SUCCESS) {
        processor_cpu_load_info_data_t* cpuLoadInfo =
            reinterpret_cast<processor_cpu_load_info_data_t*>(cpuInfo);

        // loop throgh all the cores and coutting all the ticks of that cpu
        // then after tht we get the idleTicks (the now ticks) -> caulate the usage total - idle
        for (natural_t i = 0; i < numCPUs; ++i) {
            unsigned long totalTicks = 0;
            // CPU have different states -> sum all the ticks form the diffetn statates that the cpu
            // has USER, SYSTEM, IDLE, NICE -> ??
            for (int j = 0; j < CPU_STATE_MAX; j++) {
                totalTicks += cpuLoadInfo[i].cpu_ticks[j];
            }
            unsigned long idleTicks = cpuLoadInfo[i].cpu_ticks[CPU_STATE_IDLE];
            float cpuUsage = 100.0f * (totalTicks - idleTicks) / totalTicks;
            // usage of that cpu -> to the vector. (the percentage direclty)
            // Active Ticks (Total Ticks - Idle Ticks):
            cpuUsages.push_back(cpuUsage);
        }
        // deallocate.
        size_t cpuInfoSize = sizeof(processor_cpu_load_info_data_t) * numCPUs;
        vm_deallocate(mach_task_self(), (vm_address_t) cpuInfo, cpuInfoSize);
    }
    return cpuUsages;
}

std::string CPUData::getCPUModelFromLscpu() const {
    throw std::runtime_error("Not implemented");
}

float CPUData::calculateCurrentCpuAvgUsage() const {
    throw std::runtime_error("Not implemented");
}

#elif defined(__linux__)

std::vector<float> CPUData::collectCpuUsagePerCoreLinux() const {
    std::vector<float> cpuUsages;
    std::ifstream file("/proc/stat");
    std::string line;

    while (std::getline(file, line)) {
        if (line.compare(0, 3, "cpu") == 0 && line[3] != ' ') {
            std::istringstream ss(line);

            std::string cpuLabel;
            long user, nice, system, idle;
            ss >> cpuLabel >> user >> nice >> system >> idle;

            long total = user + nice + system + idle;
            long active = total - idle;
            float cpuUsage = 100.0f * active / total;

            cpuUsages.push_back(cpuUsage * 100);
        }
    }

    return cpuUsages;
}

std::string CPUData::getCPUModelFromLscpu() const {
    std::string model;
    FILE* pipe = popen("lscpu | grep 'Model name' | awk -F': ' '{print $2}'", "r");
    if (!pipe) return "";

    char buffer[128];
    if (fgets(buffer, 128, pipe) != NULL) {
        model = buffer;
    }
    pclose(pipe);
    return model;
}

float CPUData::calculateCurrentCpuAvgUsage() const {
    std::ifstream file("/proc/stat");
    std::string line;
    std::getline(file, line);
    std::istringstream iss(line);

    std::string cpu;
    long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    iss >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;

    long totalIdle = idle + iowait;
    long totalActive = user + nice + system + irq + softirq + steal;
    long total = totalIdle + totalActive;

    // Calculate average CPU usage since the system started (maybe need to put 10000 to scale okay)
    return total > 0 ? (static_cast<float>(totalActive) / total) * 10000.0f : 0.0f;
}

#endif

CPUData::CPUData() : frequency(0.0), coreCount(0) { collectData(); }

std::string CPUData::getModel() const { return model; }

double CPUData::getFrequency() const { return frequency; }

int CPUData::getCoreCount() const { return coreCount; }

void CPUData::collectData()
{
#if defined(__APPLE__)
    char buffer[128];
    size_t bufferlen = 128;
    int coreCountInt;
    uint64_t freqHz;

    sysctlbyname("machdep.cpu.brand_string", &buffer, &bufferlen, NULL, 0);
    model = std::string(buffer);

    bufferlen = sizeof(freqHz);
    if (sysctlbyname("hw.cpufrequency", &freqHz, &bufferlen, NULL, 0) == 0) {
        frequency = static_cast<double>(freqHz) / 1e6; // Convert from Hz to MHz
    }

    bufferlen = sizeof(coreCountInt);
    sysctlbyname("hw.ncpu", &coreCountInt, &bufferlen, NULL, 0);
    coreCount = static_cast<int>(coreCountInt);
#elif defined(__linux__)
    std::ifstream cpuInfoFile("/proc/cpuinfo");
    std::string line;
    model = "";
    coreCount = 0;
    while (std::getline(cpuInfoFile, line)) {
        if (line.substr(0, 9) == "model name") {
            if (model.empty()) {
                size_t pos = line.find(": ");
                if (pos != std::string::npos) {
                    model = line.substr(pos + 2);
                }
            }
        } else if (line.substr(0, 9) == "processor") {
            coreCount++;
        }
    }
#elif defined(_WIN32)
    std::cerr << "skill issues" << std::endl;
    auto var = nullptr;
    *var = 1;
#endif
}

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.
#if defined(__APPLE__)
float CPUData::calculateCpuAvg()
{
    host_cpu_load_info_data_t cpuinfo;
    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
    if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t) &cpuinfo, &count) ==
        KERN_SUCCESS) {
        unsigned long long totalTicks = 0;
        for (int i = 0; i < CPU_STATE_MAX; i++)
            totalTicks += cpuinfo.cpu_ticks[i];
        return avgCalculatorHelper(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
    } else
        return -1.0f;
}

float CPUData::avgCalculatorHelper(unsigned long long idleTicks, unsigned long long totalTicks)
{
    unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
    unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;
    float ret = 1.0f - ((totalTicksSinceLastTime > 0)
                            ? ((float) idleTicksSinceLastTime) / totalTicksSinceLastTime
                            : 0);
    _previousTotalTicks = totalTicks;
    _previousIdleTicks = idleTicks;
    return ret;
}
float CPUData::getAvgFrequency() { return this->calculateCpuAvg() * 100; }

#elif defined(__linux__)


#endif


// // // ! test main to see basic data printed out
// int main()
// {
//     CPUData* cpu = new CPUData();
//     std::cout << cpu->getModel() << std::endl;
//     std::cout << cpu->getCoreCount() << std::endl;
//     std::vector<float> cpuUsages = cpu->collectCpuUsagePerCoreLinux();
//    for (size_t i = 0; i < cpuUsages.size(); ++i) {
//         std::cout << "Core " << i + 1 << ": " << cpuUsages[i] << "%" << std::endl;
//    }
// }

// int main() {
//     CPUData* cpu = new CPUData();
//     float avgCpuUsage = cpu->calculateCurrentCpuAvgUsage();
//     std::cout << "Current Average CPU Usage: " << avgCpuUsage << "%" << std::endl;
//     return 0;
// }

// MAIN TO TEST CORE DATA + INIDVIDUAL CORES
// int main()
// {
//     CPUData cpu;
//     cpu.collectData();

//     std::cout << "Model: " << cpu.getModel() << std::endl;
//     std::cout << "Frequency: " << cpu.getFrequency() << " MHz" << std::endl;
//     std::cout << "Core Count: " << cpu.getCoreCount() << std::endl;

//     std::vector<float> cpuUsages = cpu.collectCpuUsagePerCore();
//     std::cout << "CPU Usage per Core:" << std::endl;
//     for (size_t i = 0; i < cpuUsages.size(); ++i) {
//         std::cout << "Core " << i + 1 << ": " << cpuUsages[i] << "%" << std::endl;
//     }

//     return 0;
// }
