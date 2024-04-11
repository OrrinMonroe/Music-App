#ifndef _TRACK
#define _TRACK

#include <string>
#include <vector>

namespace Music
{

class Track
{
public:
	void setTrackId(int newTrackId);
	void setTitle(std::string newTitle);
	void setLength(int newLength);
	void setAlbumId(int newAlbumId);
	void setNextTrackId(int newNextTrackId);
	void setPrevTrackId(int newPrevTrackId);
	void Display() const;

	int getTrackId() const;
	std::string getTitle() const;
	int getLength() const;
	int getAlbumId() const;
	int getNextTrackId() const;
	int getPrevTrackId() const;

	friend class TrackManager;

private:
	int m_track_id;
	std::string m_title;
	int m_length;
	int m_album_id;
	int m_next_track_id;
	int m_prev_track_id;
};

}

#endif
