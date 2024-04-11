#ifndef _HELPER_HPP
#define _HELPER_HPP

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

namespace Utilities
{

class Helper
{
    /***************************************************************/
    /* User input functions ****************************************/
    public:
    static int           GetIntInput();
    static float         GetFloatInput();
    static char          GetCharInput();
    static std::string   GetStringInput();
    static std::string   GetStringLine();
    static std::string   GetStringLine( std::string message );
    static int           GetIntInput( int min, int max );

    private:
    static bool     s_needCinIgnore;

    /***************************************************************/
    /* Menu functionality ******************************************/
    public:
    static void ClearScreen();
    static void Pause();
    static void Header( const std::string& header );
    static void SubHeader( const std::string& header );
    static void DrawHorizontalBar( int width, char symbol = '-' );
    static void ShowMenu( const std::vector<std::string>& options, bool vertical = true, bool startAtOne = true );
    static int  ShowMenuGetInt( const std::vector<std::string>& options, bool vertical = true, bool startAtOne = true );
    static std::string  ShowMenuGetString( const std::vector<std::string>& options, bool vertical = true, bool startAtOne = true );

    /***************************************************************/
    /* System info *************************************************/
    public:
    static void PrintPwd();
    static void Sleep( int milliseconds );
    static void DisplayDirectoryContents( std::string path );

    /***************************************************************/
    /* Conversion functionality ************************************/
    public:
    template <typename T>
    static std::string   ToString( const T& value );

    static int           StringToInt( const std::string& str );
    static float         StringToFloat( const std::string& str );
    static std::string   CurrencyToString( float currency );
    static std::string   ToUpper( const std::string& val );
    static std::string   ToLower( const std::string& val );
    static std::string   Trim( const std::string& val );
    static void          Test_Trim();

    /***************************************************************/
    /* String helpers **********************************************/
    public:
    static bool                     Contains( std::string haystack, std::string needle, bool caseSensitive = true );
    static int                      Find( std::string haystack, std::string needle );
    static std::string              Replace( std::string fulltext, std::string findme, std::string replacewith );
    static std::vector<std::string> Split( std::string str, std::string delim );
    static std::string              DisplayTrim( std::string str, int maxLength );

    // wstring/string conversion
    static std::string WStringToString( std::wstring text );
    static std::wstring StringToWString( std::string text );

    // For game stuff
    static std::string CoordinateToString( int x, int y );
    static std::string DimensionsToString( int width, int height );

    /***************************************************************/
    /* Array helpers ***********************************************/
    public:
    template <typename T>
    static void          ArrayOutput( T myArray[], int size, std::ofstream& out );
    template <typename T>
    static std::string   ArrayToString( T myArray[], int size );

    template <typename T>
    static void          VectorOutput( std::vector<T> myVector, std::ofstream& out );
    template <typename T>
    static std::string   VectorToString( std::vector<T> myVector );

    /***************************************************************/
    /* Timer functionality *****************************************/
    public:
    static void   ClockStart();
    static size_t GetElapsedSeconds();
    static size_t GetElapsedMilliseconds();

    private:
    static std::chrono::system_clock::time_point s_startTime;

    /***************************************************************/
    /* Random functionality ****************************************/
    public:
    static void SeedRandomNumberGenerator();
    static int  GetRandom( int min, int max );

    /***************************************************************/
    /* Math functionality ******************************************/
    public:
    static float  GetDistance( float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2, bool fromCenter );
    static float  GetDistance( float x1, float y1, float x2, float y2 );
    static float  DotProduct( float x1, float y1, float x2, float y2 );
    static float  Length( float x1, float y1 );
    static float  AngleBetweenTwoPointsRadians( float x1, float y1, float x2, float y2 );
    static float  AngleBetweenTwoPointsDegrees( float x1, float y1, float x2, float y2 );
    static bool   BoundingBoxCollision( float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2 );
    static bool   PointInBoxCollision( float x1, float y1, float x2, float y2, float w2, float h2 );

    /***************************************************************/
    /* Additional functionality ************************************/
    static std::string GetTime();
};


template <typename T>
std::string Helper::ToString( const T& value )
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}


template <typename T>
void Helper::ArrayOutput( T myArray[], int size, std::ofstream& out )
{
    for ( int i = 0; i < size; i++ )
    {
        if ( i != 0 ) { std::cout << ", "; }
        out << myArray[i];
    }
    out << std::endl;
}

template <typename T>
std::string Helper::ArrayToString( T myArray[], int size )
{
    std::string text = "";

    for ( int i = 0; i < size; i++ )
    {
        if ( i != 0 ) { text += ", "; }
        text += ToString( myArray[i] );
    }

    return text;
}

template <typename T>
void     Helper::VectorOutput( std::vector<T> myVector, std::ofstream& out )
{
    for ( size_t i = 0; i < myVector.size(); i++ )
    {
        if ( i != 0 ) { std::cout << ", "; }
        out << myVector[i];
    }
    out << std::endl;
}

template <typename T>
std::string   Helper::VectorToString( std::vector<T> myVector )
{
    std::string text = "";

    for ( size_t i = 0; i < myVector.size(); i++ )
    {
        if ( i != 0 ) { text += ", "; }
        text += ToString( myVector[i] );
    }

    return text;
}

}

#endif
