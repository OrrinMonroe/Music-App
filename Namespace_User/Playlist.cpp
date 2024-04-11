#include "Playlist.h"
#include <stdexcept>
#include <iostream>

namespace User
{

void Playlist::SetId( int id )
{
    if ( id < 0 )
    {
        throw std::invalid_argument( "Invalid ID!" );
    }

    m_playlistId = id;
}

void Playlist::SetName( std::string name )
{
    m_name = name;
}

void Playlist::SetUserCreatorId( int id )
{
    if ( id < 0 )
    {
        throw std::invalid_argument( "Invalid ID!" );
    }

    m_userCreatorId = id;
}

void Playlist::AddTrackId( int newTrackId )
{
    if ( newTrackId < 0 )
    {
        throw std::invalid_argument( "Invalid ID!" );
    }

    m_trackIds.push_back( newTrackId );
}

void Playlist::AddChapterId( int newChapterId )
{
    if ( newChapterId < 0 )
    {
        throw std::invalid_argument( "Invalid ID!" );
    }

    m_chapterIds.push_back( newChapterId );
}

void Playlist::AddEpisodeId( int newEpisodeId )
{
    if ( newEpisodeId < 0 )
    {
        throw std::invalid_argument( "Invalid ID!" );
    }

    m_episodeIds.push_back( newEpisodeId );
}

int Playlist::GetId() const
{
    return m_playlistId;
}

std::string Playlist::GetName() const
{
    return m_name;
}

int Playlist::GetUserCreatorId() const
{
    return m_userCreatorId;
}

const std::vector<int>& Playlist::GetTrackIds() const
{
    return m_trackIds;
}

const std::vector<int>& Playlist::GetEpisodeIds() const
{
    return m_episodeIds;
}

const std::vector<int>& Playlist::GetChapterIds() const
{
    return m_chapterIds;
}

void Playlist::Display() const
{
    std::cout << "PLAYLIST" << std::endl;
    std::cout << "* PLAYLIST ID: " << m_playlistId << std::endl;
    std::cout << "* CREATOR ID : " << m_userCreatorId << std::endl;
    std::cout << "* NAME:        " << m_name << std::endl;
    std::cout << "* MUSIC TRACK IDS:" << std::endl;
    for ( auto& id : m_trackIds )
    {
        std::cout << "  * " << id << std::endl;
    }
    std::cout << "* AUDIOBOOK CHAPTER IDS:" << std::endl;
    for ( auto& id : m_chapterIds )
    {
        std::cout << "  * " << id << std::endl;
    }
    std::cout << "* PODCAST EPISODE IDS:" << std::endl;
    for ( auto& id : m_episodeIds )
    {
        std::cout << "  * " << id << std::endl;
    }
    std::cout << std::endl;
}

}
