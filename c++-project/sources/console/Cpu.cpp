#include "../../include/console/Cpu.hpp"
#include <vector>

float CPU::GetCPULoad()
{
#if defined(__APPLE__) || defined(__MACH__)

    host_cpu_load_info_data_t cpuinfo;
    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
    if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO,
            (host_info_t) &cpuinfo, &count)
        == KERN_SUCCESS) {
        unsigned long long totalTicks = 0;
        for (int i = 0; i < CPU_STATE_MAX; i++)
            totalTicks += cpuinfo.cpu_ticks[i];
        return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
    } else
        return -1.0f;
#endif
    return 0.0f;
}

float CPU::CalculateCPULoad(
    unsigned long long idleTicks, unsigned long long totalTicks)
{
    unsigned long long totalTicksSinceLastTime =
        totalTicks - _previousTotalTicks;
    unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;
    float ret = 1.0f
        - ((totalTicksSinceLastTime > 0)
                ? ((float) idleTicksSinceLastTime) / totalTicksSinceLastTime
                : 0);
    _previousTotalTicks = totalTicks;
    _previousIdleTicks = idleTicks;
    return ret;
}

std::vector<float> CPU::collectCpuUsagePerCore() const
{
#if defined(__APPLE__) || defined(__MACH__)

    natural_t numCPUs;
    processor_info_array_t cpuInfo;
    mach_msg_type_number_t numCpuInfo;
    std::vector<float> cpuUsages;

    // the host_processor_info -> get infor form the kernel we get teh numCPU
    kern_return_t err = host_processor_info(mach_host_self(),
        PROCESSOR_CPU_LOAD_INFO, &numCPUs, &cpuInfo, &numCpuInfo);
    if (err == KERN_SUCCESS) {
        processor_cpu_load_info_data_t *cpuLoadInfo =
            reinterpret_cast<processor_cpu_load_info_data_t *>(cpuInfo);

        // loop throgh all the cores and coutting all the ticks of that cpu
        // then after tht we get the idleTicks (the now ticks) -> caulate the
        // usage total - idle
        for (natural_t i = 0; i < numCPUs; ++i) {
            unsigned long totalTicks = 0;
            // CPU have different states -> sum all the ticks form the diffetn
            // statates that the cpu has USER, SYSTEM, IDLE, NICE -> ??
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
#endif
    return std::vector<float>();
}
