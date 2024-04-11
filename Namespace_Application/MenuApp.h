#ifndef _MENU_APP
#define _MENU_APP

#include "../Namespace_Music/MusicArtist.h"
#include "../Namespace_Music/Track.h"
#include "../Namespace_Music/Album.h"

#include "../Namespace_Podcast/Show.h"
#include "../Namespace_Podcast/Episode.h"
#include "../Namespace_Podcast/ShowArtist.h"

#include  "../Namespace_Audiobook/Audiobook.h"
#include "../Namespace_Audiobook/BookArtist.h"
#include "../Namespace_Audiobook/Chapter.h"

namespace Application
{

//! Program menu-based interface
class MenuApplication
{
public:
    void Run();
    void Setup();
    void Cleanup();

private:
    void Menu_Main();

    /*************************************************************************** USER NAMESPACE */
    void Menu_User_User_Add();
    void Menu_User_User_Edit();
    void Menu_User_User_View();

    void Menu_User_Playlist_Add();
    void Menu_User_Playlist_Edit();
    void Menu_User_Playlist_View();
    /*************************************************************************** MUSIC NAMESPACE */
    void Menu_Music_Album_Add();
    void Menu_Music_Album_Edit();
    void Menu_Music_Album_View();

    std::vector<Music::MusicArtist> m_artists;
    void Menu_Music_Artist_Add();
    void Menu_Music_Artist_Edit();
    void Menu_Music_Artist_View();

    void Menu_Music_Tracks_Add();
    void Menu_Music_Tracks_Edit();
    void Menu_Music_Tracks_View();
    /*************************************************************************** AUDIOBOOK NAMESPACE */
    //std::vector<Audiobook::Audiobook> m_audiobooks;
    void Menu_Audiobook_Book_Add();
    void Menu_Audiobook_Book_Edit();
    void Menu_Audiobook_Book_View();

    std::vector<Audiobook::Author> m_authors;
    void Menu_Audiobook_Author_Add();
    void Menu_Audiobook_Author_Edit();
    void Menu_Audiobook_Author_View();

    std::vector<Audiobook::Chapter> m_chapters;
    void Menu_Audiobook_Chapter_Add();
    void Menu_Audiobook_Chapter_Edit();
    void Menu_Audiobook_Chapter_View();
    /*************************************************************************** PODCAST NAMESPACE */
    std::vector<Podcast::Show> m_shows;
    void Menu_Podcast_Show_Add();
    void Menu_Podcast_Show_Edit();
    void Menu_Podcast_Show_View();

    void Menu_Podcast_Creator_Add();
    void Menu_Podcast_Creator_Edit();
    void Menu_Podcast_Creator_View();

    void Menu_Podcast_Episodes_Add();
    void Menu_Podcast_Episodes_Edit();
    void Menu_Podcast_Episodes_View();
};

}

#endif
