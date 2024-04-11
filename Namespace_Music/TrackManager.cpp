#include "TrackManager.h"
#include <stdexcept>
#include "../Namespace_Utilities/CsvParser.h"
#include "../Namespace_Utilities/Logger.h"
#include "../Namespace_Metadata/StatusCodeManager.h"



namespace Music
{

	std::string TrackManager::m_dataPath;
	std::vector<Track> TrackManager::m_trackList;

  void TrackManager::LoadData() {
    Utilities::Logger::Push( "TrackManager" + std::string( __func__ ) );

    Utilities::CsvDocument data;
    try
    {
      data = Utilities::CsvParser::Parse( m_dataPath );
    }
    catch( ... )
    {
      return;
    }

    std::string key, name;
    int audiobook_id;
    for ( auto& row : data.rows )
    {
        Track newItem;

        for ( size_t i = 0; i < data.header.size(); i++ )
        {
            std::cout << "row[" << i << "] = \"" << row[i] << "\" (header: " << data.header[i] << ")" << std::endl;

            if      ( data.header[i] == "track_id" )            { newItem.setTrackId( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "title" )               { newItem.setTitle( row[i] ); }
            else if ( data.header[i] == "length_in_seconds" )   { newItem.setLength( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "album_id" )            { newItem.setAlbumId( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "next_track_id" )       { newItem.setNextTrackId( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "prev_track_id" )       { newItem.setPrevTrackId( Utilities::Helper::StringToInt( row[i] ) ); }
        }

        m_trackList.push_back( newItem );
    }

    Utilities::Logger::OutValue( "Total artists loaded", m_trackList.size(), "TrackManager::" + std::string( __func__ ) );
    Utilities::Logger::Pop();
  }

  void TrackManager::SaveData() {
    Utilities::Logger::Push( "TrackManager::" + std::string( __func__ ) );

    // BUILD CSV DOCUMENT
    Utilities::CsvDocument data;
    data.header = std::vector<std::string>( {
        "track_id", "title", "length_in_seconds", "album_id", "next_track_id", "prev_track_id"
    } );

    for ( size_t i = 0; i < m_trackList.size(); i++ )
    {
        std::vector<std::string> columns;
        columns.push_back( Utilities::Helper::ToString( m_trackList[i].getTrackId() ) );
        columns.push_back( m_trackList[i].getTitle() );
        columns.push_back( Utilities::Helper::ToString( m_trackList[i].getLength() ) );
        columns.push_back( Utilities::Helper::ToString( m_trackList[i].getAlbumId() ) );
        columns.push_back( Utilities::Helper::ToString( m_trackList[i].getNextTrackId() ) );
        columns.push_back( Utilities::Helper::ToString( m_trackList[i].getPrevTrackId() ) );


        data.rows.push_back( columns );
    }
    Utilities::CsvParser::Save( m_dataPath, data );

    Utilities::Logger::OutValue( "Total artists saved", m_trackList.size(), "TrackManager::" + std::string( __func__ ) );
    Utilities::Logger::Pop();
  }


	void TrackManager::Setup(std::string dataPath)
	{
		m_dataPath = dataPath;
		LoadData();
	}

	void TrackManager::Cleanup()
	{
		SaveData();
	}

	void TrackManager::DisplayTable(const std::vector<Track>& trackList /* = m_trackList*/)
	{
        // Default to m_trackList if trackList is not provided
        const std::vector<Track>& tracksToDisplay = (trackList.empty()) ? m_trackList : trackList;

        // Display header
        std::cout << "Track ID | Title               | Length | Album ID | Next Track ID | Prev Track ID" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;

        for (const Track& track : tracksToDisplay) {
            std::cout << track.getTrackId() << "\t| " << track.getTitle();
            // Adjust spacing for better alignment
            int titlePadding = 20 - static_cast<int>(track.getTitle().length());
            for (int i = 0; i < titlePadding; ++i) {
                std::cout << " ";
            }
            std::cout << "| " << track.getLength() << "\t| " << track.getAlbumId()
                      << "\t| " << track.getNextTrackId() << "\t| " << track.getPrevTrackId() << std::endl;
        }
    }

	bool TrackManager::IsValidId(size_t id)
	{
		if (id >= 0 && id < m_trackList.size())
		{
			return true;
		}
		else
		{
			false;
		}
	}

	size_t TrackManager::GetTrackCount()
	{
		return  m_trackList.size();
	}

	int TrackManager::CreateTrack(std::string name)
	{
		Track newTrack;
		newTrack.setTrackId(m_trackList.size());
		newTrack.setTitle(name);
		m_trackList.push_back(newTrack);
		return newTrack.getTrackId();
	}

	void TrackManager::UpdateTrack(int id, const Track& newTrack)
	{
		if (!IsValidId(id))
		{
			throw std::invalid_argument("Invalid ID!");
		}
		m_trackList[id] = newTrack;
	}

	Track TrackManager::GetTrack(size_t id)
	{
		if (id < 0 || id >= m_trackList.size())
		{
			throw std::invalid_argument("Invalid ID!");
		}

		return m_trackList[id];
	}
}
