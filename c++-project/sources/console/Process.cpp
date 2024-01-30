#include "../../include/console/Process.hpp"
#include <string>
#include <vector>
#include <array>
#include <memory>

std::vector<std::string> Process::getProcess(int num_of_process)
{
    std::string command =
        "ps -axo pid,comm,%cpu,rss,user | head -n 1; ps -axo "
        "pid,comm,%cpu,rss,user | tail "
        "-n +2 | sort -rnk3 | head -n "
        + std::to_string(num_of_process);
    return execCommand(command.c_str());
}

std::vector<std::string> Process::execCommand(const char *cmd)
{
    std::array<char, 128> buffer;
    std::vector<std::string> result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result.push_back(buffer.data());
    }
    return result;
}
