#ifndef _EPISODE
#define _EPISODE
#include <iostream>
#include <vector>
#include <string>
namespace Podcast {
	class Episode {
	public:
		// implementing the set functions
		void SetEpisodeId(int episodeId);
		void SetTitle(std::string newTitle);
		void SetLength(int newLength);
		void SetPodcastId(int newPodcastId);
		void SetNextExpisodeId(int newExpisodeId);
		void SetPreviousId(int oldEpisodeId);

		// implementing the get functions
		int GetEpisodeId() const;
		std::string GetNewTitle() const;
		int GetLength() const;
		int GetPodcastId() const;
		int GetNextEposideId() const ;
		int GetPreviousEposideId() const;
		void Display() const;
		void AddEpisodeId(int newEpisodeId);
	private:
		int m_episodeId;
		std::vector<int>m_podcastListId;
		std::string m_title;
		int m_length;
		int m_podcastId;
		int m_nextEpisodeId;
		int m_previousEpisodeId;
		friend class EpisodeManager;

		// friend class Episode; // @Jniyonzima this isn't needed!
	};
}
#endif

