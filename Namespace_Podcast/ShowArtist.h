#ifndef _SHOWARTIST
#define _SHOWARTIST

#include <string>
#include <vector>

namespace Podcast
{

class Creator
{
public:
	void SetCreatorId(int newId);
	void SetName(std::string newName);
	void SetBio(std::string newBio);

	int GetCreatorId();
	std::string GetName();
	std::string GetBio();

	void AddPodcastId(int newPodcastId);
	std::vector<int> GetPodcastIds();

private:
	int m_creatorId;
	std::string m_name;
	std::string m_bio;
	std::vector<int> m_podcastIds;
};

}

#endif
