#include "Helper.h"

#include <sstream> // For conversions
#include <locale>  // For wstring
#include <codecvt> // For wstring
#include <cmath>
#include <iomanip>

/***************************************************************/
/* User input functions ****************************************/
/***************************************************************/

namespace Utilities
{

bool Helper::s_needCinIgnore = false;

int Helper::GetIntInput()
{
    return StringToInt( GetStringInput() );
}

float Helper::GetFloatInput()
{
    return StringToFloat( GetStringInput() );
}

char Helper::GetCharInput()
{
    std::string str = GetStringInput();
    return str[0];
}

std::string Helper::GetStringInput()
{
    std::cout << " >> ";
    s_needCinIgnore = true;
    std::string strValue;
    std::cin >> strValue;
    return strValue;
}

std::string Helper::GetStringLine()
{
    if ( s_needCinIgnore )
    {
        std::cin.ignore();
    }

    s_needCinIgnore = false;
    std::string strValue;
    std::cout << " >> ";
    getline( std::cin, strValue );
    return strValue;
}

std::string Helper::GetStringLine( std::string message )
{
    std::cout << message << std::endl;

    return GetStringLine();
}

int Helper::GetIntInput( int min, int max )
{
    int input = GetIntInput();

    while ( input < min || input > max )
    {
        std::cout << "Invalid selection. Try again: " << std::endl;
        input = GetIntInput();
    }

    return input;
}


/***************************************************************/
/* Menu functionality ******************************************/
/***************************************************************/

void Helper::ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "cls" );
    #else
        system( "clear" );
    #endif
}

void Helper::Pause()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "pause" );
    #else
        std::cout << std::endl << " Press ENTER to continue..." << std::endl;
        std::cin.ignore();
        std::string a;
        getline( std::cin, a );
//        if ( s_needCinIgnore )
//        {
//            std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
//        }
//        else
//        {
//            std::cin.get();
//        }
    #endif
}

void Helper::Header( const std::string& header )
{
    DrawHorizontalBar( 80 );
    std::string head = "| " + header + " |";
    std::cout << " " << head << std::endl << " ";
    DrawHorizontalBar( head.size() );
    std::cout << std::endl;
}

void Helper::SubHeader( const std::string& header )
{
    std::cout << std::endl << std::string( 2, '-' ) << " " << header << " "
        << std::string( 80-4-header.size(), '-' ) << std::endl << std::endl;
}

void Helper::DrawHorizontalBar( int width, char symbol /*= '-'*/ )
{
    std::cout << std::string( width, symbol ) << std::endl;
}

void Helper::ShowMenu( const std::vector<std::string>& options, bool vertical /*= true*/, bool startAtOne /*= true*/ )
{
    std::cout << std::left;
    int colWidth = 80 / options.size();

    for ( size_t i = 0; i < options.size(); i++ )
    {
        int number = ( startAtOne ) ? i+1 : i;

        if ( vertical )
        {
            std::cout << " " << number << ".\t" << options[i] << std::endl;
        }
        else
        {
            std::cout << std::setw( colWidth ) << std::string( ToString( number ) + ". " + options[i] );
        }
    }
    if ( !vertical ) { std::cout << std::endl; }
    std::cout << std::endl;
}

int  Helper::ShowMenuGetInt( const std::vector<std::string>& options, bool vertical /*= true*/, bool startAtOne /*= true*/ )
{
    ShowMenu( options, vertical, startAtOne );
    int minVal = ( startAtOne ) ? 1 : 0;
    int maxVal = ( startAtOne ) ? options.size() : options.size() - 1;
    int choice = GetIntInput( minVal, maxVal );
    return choice;
}

std::string  Helper::ShowMenuGetString( const std::vector<std::string>& options, bool vertical, bool startAtOne )
{
    int choice = ShowMenuGetInt( options, vertical, startAtOne );
    if ( startAtOne ) { choice--; }
    return options[choice];
}


/***************************************************************/
/* System info *************************************************/
/***************************************************************/

void Helper::PrintPwd()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "echo %cd%" );
    #else
        system( "pwd" );
    #endif
}

void Helper::Sleep( int milliseconds )
{
    std::this_thread::sleep_for( std::chrono::milliseconds( milliseconds ) );
}

void Helper::DisplayDirectoryContents( std::string path )
{
    std::string command;

    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    command = "dir ";
    #else
    command = "ls ";
    #endif

    command += path;

    system( command.c_str() );
}


/***************************************************************/
/* Conversion functionality ************************************/
/***************************************************************/

int      Helper::StringToInt( const std::string& str )
{
    int value = 0;
    try
    {
        value = stoi( str );
    }
    catch( const std::invalid_argument& ex )
    {
        std::cout << "Cannot convert \"" << str << "\" to int!" << std::endl;
        return -1;
    }

    return value;
}

