#include "Album.h"
#include <stdexcept>


namespace Music
{
	//Sets
	void Album::SetId(int newId)
	{
		if (newId < 0) 
		{
			throw std::invalid_argument("Album ID cannot be negative.");
		}
		else // enforce that newId is not negative.
		{
			m_albumId = newId;
		}
	}
	
	void Album::SetTitle(std::string newTitle)
	{
		m_title = newTitle;
	}
	
	void Album::SetArtistIds(int newArtistIds)
	{
		if (newArtistIds < 0)
		{
			throw std::invalid_argument("Artist's ID cannot be negative.");
		}
		else
		{
		m_artistIds.push_back(newArtistIds);
		}
	}
	
	void Album::SetTrackIds(int newTrackIds)
	{
		if (newTrackIds < 0)
		{
			throw std::invalid_argument("Track's ID cannot be negative.");
		}
		else
		{
		m_trackIds.push_back(newTrackIds);
		}
	}
	
	//Gets
	
	int Album::GetAlbumId() const
	{
		return m_albumId;
	}
	
	std::string Album::GetTitle() const
	{
		return m_title;
	}
	
	std::vector<int> Album::GetArtistIds() const
	{
		return m_artistIds;
	}
	
	std::vector<int> Album::GetTrackIds() const
	{
		return m_trackIds;
	}

	void Album::AddArtistId(int newArtistId)
	{
		//throw
		if (newArtistId < 0)
		{
			throw std::invalid_argument("Invalid Artist ID!");
		}
		
		m_artistIds.push_back(newArtistId);
	}

	void Album::AddTrackId(int newTrackId)
	{
		//throw
		if (newTrackId < 0)
		{
			throw std::invalid_argument("Invalid Track ID!");
		}

		m_trackIds.push_back(newTrackId);
	}

	void Album::Display() const
	{
		std::cout << "ALBUM" << std::endl;
		std::cout << "* ALBUM ID: " << m_albumId << std::endl;
		std::cout << "* ALBUM TITLE: " << m_title << std::endl;
		std::cout << "* ARTIST IDs: " << std::endl;
		//iterate through artist ids
		for (auto& id : m_artistIds)
		{
			std::cout << " * " << id << std::endl;
		}
		std::cout << "* TRACK IDs: " << std::endl;
		//iterate through track ids
		for (auto& id : m_trackIds)
		{
			std::cout << " * " << id << std::endl;
		}
		std::cout << std::endl;
	}

}