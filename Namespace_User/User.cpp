#include "User.h"
#include <stdexcept>
#include <iostream>

namespace User
{

void User::SetId( int newId )
{
    m_userId = newId;
}

void User::SetName( std::string newName )
{
    m_name = newName;
}

void User::AddPlaylistId( int newPlaylistId )
{
    if ( newPlaylistId < 0 )
    {
        throw std::invalid_argument( "Invalid ID!" );
    }
    m_playlistIds.push_back( newPlaylistId );
}

int User::GetId() const
{
    return m_userId;
}

std::string User::GetName() const
{
    return m_name;
}

std::vector<int> User::GetPlaylistIds() const
{
    return m_playlistIds;
}

void User::Display() const
{
    std::cout << "USER" << std::endl;
    std::cout << "* USER ID: " << m_userId << std::endl;
    std::cout << "* NAME:    " << m_name << std::endl;
    std::cout << "* PLAYLIST IDS:" << std::endl;
    for ( auto& id : m_playlistIds )
    {
        std::cout << "  * " << id << std::endl;
    }
    std::cout << std::endl;
}

}
