#ifndef _KUKO_LOGGER
#define _KUKO_LOGGER

#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

namespace Utilities
{

class Logger
{
    public:
    static void Setup( bool loud = false );
    static void Setup( int logLevel, const std::string& filter );
    static void Cleanup();
    static void SetLogLevel( int val );
    static void SetFilterWord( const std::string& filter );

    static void Out( const std::string& message, const std::string& location = "", const std::string& category = "", bool condition = true, int level = 0 );
    static void OutValue( const std::string& label, int value, const std::string& location = "", const std::string& category = "", bool condition = true, int level = 0 );
    static void OutValue( const std::string& label, const std::string& value, const std::string& location = "", const std::string& category = "", bool condition = true, int level = 0 );
    static void OutHighlight( const std::string& message, const std::string& location = "", int color = 1);
    static void Error( const std::string& message, const std::string& location = "" );
    static void Debug( const std::string& message, const std::string& location = "" );

    static double GetTimestamp();
    static std::string GetFormattedTimestamp();

    static void Push( std::string stateName );
    static void Pop();
    static std::string GetStackString();

    private:
    static std::ofstream m_file;
    static time_t m_startTime;
    static time_t m_lastTimestamp;
    static int m_logLevel;
    static std::string m_categoryFilter;
    static int m_rowCount;
    static bool m_isLoud;
    static std::vector<std::string> m_functionStack;
};

}

#endif
