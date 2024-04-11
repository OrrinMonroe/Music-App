#include "MusicArtist.h"
#include <iostream>

namespace Music
{

void MusicArtist::ArtistId(int newArtistId)
{
    if (newArtistId < 0)
    {
            throw std::invalid_argument("Id cannot be negative!");
        }
    else m_artistId = newArtistId;
}

void MusicArtist::ArtistName(std::string newName)
{
    m_name = newName;
}

void MusicArtist::AddAlbumId(int newAlbumId)
{
    if (newAlbumId < 0)
    {
        throw std::invalid_argument("Id cannot be negative!");
    }
    else m_albumIds.push_back(newAlbumId);
}

int MusicArtist::GetId()
{
    return m_artistId;
}

std::string MusicArtist::GetName()
{
    return m_name;
}

std::string MusicArtist::GetBio()
{
    return m_bio;
}

std::vector<int> MusicArtist::GetAlbumIds()
{
    return m_albumIds;
}

}
