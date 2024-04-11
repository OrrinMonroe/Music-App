#include "BookArtist.h"
#include <stdexcept>

namespace Audiobook
{

void Author::SetAuthorId( int newId )
{
    if ( newId < 0 ) { throw std::invalid_argument( "Bad ID" ); }
    m_authorId = newId;
}

int Author::GetAuthorId()
{
    return m_authorId;
}

void Author::SetName( std::string newName )
{
    m_name = newName;
}

std::string Author::GetName()
{
    return m_name;
}

void Author::SetBio( std::string newBio )
{
    m_bio = newBio;
}

std::string Author::GetBio()
{
    return m_bio;
}


void Author::AddAudiobookId( int newId )
{
    if ( newId < 0 ) { throw std::invalid_argument( "Bad ID" ); }
    m_audiobookIds.push_back( newId );
}

std::vector<int> Author::GetAudiobookIds()
{
    return m_audiobookIds;
}

}
