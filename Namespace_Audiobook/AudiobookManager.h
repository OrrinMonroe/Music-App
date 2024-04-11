#ifndef AUDIOBOOKMANAGER_H
#define AUDIOBOOKMANAGER_H

#include <vector>
#include <string>
#include "ChapterManager.h"
#include "Audiobook.h"

namespace Audiobook
{

    class AudiobookManager
    {

    public:

        static void Setup(std::string dataPath);
        static void Cleanup();
        static void DisplayTable(const std::vector<Book>& bookList = m_bookList);
        static bool IsValidId(size_t id);
        static size_t GetBookCount();
        static int CreateBook(std::string name);
        static void UpdateBook(int id, Book newBook);
        static Book GetBook(size_t id);

        static void LoadData();
        static void SaveData();

    private:
        static std::string m_dataPath;
        static std::vector<Book> m_bookList;
    };

}

#endif 
