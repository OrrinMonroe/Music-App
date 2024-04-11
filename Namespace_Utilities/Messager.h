// Chalo Engine, Moosader 2019-2020, https://gitlab.com/RachelWilShaSingh/chalo-engine

#ifndef MESSAGER_HPP
#define MESSAGER_HPP

#include <string>
#include <map>

namespace Utilities
{

//! Simple message passer
class Messager
{
public:
    static void Set( const std::string& key, const std::string& value );
    static void Set( const std::string& key, int value );
    static std::string Get( const std::string& key );
    static int GetInt( const std::string& key );
    static bool Has( const std::string& key );
    static void Erase( const std::string& key );

private:
    static std::map<std::string, std::string> msg;
};

}

#endif
