#ifndef _ALBUM
#define _ALBUM
#include <string>
#include <vector>
#include <iostream>

namespace Music
{

class Album
{
public:

	// Get
	int GetAlbumId() const;
	std::string GetTitle() const;
	std::vector<int> GetArtistIds() const;
	std::vector<int> GetTrackIds() const;
	void Display() const;
	
	// Set
	void SetId (int newId);
	void SetTitle (std::string newTitle);
	void SetArtistIds(int newArtistId); 
	void SetTrackIds(int newTrackIds);
	void AddArtistId(int newArtistId);
	void AddTrackId(int newTrackId);


private:
	int m_albumId;
	std::string m_title;
	std::vector<int> m_artistIds;
	std::vector<int> m_trackIds;

	friend class AlbumManager;
};

}

#endif
