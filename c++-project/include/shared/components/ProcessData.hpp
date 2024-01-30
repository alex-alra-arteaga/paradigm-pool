#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <vector>

class ProcessData
{
  public:
    ProcessData() = default;
    std::string getProcess(int num_of_process);
    private:
    std::string execCommand(const char* cmd);
};

#endif
