#ifndef _ALBUMMANAGER
#define _ALBUMMANAGER

#include "Album.h"
#include <string>
#include <vector>

namespace Music
{
	class AlbumManager
	{
	public:

		static void LoadData();
		static void SaveData();
		static void Setup(std::string dataPath);
		static void Cleanup();
		static void DisplayTable(std::vector<Album> albumList = m_albumList); //default para
		static bool IsValidId(size_t id);
		static size_t GetAlbumCount(); // size_t > int.
		static size_t CreateAlbum(std::string newTitle); //parameters are what is needed for a "new album"
		static void UpdateAlbum(size_t id, const Album& newAlbum); //Object: Album newAlbum... a reference(&)
		static Album GetAlbum(size_t id); //return type is Album bc this function returns a copy of an element from m_albumlist.
	private:
		static std::string m_dataPath;
		static std::vector<Album> m_albumList;

	};
}


#endif
