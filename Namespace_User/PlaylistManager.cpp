#include "PlaylistManager.h"
#include "../Namespace_Utilities/Logger.h"
#include "../Namespace_Utilities/Helper.h"
#include "../Namespace_Utilities/CsvParser.h"
#include <iostream>
#include <iomanip>

namespace User
{

std::string PlaylistManager::m_dataPath;
std::vector<Playlist> PlaylistManager::m_playlistList;

void PlaylistManager::Setup( std::string dataPath )
{
    Utilities::Logger::Push( "PlaylistManager::" + std::string( __func__ ) );
    m_dataPath = dataPath;
    LoadData();
    Utilities::Logger::Pop();
}

void PlaylistManager::Cleanup()
{
    Utilities::Logger::Push( "PlaylistManager::" + std::string( __func__ ) );
    SaveData();
    Utilities::Logger::Pop();
}

void PlaylistManager::LoadData()
{
    Utilities::Logger::Push( "PlaylistManager" + std::string( __func__ ) );

    Utilities::CsvDocument data = Utilities::CsvParser::Parse( m_dataPath );

    std::string key, name;
    int id;
    for ( auto& row : data.rows )
    {
        Playlist newPlaylist;

        for ( size_t i = 0; i < data.header.size(); i++ )
        {
            std::cout << "row[" << i << "] = \"" << row[i] << "\" (header: " << data.header[i] << ")" << std::endl;

            if      ( data.header[i] == "id" )              { newPlaylist.SetId( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "usercreatorid" )   { newPlaylist.SetUserCreatorId( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "name" )            { newPlaylist.SetName( row[i] ); }
            else if ( data.header[i] == "trackids" )
            {
                std::vector<std::string> ids = Utilities::Helper::Split( row[i], "&" );
                for ( auto& id : ids )
                {
                    if ( id == "" ) { continue; }
                    newPlaylist.AddTrackId( Utilities::Helper::StringToInt( id ) );
                }
            }
            else if ( data.header[i] == "episodeids" )
            {
                std::vector<std::string> ids = Utilities::Helper::Split( row[i], "&" );
                for ( auto& id : ids )
                {
                    if ( id == "" ) { continue; }
                    newPlaylist.AddEpisodeId( Utilities::Helper::StringToInt( id ) );
                }
            }
            else if ( data.header[i] == "chapterids" )
            {
                std::vector<std::string> ids = Utilities::Helper::Split( row[i], "&" );
                for ( auto& id : ids )
                {
                    if ( id == "" ) { continue; }
                    newPlaylist.AddChapterId( Utilities::Helper::StringToInt( id ) );
                }
            }
        }

        m_playlistList.push_back( newPlaylist );
    }

    Utilities::Logger::OutValue( "Total playlists loaded", m_playlistList.size(), "PlaylistManager::" + std::string( __func__ ) );
    Utilities::Logger::Pop();
}

void PlaylistManager::SaveData()
{
    Utilities::Logger::Push( "PlaylistManager::" + std::string( __func__ ) );

    // BUILD CSV DOCUMENT
    Utilities::CsvDocument data;
    data.header = std::vector<std::string>( {
        "id", "usercreatorid", "name", "trackids", "episodeids", "chapterids"
    } );

    for ( size_t i = 0; i < m_playlistList.size(); i++ )
    {
        std::vector<std::string> columns;
        columns.push_back( Utilities::Helper::ToString( m_playlistList[i].GetId() ) );
        columns.push_back( Utilities::Helper::ToString( m_playlistList[i].GetUserCreatorId() ) );
        columns.push_back( m_playlistList[i].GetName() );

        std::string idList = "";
        for ( auto& id : m_playlistList[i].GetTrackIds() )
        {
            if ( idList != "" ) { idList += "&"; }
            idList += Utilities::Helper::ToString( id );
        }
        columns.push_back( idList );

        idList = "";
        for ( auto& id : m_playlistList[i].GetEpisodeIds() )
        {
            if ( idList != "" ) { idList += "&"; }
            idList += Utilities::Helper::ToString( id );
        }
        columns.push_back( idList );

        idList = "";
        for ( auto& id : m_playlistList[i].GetChapterIds() )
        {
            if ( idList != "" ) { idList += "&"; }
            idList += Utilities::Helper::ToString( id );
        }
        columns.push_back( idList );
        data.rows.push_back( columns );
    }

    Utilities::CsvParser::Save( m_dataPath, data );

    Utilities::Logger::OutValue( "Total playlists saved", m_playlistList.size(), "PlaylistManager::" + std::string( __func__ ) );
    Utilities::Logger::Pop();
}

size_t PlaylistManager::GetPlaylistCount()
{
    return m_playlistList.size();
}

int PlaylistManager::CreatePlaylist( std::string name, int playlistCreatorId )
{
    Playlist newPlaylist;
    newPlaylist.SetId( m_playlistList.size() );
    newPlaylist.SetName( name );
    newPlaylist.SetUserCreatorId( playlistCreatorId );
    m_playlistList.push_back( newPlaylist );
    return newPlaylist.GetId();
}

Playlist PlaylistManager::GetPlaylist( size_t id )
{
    if ( id < 0 || id >= m_playlistList.size() )
    {
        throw std::invalid_argument( "Invalid ID!" );
    }

    return m_playlistList[id];
}

bool PlaylistManager::IsValidId( size_t id )
{
    return ( id >= 0 && id < m_playlistList.size() );
}

void PlaylistManager::DisplayTable( const std::vector<Playlist>& playlistList /* = m_playlistList*/ )
{
    std::cout << std::left;
    std::cout
        << std::setw( 5 ) << "ID"
        << std::setw( 10 ) << "CREATOR"
        << std::setw( 25 ) << "NAME"
        << std::setw( 14 ) << "# TRACKS"
        << std::setw( 14 ) << "# EPISODES"
        << std::setw( 14 ) << "# CHAPTERS"
        << std::endl << std::string( 80, '-' ) << std::endl;

    for ( auto& playlist : playlistList )
    {
        std::cout
            << std::setw( 5 ) << playlist.GetId()
            << std::setw( 10 ) << playlist.GetUserCreatorId()
            << std::setw( 25 ) << Utilities::Helper::DisplayTrim( playlist.GetName(), 24 )
            << std::setw( 14 ) << playlist.GetTrackIds().size()
            << std::setw( 14 ) << playlist.GetEpisodeIds().size()
            << std::setw( 14 ) << playlist.GetChapterIds().size()
            << std::endl;
    }
}

}
