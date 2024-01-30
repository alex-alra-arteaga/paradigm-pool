#include <string>
#include <vector>

#ifndef PROCESS_HPP_
    #define PROCESS_HPP_

class Process {
  public:
    Process() = default;
    ~Process() = default;
    std::vector<std::string> getProcess(int num_of_process);
    std::vector<std::string> execCommand(const char* cmd);
};

#endif /* !PROCESS_HPP_ */
