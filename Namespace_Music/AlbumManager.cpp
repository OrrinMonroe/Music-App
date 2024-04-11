#include "AlbumManager.h"
#include <iostream>
#include<iomanip>
#include <fstream>
#include <stdexcept>
#include "../Namespace_Utilities/CsvParser.h"
#include "../Namespace_Utilities/Logger.h"
#include "../Namespace_Metadata/StatusCodeManager.h"


namespace Music
{
	//the member variables
	std::string AlbumManager::m_dataPath;
	std::vector<Album> AlbumManager::m_albumList;

	void AlbumManager::LoadData() {
    Utilities::Logger::Push( "AlbumManager" + std::string( __func__ ) );

    Utilities::CsvDocument data = Utilities::CsvParser::Parse( m_dataPath );

    std::string key, name;
    int audiobook_id;
    for ( auto& row : data.rows )
    {
        Album newItem;

        for ( size_t i = 0; i < data.header.size(); i++ )
        {
            std::cout << "row[" << i << "] = \"" << row[i] << "\" (header: " << data.header[i] << ")" << std::endl;

            if      ( data.header[i] == "album_id" )    { newItem.SetId( Utilities::Helper::StringToInt( row[i] ) ); }
            else if ( data.header[i] == "title" )       { newItem.SetTitle( row[i] ); }
            else if ( data.header[i] == "artist_ids" )
            {
                std::vector<std::string> ids = Utilities::Helper::Split( row[i], "&" );
                for ( auto& id : ids )
                {
                    if ( id == "" ) { continue; }
                    newItem.AddArtistId( Utilities::Helper::StringToInt( id ) );
                }
            }
            else if ( data.header[i] == "track_ids" )
            {
                std::vector<std::string> ids = Utilities::Helper::Split( row[i], "&" );
                for ( auto& id : ids )
                {
                    if ( id == "" ) { continue; }
                    newItem.AddTrackId( Utilities::Helper::StringToInt( id ) );
                }
            }
        }

        m_albumList.push_back( newItem );
    }

    Utilities::Logger::OutValue( "Total albums loaded", m_albumList.size(), "AlbumManager::" + std::string( __func__ ) );
    Utilities::Logger::Pop();
	}

	void AlbumManager::SaveData() {
    Utilities::Logger::Push( "AlbumManager::" + std::string( __func__ ) );

    // BUILD CSV DOCUMENT
    Utilities::CsvDocument data;
    data.header = std::vector<std::string>( {
        "album_id", "title", "artist_ids", "track_ids"
    } );

    for ( size_t i = 0; i < m_albumList.size(); i++ )
    {
        std::vector<std::string> columns;
        columns.push_back( Utilities::Helper::ToString( m_albumList[i].GetAlbumId() ) );
        columns.push_back( m_albumList[i].GetTitle() );

        std::string idList = "";
        for ( auto& id : m_albumList[i].GetArtistIds() )
        {
            if ( idList != "" ) { idList += "&"; }
            idList += Utilities::Helper::ToString( id );
        }
        columns.push_back( idList );

        idList = "";
        for ( auto& id : m_albumList[i].GetTrackIds() )
        {
            if ( idList != "" ) { idList += "&"; }
            idList += Utilities::Helper::ToString( id );
        }
        columns.push_back( idList );

        data.rows.push_back( columns );
    }
    Utilities::CsvParser::Save( m_dataPath, data );

    Utilities::Logger::OutValue( "Total albums saved", m_albumList.size(), "AlbumManager::" + std::string( __func__ ) );
    Utilities::Logger::Pop();
	}

	void AlbumManager::Setup(std::string dataPath)
	{
		m_dataPath = dataPath;
		LoadData();
	}

	void AlbumManager::Cleanup()
	{
		SaveData();
	}

	void AlbumManager::DisplayTable(std::vector<Album> albumList) //Get to use "albumList" instead of m_albumList
	{
		std::cout << std::left;
		std::cout
			<< std::setw(25) << "ALBUM TITLE"
			<< std::setw(14) << "ALBUM ID "
			<< std::setw(14) << "# TRACKS"
			<< std::setw(14) << "# ARTISTS"

			<< std::endl
			<< std::string(80, '-') << std::endl;

		for (auto& album : albumList) // using album instead of using "i" such as in a regular for-loop.
		{
			std::cout
				<< std::setw(25) << album.GetTitle() //TITLE
				<< std::setw(14) << album.GetAlbumId()//ALBUM ID
				<< std::setw(14) << album.GetTrackIds().size()//#TRACKS
				<< std::setw(14) << album.GetArtistIds().size()//#ARTISTS
				<< std::endl;
		}
	}

	bool AlbumManager::IsValidId(size_t id)
	{
		return (id >= 0 && id < m_albumList.size()); // 0-albumList size
	}

	size_t AlbumManager::GetAlbumCount()
	{
		return m_albumList.size();
	}
	size_t AlbumManager::CreateAlbum(std::string newTitle)
	{
		Album newAlbum;
		newAlbum.SetId(m_albumList.size());//current size will be the newAlbum's Id.
		newAlbum.SetTitle(newTitle);
		/*newAlbum.SetArtistIds(newArtistId);
		newAlbum.SetTrackIds(newTrackIds);*/
		m_albumList.push_back(newAlbum);
		return newAlbum.GetAlbumId();
	 }

	void AlbumManager::UpdateAlbum(size_t id, const Album& newAlbum)
	{
		//throw
		if (!IsValidId(id))
		{
			throw std::invalid_argument("Invalid Album ID!");
		}

		m_albumList[id] = newAlbum; //updating at that specific id.
	}

	Album AlbumManager::GetAlbum(size_t id)
	{
		//throw
		if (id < 0 || id >= m_albumList.size())//Not negative OR greater than vector size
		{
			throw std::invalid_argument("Invalid Album ID!");
		}

		return m_albumList[id];
	}
}
