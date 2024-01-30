#ifndef NETWORKDATA_H
#define NETWORKDATA_H

#include <string>
#include <vector>

class NetworkData
{

  public:
    NetworkData();
    struct NetworkInterfaceData
    {
        std::string name;
        unsigned long long rxBytes; // Ibyts -> bytes received RX
        unsigned long long txBytes; // Obytes -> bytes transmmited TX
    };
    void collectData();
    unsigned long long getRX() {return RX;};
    unsigned long long getTX() {return TX;};
    std::vector<NetworkInterfaceData> getNetworks() {return networks;};
    std::vector<std::string> execCommand(const char* cmd); // execute a comand and return the resutl
  private:
    std::vector<NetworkInterfaceData> networks;
    unsigned long long RX;
    unsigned long long TX;
};

#endif // NETWORKDATA_H
