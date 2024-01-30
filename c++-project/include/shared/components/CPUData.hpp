#ifndef CPUDATA_H
#define CPUDATA_H

#include <string>
#include <vector>

class CPUData
{
  public:
    CPUData();
    void collectData();

    // getters
    std::string getModel() const;
    double getFrequency() const;
    int getCoreCount() const;
    std::vector<float> collectCpuUsagePerCore() const;
    float getAvgFrequency();

    // linx
    std::vector<float> collectCpuUsagePerCoreLinux() const;
    std::string getCPUModelFromLscpu() const;
    float calculateCurrentCpuAvgUsage() const;

    // auxiliars for avFrequency
    unsigned long long _previousTotalTicks;
    unsigned long long _previousIdleTicks;

  private:
    float avgCalculatorHelper(unsigned long long idleTicks, unsigned long long totalTicks);
    float calculateCpuAvg();


    // linux

    std::string model;
    double frequency;
    int coreCount;
};

#endif