float    Helper::StringToFloat( const std::string& str )
{
    float value = 0;
    try
    {
        value = stof( str );
    }
    catch( const std::invalid_argument& ex )
    {
        std::cout << "Cannot convert \"" << str << "\" to float!" << std::endl;
        return -1;
    }

    return value;
}

std::string   Helper::CurrencyToString( float currency )
{
    std::stringstream ss;
    ss << "$" << std::fixed << std::setprecision(2) << currency;
    return ss.str();
}

std::string   Helper::ToUpper( const std::string& val )
{
    std::string str = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        str += toupper( val[i] );
    }
    return str;
}

std::string   Helper::ToLower( const std::string& val )
{
    std::string str = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        str += tolower( val[i] );
    }
    return str;
}

std::string   Helper::Trim( const std::string& val )
{
    int firstLetter = -1;
    int lastLetter = -1;
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        if ( firstLetter == -1 && val[i] != ' ' )
        {
            firstLetter = i;
        }

        if ( val[i] != ' ' )
        {
            lastLetter = i;
        }
    }

    int stringLength = lastLetter - firstLetter + 1;

    std::string trimmed = val.substr( firstLetter, stringLength );
    return trimmed;
}

void Helper::Test_Trim()
{
    {
        std::string input = "Nothing to trim";
        std::string expectedOutput = "Nothing to trim";
        std::string actualOutput = Helper::Trim( input );

        std::cout << "Test 1: \"" << input << "\"... ";
        if ( actualOutput != expectedOutput ) { std::cout << "FAIL" << std::endl; }
        else { std::cout << "PASS" << std::endl; }
        std::cout << "Expected output: \"" << expectedOutput << "\"" << std::endl;
        std::cout << "Actual output: \"" << actualOutput << "\"" << std::endl;
    }

    {
        std::string input = "  Space at the beginning";
        std::string expectedOutput = "Space at the beginning";
        std::string actualOutput = Helper::Trim( input );

        std::cout << "Test 2: \"" << input << "\"... ";
        if ( actualOutput != expectedOutput ) { std::cout << "FAIL" << std::endl; }
        else { std::cout << "PASS" << std::endl; }
        std::cout << "Expected output: \"" << expectedOutput << "\"" << std::endl;
        std::cout << "Actual output: \"" << actualOutput << "\"" << std::endl;
    }

    {
        std::string input = "Space at the end  ";
        std::string expectedOutput = "Space at the end";
        std::string actualOutput = Helper::Trim( input );

        std::cout << "Test 3: \"" << input << "\"... ";
        if ( actualOutput != expectedOutput ) { std::cout << "FAIL" << std::endl; }
        else { std::cout << "PASS" << std::endl; }
        std::cout << "Expected output: \"" << expectedOutput << "\"" << std::endl;
        std::cout << "Actual output: \"" << actualOutput << "\"" << std::endl;
    }

    {
        std::string input = "   Space on both ends   ";
        std::string expectedOutput = "Space on both ends";
        std::string actualOutput = Helper::Trim( input );

        std::cout << "Test 4: \"" << input << "\"... ";
        if ( actualOutput != expectedOutput ) { std::cout << "FAIL" << std::endl; }
        else { std::cout << "PASS" << std::endl; }
        std::cout << "Expected output: \"" << expectedOutput << "\"" << std::endl;
        std::cout << "Actual output: \"" << actualOutput << "\"" << std::endl;
    }
}


/***************************************************************/
/* String helpers **********************************************/
/***************************************************************/

bool     Helper::Contains( std::string haystack, std::string needle, bool caseSensitive /*= true*/ )
{
    std::string a = haystack;
    std::string b = needle;

    if ( !caseSensitive )
    {
        for ( unsigned int i = 0; i < a.size(); i++ )
        {
            a[i] = tolower( a[i] );
        }

        for ( unsigned int i = 0; i < b.size(); i++ )
        {
            b[i] = tolower( b[i] );
        }
    }

    return ( a.find( b ) != std::string::npos );
}

int      Helper::Find( std::string haystack, std::string needle )
{
    return haystack.find( needle );
}

std::string   Helper::Replace( std::string fulltext, std::string findme, std::string replacewith )
{
    std::string updated = fulltext;
    size_t index = updated.find( findme );

    while ( index != std::string::npos )
    {
        // Make the replacement
        updated = updated.replace( index, findme.size(), replacewith );

        // Look for the item again
        index = updated.find( findme );
    }

    return updated;
}

