#ifndef _USER
#define _USER

#include <string>
#include <vector>

namespace User
{

class User
{
public:
    void SetId( int newId );
    void SetName( std::string newName );
    void AddPlaylistId( int newPlaylistId );

    int GetId() const;
    std::string GetName() const;
    std::vector<int> GetPlaylistIds() const;
    void Display() const;

private:
    int m_userId;
    std::string m_name;
    std::vector<int> m_playlistIds;

    friend class UserTester;
    friend class UserManager;
};

}

#endif
