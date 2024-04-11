#include "EpisodeManager.h"
#include <stdexcept>
#include "../Namespace_Utilities/Logger.h"
#include "../Namespace_Utilities/Helper.h"
#include "../Namespace_Utilities/CsvParser.h"

namespace Podcast {
    std::string EpisodeManager::m_dataPath;
    std::vector <Episode > EpisodeManager::m_episodeList;

  void EpisodeManager::LoadData() {
    Utilities::Logger::Push( "EpisodeManager" + std::string( __func__ ) );

    Utilities::CsvDocument data;
    try
    {
      data = Utilities::CsvParser::Parse( m_dataPath );
    }
    catch( ... ) { return; }

    std::string key, name;
    int audiobook_id;
    for ( auto& row : data.rows )
    {
        Episode newItem;

        for ( size_t i = 0; i < data.header.size(); i++ )
        {
            std::cout << "row[" << i << "] = \"" << row[i] << "\" (header: " << data.header[i] << ")" << std::endl;

            if      ( data.header[i] == "episode_id" )        { newItem.SetEpisodeId( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "title" )             { newItem.SetTitle( row[i] ); }
            else if ( data.header[i] == "length_in_seconds" ) { newItem.SetLength( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "podcast_id" )        { newItem.SetPodcastId( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "next_episode_id" )   { newItem.SetNextExpisodeId( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "prev_episode_id" )   { newItem.SetPreviousId( Utilities::Helper::StringToInt( row[i] ) ); }
        }

        m_episodeList.push_back( newItem );
    }

    Utilities::Logger::OutValue( "Total episodes loaded", m_episodeList.size(), "EpisodeManager::" + std::string( __func__ ) );
    Utilities::Logger::Pop();
  }

  void EpisodeManager::SaveData() {
    Utilities::Logger::Push( "EpisodeManager::" + std::string( __func__ ) );

    // BUILD CSV DOCUMENT
    Utilities::CsvDocument data;
    data.header = std::vector<std::string>( {
        "episode_id", "title", "length_in_seconds", "podcast_id", "next_episode_id", "prev_episode_id"
    } );

    for ( size_t i = 0; i < m_episodeList.size(); i++ )
    {
        std::vector<std::string> columns;
        columns.push_back( Utilities::Helper::ToString( m_episodeList[i].GetEpisodeId() ) );
        columns.push_back( m_episodeList[i].GetNewTitle() );
        columns.push_back( Utilities::Helper::ToString( m_episodeList[i].GetLength() ) );
        columns.push_back( Utilities::Helper::ToString( m_episodeList[i].GetPodcastId() ) );
        columns.push_back( Utilities::Helper::ToString( m_episodeList[i].GetNextEposideId() ) );
        columns.push_back( Utilities::Helper::ToString( m_episodeList[i].GetPreviousEposideId() ) );

        data.rows.push_back( columns );
    }
    Utilities::CsvParser::Save( m_dataPath, data );

    Utilities::Logger::OutValue( "Total episodes saved", m_episodeList.size(), "EpisodeManager::" + std::string( __func__ ) );
    Utilities::Logger::Pop();
  }

    void EpisodeManager::Setup(std::string dataPath)
    {
        Utilities::Logger::Push("EpisodeManager::" + std::string(__func__));
        m_dataPath = dataPath;
        LoadData();
        Utilities::Logger::Pop();
    }
    void EpisodeManager::Cleanup()
    {
        Utilities::Logger::Push("EpisodeManager::" + std::string(__func__));
        SaveData();
        Utilities::Logger::Pop();
    }

    void EpisodeManager::DisplayTable( std::vector<Episode>& episodeList)
    {

        std::cout << std::left;
        std::cout
            << std::setw(5) << "ID"
            << std::setw(20) << "Title"
            << std::setw(10) << "Length"
            << std::setw(14) << "PODCAST ID"
            << std::setw(25) << "NEXT EPISODE ID"
            << std::setw(25) << "PREVIOUS EPISODE ID"
            << std::endl << std::string(80, '-') << std::endl;

        for (auto& episode : episodeList)
        {
            //std::cout << std::left;
            std::cout
                << std::setw(5) << episode.GetEpisodeId()
                << std::setw(20) << episode.GetNewTitle()
                << std::setw(10) << episode.GetLength()
                << std::setw(14) << episode.GetPodcastId()
                << std::setw(25) << episode.GetNextEposideId()
                << std::setw(25) << episode.GetPreviousEposideId()
                << std::endl;
        }
    }



    size_t  EpisodeManager::GetEpisodeCount()
    {
        return m_episodeList.size();

    }
    int  EpisodeManager::CreateEpisode(std::string title)
    {
        Episode newEpisode;
        newEpisode.SetEpisodeId(m_episodeList.size()+1);
        newEpisode.SetTitle(title);


        newEpisode.SetLength(0);
        newEpisode.SetPodcastId(0);
        newEpisode.SetNextExpisodeId(newEpisode.GetEpisodeId() + 1);
        newEpisode.SetPreviousId(newEpisode.GetEpisodeId() - 1);


        m_episodeList.push_back(newEpisode);

        return newEpisode.GetEpisodeId();

    }
    void EpisodeManager::UpdateEpisode(size_t id, const Podcast ::Episode& episode)
    {

        if (!IsValidId(id))
        {
            throw std::invalid_argument("Invalid ID!");
        }

        m_episodeList[id] = episode;


    }
    Episode EpisodeManager::GetEpisode(size_t id)
    {


        if (id < 0 || id >= m_episodeList.size())
        {

            throw std::invalid_argument("Invalid Id");
        }
        return m_episodeList[id];


    }
    bool EpisodeManager::IsValidId(size_t id)
    {
        return (id >= 0 && id < m_episodeList.size());
    }
}
