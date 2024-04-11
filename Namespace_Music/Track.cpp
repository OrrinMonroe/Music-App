#include "Track.h"
#include <stdexcept>
#include <iostream>
namespace Music
{
	void Track::setTrackId(int newTrackId)
	{
		if (newTrackId < 0)
		{
			throw std::invalid_argument("Invalid Track ID");
		}
		m_track_id = newTrackId;
	}

	void Track::setTitle(std::string newTitle)
	{
		m_title = newTitle;
	}

	void Track::setLength(int newLength)
	{
		m_length = newLength;
	}

	void Track::setAlbumId(int newAlbumId)
	{
		if (newAlbumId < 0)
		{
			throw std::invalid_argument("Invalid ID!");
		}
		m_album_id = newAlbumId;
	}

	void Track::setNextTrackId(int newNextTrackId)
	{
		m_next_track_id = newNextTrackId;
	}

	void Track::setPrevTrackId(int newPrevTrackId)
	{
		m_prev_track_id = newPrevTrackId;
	}

	int Track::getTrackId() const
	{
		return m_track_id;
	}

	std::string Track::getTitle() const
	{
		return m_title;
	}

	int Track::getLength() const
	{
		return m_length;
	}

  int Track::getAlbumId() const
	{
		return m_album_id;
	}

	int Track::getNextTrackId() const
	{
		return m_next_track_id;
	}

	int Track::getPrevTrackId() const
	{
		return m_prev_track_id;
	}

	void Track::Display() const
	{
    std::cout << "TRACK:         " << m_title << std::endl;
    std::cout << "TRACK ID:      " << m_track_id << std::endl;
    std::cout << "LENGTH:        " << m_length << " seconds" << std::endl;
    std::cout << "ALBUM ID:      " << m_album_id << std::endl;
    std::cout << "NEXT TRACK ID: " << m_next_track_id << std::endl;
    std::cout << "PREV TRACK ID: " << m_prev_track_id << std::endl;
    std::cout << std::endl;
	}
}
