#include "Logger.h"
#include "Helper.h"

namespace Utilities
{

std::ofstream Logger::m_file;
time_t Logger::m_startTime;
time_t Logger::m_lastTimestamp;
int Logger::m_logLevel;
std::string Logger::m_categoryFilter;
int Logger::m_rowCount;
bool Logger::m_isLoud;
std::vector<std::string> Logger::m_functionStack;

/*
    m_logLevel:
    * 0: Mundane
*/

void Logger::Setup( bool isLoud )
{
    m_rowCount = 0;
    m_logLevel = 0;
    m_file.open( "log.html" );
    m_startTime = GetTimestamp();
    m_lastTimestamp = m_startTime;
    m_isLoud = isLoud;

    m_file << "<html><head><title>LOG " << __DATE__ << "</title></head><body>" << std::endl;
    m_file << "<style>" << std::endl;
    m_file << "table { font-family: sans-serif; width: 100%; }" << std::endl;
    m_file << "tr.highlight { background: #ff7c7c; } " << std::endl;
    m_file << "tr.highlight-1 { background: #ffb67c; } " << std::endl;
    m_file << "tr.highlight-2 { background: #ffef7c; } " << std::endl;
    m_file << "tr.highlight-3 { background: #aeff7c; } " << std::endl;
    m_file << "tr.highlight-4 { background: #7cffdc; } " << std::endl;
    m_file << "tr.highlight-5 { background: #7cbbff; } " << std::endl;
    m_file << "tr.highlight-6 { background: #947cff; } " << std::endl;
    m_file << "tr.highlight-7 { background: #dd7cff; } " << std::endl;
    m_file << "tr.highlight-8 { background: #ff7cb1; } " << std::endl;
    m_file << "tr.highlight-9 { background: #d7d7d7; } " << std::endl;
    m_file << "tr.highlight-10 { background: #ffcbcb; } " << std::endl;

    m_file << "td { border-bottom: solid 1px #CCCCCC; } " << std::endl;
    m_file << "table .time { padding-right: 25px; }" << std::endl;
    m_file << "table .location { padding-right: 25px; }" << std::endl;
    m_file << "table td.time { font-size: 14px; }" << std::endl;
    m_file << "table td.location { font-size: 14px; }" << std::endl;
    m_file << "table td.message { font-size: 14px; }" << std::endl;
    m_file << "table td.stack { font-size: 9px; }" << std::endl;
    m_file << "table .odd { background: #DDDDDD; }" << std::endl;
    m_file << "table .error { background: #FFA5A5; }" << std::endl;
    m_file << "</style>" << std::endl;
    m_file << "<table>" << std::endl;
    m_file << "<tr>"
        << "<td class='time'><strong>TIME</strong></td>"
        << "<td class='location'><strong>LOCATION</strong></td>"
        << "<td class='message'><strong>MESSAGE</strong></td>"
        << "<td class='stack'><strong>STACK</strong></td>"
        << "<td class='misc'><strong>MISC</strong></td>"
        << "</tr>" << std::endl;
    Out( "Logging Begins", "Logger::Setup" );
}

void Logger::Setup( int logLevel, const std::string& filter )
{
    Setup();
    SetLogLevel( logLevel );
    SetFilterWord( filter );
}

void Logger::SetLogLevel( int val )
{
    m_logLevel = val;
}

void Logger::SetFilterWord( const std::string& filter )
{
    Out( "Setting filter to only display messages of category \"" + filter + "\"" );
    m_categoryFilter = filter;
}

void Logger::Cleanup()
{
    Out( "Logging Ends", "Logger::Cleanup" );
    m_file << "</table>" << std::endl;
    m_file << "</body></html>" << std::endl;
    m_file.close();
}

void Logger::OutHighlight( const std::string& message, const std::string& location, int color /* = 1 */ )
{
    if ( m_isLoud )
    {
        std::cout << GetFormattedTimestamp();
        if ( location != "" ) { std::cout << " @ " << location; }
        std::cout << std::endl << "  " << message << std::endl << std::endl;
    }

    std::string loc = location;
    if ( loc == "" ) { loc = "-"; }

    m_file << "<tr class='highlight-" << color << "'>"
        << "<td class='time'>" << GetFormattedTimestamp() << "</td>"
        << "<td class='location'>" << loc << "</td>"
        << "<td class='message'>" << message << "</td>"
        << "<td class='stack'>" << GetStackString() << "</td>"
        << "</tr>" << std::endl;

    m_rowCount++;
}

void Logger::Out( const std::string& message, const std::string& location /* = "" */, const std::string& category /* = "" */, bool condition /* = true */, int level /* = 0 */ )
{
    if ( m_categoryFilter.size() > 0 )
    {
        // Filter is active

        if ( category.size() == 0
            || m_categoryFilter.find( category ) == std::string::npos )
        {
            return;
        }
    }

    if ( level < m_logLevel )
    {
        return;
    }

    if ( condition )
    {
        if ( m_isLoud )
        {
            std::cout << GetFormattedTimestamp();
            if ( location != "" ) { std::cout << " @ " << location; }
            std::cout << std::endl << "  " << message << std::endl << std::endl;
        }

        std::string loc = location;
        if ( loc == "" ) { loc = "-"; }

        std::string rowClass = ( m_rowCount % 2 == 0 ) ? "" : "odd";

        m_file << "<tr class='" + rowClass + "'>"
            << "<td class='time'>" << GetFormattedTimestamp() << "</td>"
            << "<td class='location'>" << loc << "</td>"
            << "<td class='message'>" << message << "</td>"
            << "<td class='stack'>" << GetStackString() << "</td>"
            << "</tr>" << std::endl;

        m_rowCount++;
    }
}

void Logger::OutValue( const std::string& label, int value, const std::string& location, const std::string& category, bool condition, int level )
{
    Out( label + ": " + Helper::ToString( value ), location, category, condition, level );
}

void Logger::OutValue( const std::string& label, const std::string& value, const std::string& location, const std::string& category, bool condition, int level )
{
    Out( label + ": " + value, location, category, condition, level );
}

void Logger::Error( const std::string& message, const std::string& location /* = "" */ )
{
    std::cerr   << "** " << GetTimestamp() << "\t" << message;
    if ( location != "" ) { std::cerr << " @ " << location; }
    std::cerr << "\t LINE " << __LINE__ << " FILE " << __FILE__ ;
    std::cerr << std::endl;

    std::string loc = location;
    if ( loc == "" ) { loc = "-"; }

    m_file << "<tr class='error'>"
        << "<td class='time'>" << GetFormattedTimestamp() << "</td>"
        << "<td class='location'>" << loc << "</td>"
        << "<td class='message'>" << message << "</td>"
        << "<td class='stack'>" << GetStackString() << "</td>"
        << "</tr>" << std::endl;
}

void Logger::Debug( const std::string& message, const std::string& location )
{
    std::cerr   << "** " << Helper::GetTime() << "\t" << message;
    if ( location != "" )
    {
        std::cerr << " @ " << location;
    }
    std::cerr << std::endl;

    std::string loc = location;
    if ( loc == "" )
    {
        loc = "-";
    }

    m_file << "<tr class='debug'>"
           << "<td class='time'>" << Helper::GetTime() << "</td>"
           << "<td class='location'>" << loc << "</td>"
           << "<td class='message'>" << message << "</td>"
            << "<td class='stack'>" << GetStackString() << "</td>"
           << "<td class='misc'>DEBUG</td>"
           << "</tr>" << std::endl;
}

std::string Logger::GetFormattedTimestamp()
{

    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        time_t timestamp = GetTimestamp();
        struct tm timeinfo;
        char buffer[80];
        time( &timestamp );
        localtime_s ( &timeinfo, &timestamp );
        // http://www.cplusplus.com/reference/ctime/strftime/
        strftime( buffer, 80, "%H:%M:%S", &timeinfo );

        std::string str( buffer );
        return str;
    #else
            time_t timestamp = GetTimestamp();
        struct tm* timeinfo;
        char buffer[80];
        time( &timestamp );
        timeinfo = localtime ( &timestamp );
        // http://www.cplusplus.com/reference/ctime/strftime/
        strftime( buffer, 80, "%H:%M:%S", timeinfo );

        std::string str( buffer );
        return str;
    #endif

}

double Logger::GetTimestamp()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t( now );
}

void Logger::Push( std::string stateName )
{
    m_functionStack.push_back( stateName );
}

void Logger::Pop()
{
    m_functionStack.pop_back();
}

std::string Logger::GetStackString()
{
    std::string str = "";
    for ( size_t i = 0; i < m_functionStack.size(); i++ )
    {
        str += Helper::ToString( i ) + ". " + m_functionStack[i] + "<br>";
    }
    return str;
}

}
