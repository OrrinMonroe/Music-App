#ifndef _CREATORMANAGER
#define _CREATORMANAGER

#include <iostream>
#include <string>
#include <vector>
#include "ShowArtist.h"

namespace Podcast
{
	using namespace std;

	class CreatorManager
	{
	public:
		static void LoadData();
		static void SaveData();
		static void Setup(string dataPath);
		static void Cleanup();
		static void DisplayTable(vector<Creator> creatorList = m_creatorList);
		static bool IsValidID(int id);
		static int GetCreatorCount();
		static int CreateCreator(string name);
		static void UpdateCreator(int id, const Creator& newCreator);
		static Creator GetCreator(size_t id);

	private:
		static string m_dataPath;
		static vector <Creator> m_creatorList;

	};

}


#endif
