#include <vector>
#if defined(__APPLE__) || defined(__MACH__)
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>
#endif

#ifndef CPU_HPP_
    #define CPU_HPP_

class CPU {
  private:
    unsigned long long _previousTotalTicks = 0;
    unsigned long long _previousIdleTicks = 0;

  public:
    CPU() = default;
    ~CPU() = default;
    float CalculateCPULoad(unsigned long long, unsigned long long);
    float GetCPULoad();
    std::vector<float> collectCpuUsagePerCore() const;
};

#endif /* !CPU_HPP_ */
