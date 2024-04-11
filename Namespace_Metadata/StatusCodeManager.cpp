#include "StatusCodeManager.h"

namespace Metadata
{

std::map<int, StatusCode> StatusCodeManager::s_statusCodes;

void StatusCodeManager::Setup()
{
    s_statusCodes[200] = StatusCode( 200, "OK" );
    s_statusCodes[400] = StatusCode( 400, "Bad Request" );
    s_statusCodes[401] = StatusCode( 401, "Unauthorized" );
    s_statusCodes[404] = StatusCode( 404, "Not Found" );
    s_statusCodes[500] = StatusCode( 500, "Internal Server Error" );
    s_statusCodes[501] = StatusCode( 501, "Not Implemented" );
}

StatusCode StatusCodeManager::GetCode( int code )
{
    if ( s_statusCodes.find( code ) == s_statusCodes.end() )
    {
        return s_statusCodes[500];
    }

    return s_statusCodes[code];
}

}
