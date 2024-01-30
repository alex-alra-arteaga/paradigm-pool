#include "../../include/console/Battery.hpp"

#ifdef __APPLE__
    #include <IOKit/ps/IOPSKeys.h>
    #include <IOKit/ps/IOPowerSources.h>
#endif

bool Battery::isCharging() const
{
#ifdef __APPLE__
    CFDictionaryRef pSource = NULL;
    CFStringRef psState;
    int i;
    bool retval = false;

    CFTypeRef blob = IOPSCopyPowerSourcesInfo();
    CFArrayRef list = IOPSCopyPowerSourcesList(blob);

    for (i = 0; i < CFArrayGetCount(list); i++) {
        pSource = IOPSGetPowerSourceDescription(
            blob, CFArrayGetValueAtIndex(list, i));
        if (!pSource)
            break;
        psState = (CFStringRef) CFDictionaryGetValue(
            pSource, CFSTR(kIOPSPowerSourceStateKey));
        if (!CFStringCompare(psState, CFSTR(kIOPSBatteryPowerValue), 0)) {
            retval = true;
        }
    }

    CFRelease(blob);
    CFRelease(list);
    return !retval;
#endif
    /* Not implemented */
    return false;
}

int Battery::getPercentage() const
{
#ifdef __APPLE__
    CFDictionaryRef pSource = NULL;
    CFStringRef psState;
    int i;
    bool retval = false;

    CFTypeRef blob = IOPSCopyPowerSourcesInfo();
    CFArrayRef list = IOPSCopyPowerSourcesList(blob);

    for (i = 0; i < CFArrayGetCount(list); i++) {
        pSource = IOPSGetPowerSourceDescription(
            blob, CFArrayGetValueAtIndex(list, i));
        if (!pSource)
            break;
        psState = (CFStringRef) CFDictionaryGetValue(
            pSource, CFSTR(kIOPSPowerSourceStateKey));

        CFNumberRef currentCapacity = (CFNumberRef) CFDictionaryGetValue(
            pSource, CFSTR(kIOPSCurrentCapacityKey));
        CFNumberRef maxCapacity = (CFNumberRef) CFDictionaryGetValue(
            pSource, CFSTR(kIOPSMaxCapacityKey));

        int cur, max;
        CFNumberGetValue(currentCapacity, kCFNumberSInt32Type, &cur);
        CFNumberGetValue(maxCapacity, kCFNumberSInt32Type, &max);

        return (cur * 100) / max;
    }

    CFRelease(blob);
    CFRelease(list);
    return !retval;
#endif
    /* Not implemented */
    return 42;
}
