#ifndef _BOOKARTIST
#define _BOOKARTIST

#include <string>
#include <vector>

namespace Audiobook
{

class Author
{
public:
    void SetAuthorId( int newId );
    int GetAuthorId();

    void SetName( std::string newName );
    std::string GetName();

    void SetBio( std::string newBio );
    std::string GetBio();

    void AddAudiobookId( int newId );
    std::vector<int> GetAudiobookIds();

private:
    int m_authorId;
    std::string m_name;
    std::string m_bio;
    std::vector<int> m_audiobookIds;
};

}

#endif
