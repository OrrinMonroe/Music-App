#ifndef _AUDIOBOOK
#define _AUDIOBOOK

#include <string>
#include <vector>

namespace Audiobook
{

class Book
{
public:
	void SetID(int newId);
	int GetID() const;
	std::string GetTitle() const;
	void SetTitle(std::string newTitle);
	void AddAuthorID(int authorID);
	void AddChapterID(int chapterID);
	std::vector<int> GetAuthorID() const;
	std::vector<int> GetChapterID() const;

	void Display() const;

private:
	int id = -1;
	std::string m_title;
	std::vector<int> m_authorID;
	std::vector<int> m_chapterID;

	friend class AudiobookManager;
};

}

#endif
