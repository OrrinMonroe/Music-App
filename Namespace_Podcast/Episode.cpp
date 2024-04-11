# include "Episode.h"
namespace Podcast
{
    void Episode::SetEpisodeId(int episodeId)
    {
        if (episodeId < 0) {
            throw std::invalid_argument("The Episode Id Can't be less than zero");
        }
        else {
            m_episodeId = episodeId;
        }

    }

    void Episode::SetTitle(std::string newtitle)
    {
        m_title = newtitle;
    }

    void Episode::SetLength(int new_length)
    {

        m_length = new_length;
    }
    void Episode::SetPodcastId(int newId)
    {
        if (newId < 0) {
            throw std::invalid_argument("The Podcast Id Can't be less than zero");
        }
        else {
            m_podcastId = newId;
        }

    }

    void Episode:: SetNextExpisodeId(int newExpisodeId)
    {
        if (newExpisodeId < 0) {
            throw std::invalid_argument("The next Episode Id Can't be less than zero");
        }
        else {
            m_nextEpisodeId = newExpisodeId;
        }

    }

    void Episode::SetPreviousId(int episodeId)
    {
        if (episodeId < 0) {
            throw std::invalid_argument("The the previous Episode Id Can't be less than zero");
        }
        else {
            m_previousEpisodeId= episodeId;
        }

    }
    int Episode::GetEpisodeId() const {
        return  m_episodeId;
    }
    std::string Episode::GetNewTitle() const {
        return m_title;
    }
    int Episode::GetLength() const {
        return m_length;
    }
    int Episode::GetPodcastId() const {
        return m_podcastId;
    }
    int Episode::GetNextEposideId()  const {
        return m_nextEpisodeId;

    }
    int Episode::GetPreviousEposideId() const{
        return m_previousEpisodeId;

    }
    void Episode::Display() const {
       
        std::cout << "POPDCAST" << std::endl;
        std::cout << "* EPISODE  ID:       " << m_episodeId << std::endl;
        std::cout << "* Episode Title :     " << m_title << std::endl;
        std::cout << "* LENGTH OF EPISODE   " << m_length << std::endl;
        std::cout << "* PODCAST ID:         " <<m_podcastId <<std::endl;
        std::cout << "* NEXT EPISODE ID     " << m_nextEpisodeId<<std::endl;
        std::cout << "* PREVIOUS EPISODE ID " << m_previousEpisodeId <<std::endl;
             
        for (auto& id : m_podcastListId) {
            std::cout << " * " <<  id << std::endl;
        }
        std::cout << std::endl;
    } // end of my display function
    void Episode:: AddEpisodeId(int newEpisodeId)
    {
        if (newEpisodeId < 0)
        {
            throw std::invalid_argument("Invalid episode id");
        }
        m_podcastListId.push_back(newEpisodeId);
    }


}
