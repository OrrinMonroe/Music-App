#include "CreatorManager.h"
#include "ShowArtist.h"
#include "../Namespace_Utilities/CsvParser.h"
#include "../Namespace_Utilities/Logger.h"
#include "../Namespace_Metadata/StatusCodeManager.h"

#include <iostream>
#include <string>
#include <vector>

namespace Podcast
{
	string CreatorManager::m_dataPath;
	vector<Creator> CreatorManager::m_creatorList;

  void CreatorManager::LoadData() {
      Utilities::Logger::Push( "CreatorManager" + std::string( __func__ ) );

      Utilities::CsvDocument data;
      try
      {
        data = Utilities::CsvParser::Parse( m_dataPath );
      }
      catch( ... ) {
        Utilities::Logger::Error( "Couldn't find file " + m_dataPath, "CreatorManager" + std::string( __func__ ) );
        return;
      }

      std::string key, name;
      for ( auto& row : data.rows )
      {
          Creator newItem;

          for ( size_t i = 0; i < data.header.size(); i++ )
          {
              std::cout << "row[" << i << "] = \"" << row[i] << "\" (header: " << data.header[i] << ")" << std::endl;

              if      ( data.header[i] == "creator_id" ) { newItem.SetCreatorId( Utilities::Helper::StringToInt( row[i] ) ); }
              else if ( data.header[i] == "name" )      { newItem.SetName( row[i] ); }
              else if ( data.header[i] == "bio" )       { newItem.SetBio( row[i] ); }
              else if ( data.header[i] == "podcast_ids" )
              {
                  std::vector<std::string> ids = Utilities::Helper::Split( row[i], "&" );
                  for ( auto& id : ids )
                  {
                      if ( id == "" ) { continue; }
                      newItem.AddPodcastId( Utilities::Helper::StringToInt( id ) );
                  }
              }
          }

          m_creatorList.push_back( newItem );
      }

      Utilities::Logger::OutValue( "Total creators loaded", m_creatorList.size(), "CreatorManager::" + std::string( __func__ ) );
      Utilities::Logger::Pop();
  }

  void CreatorManager::SaveData() {

      Utilities::Logger::Push( "CreatorManager::" + std::string( __func__ ) );

      // BUILD CSV DOCUMENT
      Utilities::CsvDocument data;
      data.header = std::vector<std::string>( {
          "creator_id", "name", "bio", "podcast_ids"
      } );

      for ( size_t i = 0; i < m_creatorList.size(); i++ )
      {
          std::vector<std::string> columns;
          columns.push_back( Utilities::Helper::ToString( m_creatorList[i].GetCreatorId() ) );
          columns.push_back( m_creatorList[i].GetName() );
          columns.push_back( m_creatorList[i].GetBio() );

          std::string idList = "";
          for ( auto& id : m_creatorList[i].GetPodcastIds() )
          {
              if ( idList != "" ) { idList += "&"; }
              idList += Utilities::Helper::ToString( id );
          }
          columns.push_back( idList );

          data.rows.push_back( columns );
      }
      Utilities::CsvParser::Save( m_dataPath, data );

      Utilities::Logger::OutValue( "Total creators saved", m_creatorList.size(), "CreatorManager::" + std::string( __func__ ) );
      Utilities::Logger::Pop();
  }

	void CreatorManager::Setup(string dataPath)
	{
		m_dataPath = dataPath;
		LoadData();
	}

	void CreatorManager::Cleanup()
	{
		SaveData();
	}

	void CreatorManager::DisplayTable(vector<Creator> creatorList)
	{

		const int ID_COL = 5, NAME_COL = 30;
		std::cout << std::left;
		std::cout
			<< std::setw(ID_COL) << "ID"
			<< std::setw(NAME_COL) << "NAME"
			<< std::endl << std::string(80, '-')
			<< std::endl;

		for (auto creator : creatorList) {

			std::cout
				<< std::setw(ID_COL) << creator.GetCreatorId()
				<< std::setw(NAME_COL) << creator.GetName()
				<< std::endl;

		}
	}

	bool CreatorManager::IsValidID(int id)
	{
		return (id >= 0 && id < m_creatorList.size());
	}

	int CreatorManager::GetCreatorCount()
	{
		return m_creatorList.size();
	}

	int CreatorManager::CreateCreator(string name)
	{
		Creator newCreator;
		newCreator.SetCreatorId(m_creatorList.size());
		newCreator.SetName(name);
		m_creatorList.push_back(newCreator);
		return newCreator.GetCreatorId();

	}

	void CreatorManager::UpdateCreator(int id, const Creator& newCreator)
	{
		if (!IsValidID(id))
		{
			throw invalid_argument("Invalid ID!");
		}
		m_creatorList[id] = newCreator;
	}

	Creator CreatorManager::GetCreator(size_t id)
	{
		if (id < 0 || id >= m_creatorList.size())
		{
			throw std::invalid_argument("Invalid ID!");
		}
		return m_creatorList[id];
	}
}
