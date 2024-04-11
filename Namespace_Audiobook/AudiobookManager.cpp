#include "AudiobookManager.h"
#include <iostream>
#include <iomanip>

namespace Audiobook
{

    std::string AudiobookManager::m_dataPath;
    std::vector<Book> AudiobookManager::m_bookList;


    void AudiobookManager::Setup(std::string dataPath)
    {
        
        m_dataPath = dataPath;
        LoadData();

    }

    void AudiobookManager::Cleanup()
    {
        
        SaveData();

    }

    void AudiobookManager::LoadData() //to be implemented later
    {
      
    } 

    void AudiobookManager::SaveData() //to be implemented later
    {
        
    }

    size_t AudiobookManager::GetBookCount()
    {

        return m_bookList.size();

    }

    int AudiobookManager::CreateBook(std::string name)
    {
        //Create a newAudiobook object and add it to m_bookList.
        //Probably need to change what gets added once the audiobook.cpp is added

        Book newAudiobook;
        newAudiobook.SetID(m_bookList.size());
        newAudiobook.SetTitle(name);
      /*  newAudiobook.SetAuthorId(AuthorId);
        newAudiobook.SetChapterId(chapterId);*/
        m_bookList.push_back(newAudiobook);
        return newAudiobook.GetID();

    }

    void AudiobookManager::UpdateBook(int id, Book newAudiobook)
    {
        if (id < 0 || id >= m_bookList.size())
        {

            throw std::invalid_argument("Invalid ID!");

        }
        m_bookList[id] = newAudiobook;

    }

    Book AudiobookManager::GetBook(size_t id)
    {

        if ( id < 0 || id >= m_bookList.size() )
        {

            throw std::invalid_argument("Invalid ID!");

        }

        return m_bookList[id];

    }

    bool AudiobookManager::IsValidId(size_t id)
    {

        return ( id >= 0 && id < m_bookList.size() );

    }

    //This function will need work
    void AudiobookManager::DisplayTable(const std::vector<Book>& bookList /* = m_bookList*/)
    {
        std::cout << std::left;
        std::cout
            << std::setw(5) << "ID"
            << std::setw(25) << "Title"
            << std::endl << std::string(80, '-') << std::endl;

        //This should be something else.
        for (auto& book : bookList)
        {
            std::cout
                << std::setw(5) << book.GetID()
                << std::setw(10) << book.GetTitle()
                << std::endl;
        }
        
        
    }

}