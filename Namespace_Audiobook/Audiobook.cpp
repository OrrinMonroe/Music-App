#include <iostream>
#include "Audiobook.h"
#include <vector>
#include <string>

using namespace std;

namespace Audiobook {

	//set IDs
	void Book::SetID(int newId)  {
		if (newId < 0) {
			throw std::invalid_argument("ID can't be negative.");
		}
		id = newId;
	}

	void Book::SetTitle(std::string newTitle)
	{
		m_title = newTitle;
	}

	void Book::AddAuthorID(int newAuthorId)
	{
        // TODO @capplema : try/catch go OUTSIDE THE FUNCTION, during the function call.
        // Only the throw statement belongs in here.
		if (newAuthorId < 0)
		{
			throw invalid_argument("Can't be negative");
		}
		else m_authorID.push_back(newAuthorId);
	}


	void Book::AddChapterID(int newChapterId)
	{
        // TODO @capplema : try/catch go OUTSIDE THE FUNCTION, during the function call.
        // Only the throw statement belongs in here.
		if (newChapterId < 0)
		{
			throw invalid_argument("Can't be negative");
		}
		else m_chapterID.push_back(newChapterId);
	}


	//retrieve info
	int Book::GetID() const
	{
		return id;
	}

	string Book::GetTitle() const
	{
		return m_title;
	}

	vector<int> Book::GetAuthorID() const
	{
		return m_authorID;
	}

	vector<int> Book::GetChapterID() const
	{
		return m_chapterID;
	}

	void Book::Display() const
	{
		std::cout << "Audiobook" << std::endl;
		std::cout << "* Audiobook ID: " << id << std::endl;
		std::cout << "* Title:    " << m_title << std::endl;
		std::cout << "* Author IDs:" << std::endl;
		for (auto& id : m_authorID)
		{
			std::cout << "  * " << id << std::endl;
		}
		std::cout << "* Chapter IDs:" << std::endl;
		for (auto& id : m_chapterID)
		{
			std::cout << "  * " << id << std::endl;
		}

		std::cout << std::endl;
	}

}
