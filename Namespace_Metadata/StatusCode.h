#ifndef _STATUSCODE
#define _STATUSCODE

#include <string>

namespace Metadata
{

struct StatusCode
{
    StatusCode() { }
    StatusCode( int c, std::string n ) { code = c; name = n; }
    int code;
    std::string name;
    std::string message;
};

}

#endif