std::vector<std::string> Helper::Split( std::string str, std::string delim )
{
    std::vector<std::string> data;

    int begin = 0;
    int end = 0;

    while ( str.find( delim ) != std::string::npos )
    {
        end = str.find( delim );

        // Get substring up until delimiter
        int length = end - begin;
        std::string substring = str.substr( begin, length );
        data.push_back( substring );

        // Remove this chunk of string
        str = str.erase( begin, length+1 );
    }

    // Put last string in structure
    data.push_back( str );

    return data;
}

std::string Helper::DisplayTrim( std::string str, int maxLength )
{
    if ( str.size() < maxLength ) { return str; }
    return str.substr( 0, maxLength-3 ) + "...";
}

// From https://stackoverflow.com/questions/4804298/how-to-convert-wstring-into-string
std::string Helper::WStringToString( std::wstring text )
{
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;

    //use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
    std::string converted_str = converter.to_bytes( text );

    return converted_str;
}

// From https://stackoverflow.com/questions/2573834/c-convert-string-or-char-to-wstring-or-wchar-t
std::wstring Helper::StringToWString( std::string text )
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wide = converter.from_bytes( text );
    return wide;
}

std::string Helper::CoordinateToString( int x, int y )
{
    std::stringstream ss;
    ss << "(" << x << ", " << y << ")";
    return ss.str();
}

std::string Helper::DimensionsToString( int width, int height  )
{
    std::stringstream ss;
    ss << width << "x" << height;
    return ss.str();
}

/***************************************************************/
/* Timer functionality *****************************************/
/***************************************************************/

std::chrono::system_clock::time_point Helper::s_startTime;

void Helper::ClockStart()
{
    s_startTime = std::chrono::system_clock::now();
}

size_t Helper::GetElapsedSeconds()
{
    std::chrono::system_clock::time_point current_time = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>( current_time - s_startTime ).count();
}

size_t Helper::GetElapsedMilliseconds()
{
    std::chrono::system_clock::time_point current_time = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>( current_time - s_startTime ).count();
}


/***************************************************************/
/* Random functionality ****************************************/

void Helper::SeedRandomNumberGenerator()
{
    srand( time( NULL ) );
}

int  Helper::GetRandom( int min, int max )
{
    return rand() % ( max - min + 1 ) + min;
}

/***************************************************************/
/* Math functionality ******************************************/
/***************************************************************/
float Helper::GetDistance( float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2, bool fromCenter )
{
  if ( fromCenter )
  {
      x1 += w1 / 2;
      y1 += h1 / 2;

      x2 += w2 / 2;
      y2 += h2 / 2;
  }

  return sqrt( pow( x2 - x1, 2 ) + pow( y2 - y1, 2 ) );
}

float Helper::GetDistance( float x1, float y1, float x2, float y2 )
{
    return sqrt( pow( x2 - x1, 2 ) + pow( y2 - y1, 2 ) );
}

float Helper::DotProduct( float x1, float y1, float x2, float y2 )
{
    return ( x1 * x2 + y1 * y2 );
}

float Helper::Length( float x1, float y1 )
{
    return sqrt( x1 * x1 + y1 * y1 );
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define M_PI 3.14159
#endif


float Helper::AngleBetweenTwoPointsRadians( float x1, float y1, float x2, float y2 )
{
    // Reference: https://www.wikihow.com/Find-the-Angle-Between-Two-Vectors
    // Note that SFML uses degrees, cmath uses radians.

    float lengthA = Length( x1, y1 );
    float lengthB = Length( x2, y2 );
    float dotProduct = DotProduct( x1, y1, x2, y2 );
    float cos = dotProduct / ( lengthA * lengthB );
    // acos computes between [-1, +1]
    float angle = acos( cos );
    return angle;
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define M_PI 3.14159
#endif

float Helper::AngleBetweenTwoPointsDegrees( float x1, float y1, float x2, float y2 )
{
    float radians = AngleBetweenTwoPointsDegrees( x1, y1, x2, y2 );
    return radians * 180 / M_PI;


}

bool Helper::BoundingBoxCollision( float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2 )
{
    return (
      x1      < x2 + w2 &&
      x1 + w1 > x2 &&
      y1      < y2 + h2 &&
      y1 + h1 > y2
      );
}

bool Helper::PointInBoxCollision( float x1, float y1, float x2, float y2, float w2, float h2 )
{
    return (
      x1   >= x2 &&
      x1   <= x2 + w2 &&
      y1   >= y2 &&
      y1   <= y2 + h2
    );
}

/***************************************************************/
/* Additional functionality ************************************/

std::string Helper::GetTime()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    char str[26];
    ctime_s(str, sizeof str, &time);
    return str;
#else
    return ctime(&time);
#endif
}

}
