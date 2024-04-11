#ifndef _PLAYLISTMANAGER
#define _PLAYLISTMANAGER

#include "UserManager.h"
#include "Playlist.h"
#include <vector>
#include <string>

namespace User
{

class PlaylistManager
{
    public:
    static void Setup( std::string dataPath );
    static void Cleanup();
    static void DisplayTable( const std::vector<Playlist>& playlistList = m_playlistList );
    static size_t GetPlaylistCount();
    static int CreatePlaylist( std::string name, int playlistCreatorId );
    static Playlist GetPlaylist( size_t id );
    static bool IsValidId( size_t id );

    static void LoadData();
    static void SaveData();

    private:
    static std::string m_dataPath;
    static std::vector<Playlist> m_playlistList;
};

}

#endif
