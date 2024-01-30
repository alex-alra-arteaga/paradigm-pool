#include <string>

#ifndef INFO_HPP_
#define INFO_HPP_

class Info {
  public:
    Info() = default;
    ~Info() = default;
    std::string getUsername() const;
    std::string getHostname() const;
    std::string getOS() const;
    std::string getKernel() const;
};

#endif /* !INFO_HPP_ */
