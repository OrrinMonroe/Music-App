#ifndef _EPISODE_MANAGER
#define _EPISODE_MANAGER
#include <string>
#include <vector>
#include "Episode.h"
namespace Podcast {
	class EpisodeManager {
	public:

		static  void LoadData();
		static void SaveData();
		static void Setup(std::string dataPath);
		static void Cleanup();
		static void DisplayTable( std::vector<Episode>& episode = m_episodeList);
		static bool IsValidId(size_t id);

		static size_t  GetEpisodeCount();
		
		static int CreateEpisode(std::string name);
		static void UpdateEpisode(size_t id, const Podcast::Episode& episode);
		static Episode GetEpisode(size_t id);


	private:
		static std::vector<Episode> m_episodeList;
		static std::string m_dataPath;
		
	};
}
#endif // !_EpisodeManager
