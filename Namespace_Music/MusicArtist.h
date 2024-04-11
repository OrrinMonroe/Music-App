#ifndef _MUSICARTIST
#define _MUSICARTIST

#include <string>
#include <vector>

namespace Music
{

class MusicArtist
{
public:
	void ArtistId(int newArtistId);
	void ArtistName(std::string newName);
	void ArtistBio(std::string newBio);
	void AddAlbumId(int newAlbumId);

	int GetId();
	std::string GetName();
	std::string GetBio();
	std::vector<int> GetAlbumIds();

private:
	int m_artistId;
	std::string m_name;
	std::string m_bio;
	std::vector<int> m_albumIds;

};

}

#endif
