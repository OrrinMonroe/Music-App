#ifndef _TRACKMANAGER
#define _TRACKMANAGER

#include <string>
#include <vector>
#include "Track.h"

namespace Music
{

class TrackManager
{
public:
	static void LoadData();
	static void SaveData();
	static void Setup(std::string dataPath);
	static void Cleanup();
	static void DisplayTable( const std::vector<Track>& userList = m_trackList );
	static bool IsValidId( size_t id );
	static size_t GetTrackCount();
	static int CreateTrack( std::string name );
	static void UpdateTrack(int id, const Track& newTrack);
	static Track GetTrack(size_t id);
	
private:
	static std::string m_dataPath;
	static std::vector<Track> m_trackList;
};
}
#endif