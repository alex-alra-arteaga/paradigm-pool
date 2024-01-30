#ifndef MEMORYDATA_H
#define MEMORYDATA_H

#include <stdbool.h>
#include <string>

class MemoryData
{
  public:
    MemoryData();
    void collectData();

    struct xsw_usage
    {
        uint64_t xsu_total; // total swap size
        uint64_t xsu_avail; // available swap size
        uint64_t xsu_used;  // used swap size
        uint32_t xsu_pagesize;
        bool xsu_encrypted; // is encrypted
    };

    unsigned long getTotalMemory() const;
    unsigned long getUsedMemory() const;
    unsigned long getFreeMemory() const;

    float getMemoryUsagePercentage() const;
    xsw_usage getSwapMemory() const;
    // returned struct by -> vm.swapusage: total = 2048.00M  used = 1452.38M  free = 595.62M
    // (encrypted)

  private:
    unsigned long totalMemory;
    unsigned long usedMemory;
    unsigned long freeMemory;
    xsw_usage swapMemory;
};

#endif // MEMORYDATA_H
