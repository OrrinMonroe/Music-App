#ifndef _PLAYLIST
#define _PLAYLIST

#include <string>
#include <vector>

namespace User
{

class Playlist
{
public:
    void SetId( int id );
    void SetName( std::string name );
    void SetUserCreatorId( int id );
    void AddTrackId( int newTrackId );
    void AddEpisodeId( int newEpisodeId );
    void AddChapterId( int newChapterId );

    int GetId() const;
    std::string GetName() const;
    int GetUserCreatorId() const;
    const std::vector<int>& GetTrackIds() const;
    const std::vector<int>& GetEpisodeIds() const;
    const std::vector<int>& GetChapterIds() const;
    void Display() const;

private:
    int m_playlistId;
    int m_userCreatorId;
    std::string m_name;
    std::vector<int> m_trackIds;
    std::vector<int> m_episodeIds;
    std::vector<int> m_chapterIds;

    friend class PlaylistManager;
};

}

#endif
