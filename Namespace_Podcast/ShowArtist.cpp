#include "ShowArtist.h"
#include <stdexcept>

namespace Podcast
{
	void Creator::SetCreatorId(int newId)
	{
		if (newId < 0)
		{
			throw std::invalid_argument("Invalid ID");
		}
		m_creatorId = newId;
	}
	void Creator::SetName(std::string newName)
	{
		m_name = newName;
	}
	void Creator::SetBio(std::string newBio)
	{
		m_bio = newBio;
	}

	int Creator::GetCreatorId()
	{
		return m_creatorId;
	}
	std::string Creator::GetName()
	{
		return m_name;
	}
	std::string Creator::GetBio()
	{
		return m_bio;
	}

	void Creator::AddPodcastId(int newPodcastId)
	{
		if (newPodcastId < 0)
		{
			throw std::invalid_argument("Invalid ID");
		}
		m_podcastIds.push_back(newPodcastId);
	}
	std::vector<int> Creator::GetPodcastIds()
	{
		return m_podcastIds;
	}
}
