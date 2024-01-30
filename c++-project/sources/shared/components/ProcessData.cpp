#include "../../../include/shared/components/ProcessData.hpp"
#include <array>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <memory>
#include <sstream> // Include the necessary header file
#include <string>
#if defined(__APPLE__) || defined(__MACH__)
#include <sys/sysctl.h>
#endif
#include <sys/types.h>
#include <vector>

#include <string>

std::string ProcessData::getProcess(int num_of_process)
{
    std::string command = "ps -axo pid,comm,%cpu,rss | head -n 1; ps -axo pid,comm,%cpu,rss | tail -n +2 | sort -rnk3 | head -n " + std::to_string(num_of_process);
    return execCommand(command.c_str());
}


std::string ProcessData::execCommand(const char* cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    //  fgets reads form the pipe (FILE pointer opend by popen), then read up to bufer.size() tile
    //  this is not null we keep reading
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

// int main()
// {
//     ProcessData *data = new ProcessData();

//     std::cout << data->getProcess(10) << std::endl;
// }
