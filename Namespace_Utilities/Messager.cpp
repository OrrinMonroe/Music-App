#include "Messager.h"
#include "Logger.h"
#include "Helper.h"

namespace Utilities
{

std::map<std::string, std::string> Messager::msg;

//! Set a global message
/**
@param      key     Identifying key of the message
@param      value   Value of the message
*/
void Messager::Set( const std::string& key, const std::string& value )
{
    Logger::Out( "Set \"" + key + "\" = \"" + value + "\"", "Messager::Set" );
    Messager::msg[ key ] = value;
}

//! Set a global message
/**
@param      key     Identifying key of the message
@param      value   Value of the message
*/
void Messager::Set( const std::string& key, int value )
{
    Set( key, Helper::ToString( value ) );
}

//! Retrieve a global message
/**
@param      key     Identifying key of the message
@return             The value of the message
*/
std::string Messager::Get( const std::string& key )
{
    return Messager::msg[ key ];
}

//! Retrieve a global message
/**
@param      key     Identifying key of the message
@return             The value of the message (as an int)
*/
int Messager::GetInt( const std::string& key )
{
    return Helper::StringToInt( Messager::msg[ key ] );
}

bool Messager::Has( const std::string& key )
{
    return ( Messager::msg.find( key ) != Messager::msg.end() );
}

void Messager::Erase( const std::string& key )
{
    std::map<std::string, std::string>::iterator item = Messager::msg.find( key );
    Messager::msg.erase( item );
}


}
