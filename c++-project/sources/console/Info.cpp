#include "../../include/console/Info.hpp"
#include <string>
#include <unistd.h>
#include "infoware/system.hpp"

#ifdef __APPLE__
    #include <CoreFoundation/CoreFoundation.h>
    #include <CoreServices/CoreServices.h>
    #include <sys/utsname.h>
#endif

std::string Info::getUsername() const
{
#ifdef __APPLE__
    return std::string(getenv("USER"));
#endif
    return "Not implemented";
}

std::string Info::getHostname() const
{
#ifdef __APPLE__
    char hostname[1024];
    gethostname(hostname, 1024);
    return std::string(hostname);
#endif
    return "Not implemented";
}

std::string Info::getOS() const
{
#if defined(__APPLE__) || defined(__MACH__)
    struct utsname uts;
    uname(&uts);
    return std::string(uts.sysname);
#endif
}

std::string Info::getKernel() const
{
#ifdef __APPLE__
    return iware::system::OS_info().full_name;
#endif
    return "Not implemented";
}
