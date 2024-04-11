#include "UserManager.h"

#include "../Namespace_Utilities/CsvParser.h"
#include "../Namespace_Utilities/Logger.h"
#include "../Namespace_Metadata/StatusCodeManager.h"

#include <iostream>
#include <iomanip>
#include <fstream>

namespace User
{

std::string UserManager::m_dataPath;
std::vector<User> UserManager::m_userList;

void UserManager::Setup( std::string dataPath )
{
    Utilities::Logger::Push( "UserManager::" + std::string( __func__ ) );
    m_dataPath = dataPath;
    LoadData();
    Utilities::Logger::Pop();
}

void UserManager::Cleanup()
{
    Utilities::Logger::Push( "UserManager::" + std::string( __func__ ) );
    SaveData();
    Utilities::Logger::Pop();
}

size_t UserManager::GetUserCount()
{
    return m_userList.size();
}

int UserManager::CreateUser( std::string name )
{
    User newUser;
    newUser.SetId( m_userList.size() );
    newUser.SetName( name );
    m_userList.push_back( newUser );
    return newUser.GetId();
}

void UserManager::UpdateUser( int id, const User& newUser )
{
    if ( !IsValidId( id ) )
    {
        throw std::invalid_argument( "Invalid ID!" );
    }

    m_userList[id] = newUser;
}

User UserManager::GetUser( size_t id )
{
    if ( id < 0 || id >= m_userList.size() )
    {
        throw std::invalid_argument( "Invalid ID!" );
    }

    return m_userList[id];
}

bool UserManager::IsValidId( size_t id )
{
    return ( id >= 0 && id < m_userList.size() );
}

void UserManager::LoadData()
{
    Utilities::Logger::Push( "UserManager" + std::string( __func__ ) );

    Utilities::CsvDocument data = Utilities::CsvParser::Parse( m_dataPath );

    std::string key, name;
    int id;
    for ( auto& row : data.rows )
    {
        User newUser;

        for ( size_t i = 0; i < data.header.size(); i++ )
        {
            std::cout << "row[" << i << "] = \"" << row[i] << "\" (header: " << data.header[i] << ")" << std::endl;

            if      ( data.header[i] == "id" )      { newUser.SetId( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "name" )    { newUser.SetName( row[i] ); }
            else if ( data.header[i] == "playlistids" )
            {
                std::vector<std::string> playlistIds = Utilities::Helper::Split( row[i], "&" );
                for ( auto& pid : playlistIds )
                {
                    if ( pid == "" ) { continue; }
                    newUser.AddPlaylistId( Utilities::Helper::StringToInt( pid ) );
                }
            }
        }

        m_userList.push_back( newUser );
    }

    Utilities::Logger::OutValue( "Total users loaded", m_userList.size(), "UserManager::" + std::string( __func__ ) );
    Utilities::Logger::Pop();
}

void UserManager::SaveData()
{
    Utilities::Logger::Push( "UserManager::" + std::string( __func__ ) );

    // BUILD CSV DOCUMENT
    Utilities::CsvDocument data;
    data.header = std::vector<std::string>( {
        "id", "name", "playlistids"
    } );

    for ( size_t i = 0; i < m_userList.size(); i++ )
    {
        std::vector<std::string> columns;
        columns.push_back( Utilities::Helper::ToString( m_userList[i].GetId() ) );
        columns.push_back( m_userList[i].GetName() );

        std::string idList = "";
        for ( auto& id : m_userList[i].GetPlaylistIds() )
        {
            if ( idList != "" ) { idList += "&"; }
            idList += Utilities::Helper::ToString( id );
        }
        columns.push_back( idList );

        columns.push_back( idList );
        data.rows.push_back( columns );
    }

    Utilities::CsvParser::Save( m_dataPath, data );
    Utilities::Logger::OutValue( "Total users saved", m_userList.size(), "UserManager::" + std::string( __func__ ) );
    Utilities::Logger::Pop();
}

/** IGNORE THIS FUNCTION, IT'S FOR API **/
void UserManager::CreateUser( Metadata::StatusCode& result, const std::vector<std::string>& arguments )
{
    Utilities::Logger::Push( "UserManager::" + std::string( __func__ ) );
    Utilities::Logger::Out( "Arguments: " + Utilities::Helper::VectorToString( arguments ), "UserManager::" + std::string( __func__ ) );

    if ( arguments.size() < 1 )
    {
        result = Metadata::StatusCodeManager::GetCode( 400 );
        result.message = "Missing argument(s): NAME";
        Utilities::Logger::Pop();
        return;
    }

    User newUser;
    newUser.SetId( m_userList.size() );
    newUser.SetName( arguments[0] );
    m_userList.push_back( newUser );
    SaveData();

    result = Metadata::StatusCodeManager::GetCode( 200 );
    Utilities::Logger::Pop();
    return;
}

/** IGNORE THIS FUNCTION, IT'S FOR API **/
std::vector<User> UserManager::GetUsers( Metadata::StatusCode& result, const std::vector<std::string>& arguments )
{
    Utilities::Logger::Push( "UserManager::" + std::string( __func__ ) );
    Utilities::Logger::Out( "Arguments: " + Utilities::Helper::VectorToString( arguments ), "UserManager::" + std::string( __func__ ) );

    // No arguments; return all
    if ( arguments.size() < 1 )
    {
        result = Metadata::StatusCodeManager::GetCode( 200 );
        Utilities::Logger::Pop();
        return m_userList;
    }

    // Arguments contain id, search for
    std::vector<User> matchingUsers;
    for ( auto& arg : arguments )
    {
        int index = Utilities::Helper::StringToInt( arg );

        // Search for this user
        for ( auto& user : m_userList )
        {
            if ( user.GetId() == index )
            {
                matchingUsers.push_back( user );
            }
        }
    }

    result = Metadata::StatusCodeManager::GetCode( 200 );
    Utilities::Logger::Pop();
    return matchingUsers;
}

void UserManager::DisplayTable( const std::vector<User>& userList /* = m_userList*/ )
{
    const int ID_COL = 5, NAME_COL = 30;
    std::cout << std::left;
    std::cout
        << std::setw( ID_COL ) << "ID"
        << std::setw( NAME_COL ) << "NAME"

        << std::endl << std::string( 80, '-' ) << std::endl;

    for ( auto& user : userList )
    {
        std::cout
            << std::setw( ID_COL ) << user.GetId()
            << std::setw( NAME_COL ) << user.GetName()
            << std::endl;
    }
}


};
