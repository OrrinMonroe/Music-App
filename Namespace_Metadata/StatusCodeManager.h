#ifndef _STATUSCODEMANAGER
#define _STATUSCODEMANAGER

#include "StatusCode.h"

#include <map>

namespace Metadata
{

class StatusCodeManager
{
public:
    static void Setup();
    static StatusCode GetCode( int code );

private:
    static std::map<int, StatusCode> s_statusCodes;
};

}

#endif
