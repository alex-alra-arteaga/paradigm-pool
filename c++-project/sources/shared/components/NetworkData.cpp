#include "../../../include/shared/components/NetworkData.hpp"
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
#include <unordered_map>
#include <sys/types.h>
#include <vector>

NetworkData::NetworkData() : RX(0), TX(0), networks() { collectData(); }

std::vector<std::string> NetworkData::execCommand(const char* cmd)
{
    std::array<char, 128> buffer;
    std::vector<std::string> result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    //  fgets reads form the pipe (FILE pointer opend by popen), then read up to bufer.size() tile
    //  this is not null we keep reading
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result.push_back(buffer.data());
    }
    return result;
}

void NetworkData::collectData()
{
    std::vector<std::string> result = execCommand("netstat -ib");
    std::unordered_map<std::string, bool> networkData;

    for (size_t i = 1; i < result.size(); i++) {
        char* cstr = new char[result[i].size() + 1];
        std::strcpy(cstr, result[i].c_str());
        std::unique_ptr<NetworkInterfaceData> currNet(new NetworkInterfaceData());

        std::vector<std::string> tokens;
        char* token = std::strtok(cstr, " ");

        while (token != nullptr) {
            tokens.push_back(token);
            token = std::strtok(nullptr, " ");
        }

        if (tokens.size() >= 10) {
            const char* IbytesStr = tokens[6].c_str();
            const char* ObytesStr = tokens[9].c_str();
            unsigned long long Ibytes = std::strtoull(IbytesStr, nullptr, 10);
            unsigned long long Obytes = std::strtoull(ObytesStr, nullptr, 10);

            currNet->name = tokens[0];
            currNet->rxBytes = Ibytes;
            currNet->txBytes = Obytes;

            if (networkData.find(currNet->name) == networkData.end()) {
                TX += Ibytes;
                RX += Obytes;
                networkData[tokens[0]] = true;
            }

            networks.push_back(*currNet);
        }

        delete[] cstr;
    }
}

// MAIN TO TEST NETWORKDATA

// int main() {
//     const double bytesToMB = 1024 * 1024;
//     std::unique_ptr<NetworkData> network(new NetworkData());

//     double rxMB = static_cast<double>(network->getRX()) / bytesToMB;
//     double txMB = static_cast<double>(network->getTX()) / bytesToMB;

//     if (!network->getNetworks().empty()) {
//         std::cout << "Total RX: " << rxMB << " MB" << std::endl;
//         std::cout << "Total TX: " << txMB << " MB" << std::endl;
//         std::cout << network->getNetworks().front().name << std::endl;
//     } else {
//         std::cerr << "No network data available." << std::endl;
//     }
// }
