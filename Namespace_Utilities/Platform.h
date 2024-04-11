// Chalo Engine, Moosader 2019-2020, https://gitlab.com/RachelWilShaSingh/chalo-engine

#ifndef PLATFORM_SPECIFIC_HPP
#define PLATFORM_SPECIFIC_HPP

#include <string>

namespace Utilities
{

enum OperatingSystem { UNKNOWN, WINDOWS32, WINDOWS64, APPLE, LINUX, UNIX, IOS, ANDROID };

class Platform
{
public:
    static OperatingSystem GetOperatingSystem();
    static std::string GetOperatingSystemName( OperatingSystem system );
    static void OpenUrl( const std::string& url );
};

}

#endif
