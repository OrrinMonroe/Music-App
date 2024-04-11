#include "MenuApp.h"
#include "../Namespace_Music/TrackManager.h"

#include "../Namespace_Utilities/Logger.h"
#include "../Namespace_Utilities/Helper.h"
#include "../Namespace_Utilities/ScreenDrawer.h"
#include "../Namespace_Podcast/Episode.h"
#include "../Namespace_Audiobook/Audiobook.h"
#include "../Namespace_Music/MusicArtist.h"

#include "../Namespace_User/UserManager.h"
#include "../Namespace_User/PlaylistManager.h"
#include "../Namespace_Audiobook/AudiobookManager.h"
#include "../Namespace_Podcast/EpisodeManager.h"
#include "../Namespace_Podcast/CreatorManager.h"

#include "../Namespace_Music/AlbumManager.h"

namespace Application
{

void MenuApplication::Setup() // LATEST VERSION
{
    Utilities::Logger::Setup( true );
    Utilities::ScreenDrawer::Setup( 80, 20 );
    User::UserManager::Setup( "../data/users/users.csv" );
    User::PlaylistManager::Setup( "../data/users/playlists.csv" );
    Music::TrackManager::Setup("../data/music/tracks.csv");
    Music::AlbumManager::Setup("../data/music/albums.csv"); //??
    Audiobook::AudiobookManager::Setup("../data/users/audiobooks.csv");
    Podcast::EpisodeManager::Setup("../data/podcasts/episodes.csv");
    Podcast::CreatorManager::Setup("../data/podcasts/creators.csv");
}

void MenuApplication::Cleanup() // LATEST VERSION
{
    User::UserManager::Cleanup();
    Utilities::ScreenDrawer::Teardown();
    User::PlaylistManager::Cleanup();
    Music::AlbumManager::Cleanup();
    Utilities::Logger::Cleanup();
    Music::TrackManager::Cleanup();
    Audiobook::AudiobookManager::Cleanup();
    Podcast::EpisodeManager::Cleanup();
    Podcast::CreatorManager::Cleanup();
}

void MenuApplication::Run()
{
    Setup();
    Menu_Main();
    Cleanup();
}

void MenuApplication::Menu_Main()
{
    std::cout << std::string( 40, '\n' );
    bool menuDone = false;
    while ( !menuDone )
    {
        std::string command;

        // MENU 1
        Utilities::ScreenDrawer::DrawBackground();
        Utilities::ScreenDrawer::DrawLine( 0, 0, 80, 0, ' ', "black", "yellow" );
        Utilities::ScreenDrawer::Set( 0, 0, "Team Mango", "black", "yellow" );
        Utilities::ScreenDrawer::DrawWindow( "MAIN MENU", 2, 2, 77, 20-3 );

        Utilities::ScreenDrawer::Set( 5,  4,    "[1] ADD", "white", "black" );
        Utilities::ScreenDrawer::Set( 25, 4,    "[2] EDIT", "white", "black" );
        Utilities::ScreenDrawer::Set( 45, 4,    "[3] VIEW", "white", "black" );
        Utilities::ScreenDrawer::Set( 6, 20-5,  "[0] Exit", "white", "black" );

        Utilities::ScreenDrawer::Draw();
        int commandInt;
        std::cin >> commandInt;
        if      ( commandInt == 0 ) { menuDone = true; continue; }
        if      ( commandInt == 1 ) { command = "ADD"; }
        else if ( commandInt == 2 ) { command = "EDIT"; }
        else if ( commandInt == 3 ) { command = "VIEW"; }

        // MENU 2
        Utilities::ScreenDrawer::DrawBackground();
        Utilities::ScreenDrawer::DrawLine( 0, 0, 80, 0, ' ', "black", "yellow" );
        Utilities::ScreenDrawer::Set( 0, 0, "Team Mango", "black", "yellow" );
        Utilities::ScreenDrawer::DrawWindow( "MAIN MENU", 2, 2, 77, 20-3 );
        Utilities::ScreenDrawer::DrawLine( 3, 4, 76, 4, ' ', "blue", "blue" );
        Utilities::ScreenDrawer::Set( 4, 4, command, "white", "blue" );

        Utilities::ScreenDrawer::Set( 4,  5,    "USERS", "white", "black" );
        Utilities::ScreenDrawer::Set( 5,  6,    "[1] USER", "white", "black" );
        Utilities::ScreenDrawer::Set( 5,  7,    "[2] PLAYLIST", "white", "black" );

        Utilities::ScreenDrawer::Set( 24, 5,    "AUDIOBOOKS", "white", "black" );
        Utilities::ScreenDrawer::Set( 25,  6,    "[3] AUDIOBOOK", "white", "black" );
        Utilities::ScreenDrawer::Set( 25,  7,    "[4] AUTHOR", "white", "black" );
        Utilities::ScreenDrawer::Set( 25,  8,    "[5] CHAPTER", "white", "black" );

        Utilities::ScreenDrawer::Set( 44, 5,    "PODCASTS", "white", "black" );
        Utilities::ScreenDrawer::Set( 45,  6,    "[6] PODCAST", "white", "black" );
        Utilities::ScreenDrawer::Set( 45,  7,    "[7] CREATOR", "white", "black" );
        Utilities::ScreenDrawer::Set( 45,  8,    "[8] EPISODE", "white", "black" );

        Utilities::ScreenDrawer::Set( 64, 5,    "MUSIC", "white", "black" );
        Utilities::ScreenDrawer::Set( 65,  6,    "[9]  ALBUM", "white", "black" );
        Utilities::ScreenDrawer::Set( 65,  7,    "[10] ARTIST", "white", "black" );
        Utilities::ScreenDrawer::Set( 65,  8,    "[11] TRACK", "white", "black" );

        Utilities::ScreenDrawer::Set( 6, 20-5,  "[0] GO BACK", "white", "black" );

        Utilities::ScreenDrawer::Draw();

        std::cin >> commandInt;
        if ( commandInt == 0 ) { continue; }
        switch( commandInt )
        {
          case 1: command += " USERS - User"; break;
          case 2: command += " USERS - Playlist"; break;
          case 3: command += " AUDIOBOOKS - Audiobook"; break;
          case 4: command += " AUDIOBOOKS - Author"; break;
          case 5: command += " AUDIOBOOKS - Chapter"; break;
          case 6: command += " PODCASTS - Podcast"; break;
          case 7: command += " PODCASTS - Creator"; break;
          case 8: command += " PODCASTS - Episode"; break;
          case 9: command += " MUSIC - Album"; break;
          case 10: command += " MUSIC - Artist"; break;
          case 11: command += " MUSIC - Track"; break;
        }

        /*************************************************************************** USER NAMESPACE */
        if      ( command == "ADD USERS - User"  )              { Menu_User_User_Add(); }
        else if ( command == "EDIT USERS - User" )              { Menu_User_User_Edit(); }
        else if ( command == "VIEW USERS - User" )              { Menu_User_User_View(); }
        else if ( command == "ADD USERS - Playlist"   )         { Menu_User_Playlist_Add(); }
        else if ( command == "EDIT USERS - Playlist"  )         { Menu_User_Playlist_Edit(); }
        else if ( command == "VIEW USERS - Playlist"  )         { Menu_User_Playlist_View(); }
        /*************************************************************************** MUSIC NAMESPACE */
        else if ( command == "ADD MUSIC - Album"  )             { Menu_Music_Album_Add(); }
        else if ( command == "EDIT MUSIC - Album" )             { Menu_Music_Album_Edit(); }
        else if ( command == "VIEW MUSIC - Album" )             { Menu_Music_Album_View(); }
        else if ( command == "ADD MUSIC - Artist"  )            { Menu_Music_Artist_Add(); }
        else if ( command == "EDIT MUSIC - Artist" )            { Menu_Music_Artist_Edit(); }
        else if ( command == "VIEW MUSIC - Artist" )            { Menu_Music_Artist_View(); }
        else if ( command == "ADD MUSIC - Track"  )             { Menu_Music_Tracks_Add(); }
        else if ( command == "EDIT MUSIC - Track" )             { Menu_Music_Tracks_Edit(); }
        else if ( command == "VIEW MUSIC - Track" )             { Menu_Music_Tracks_View(); }
        /*************************************************************************** AUDIOBOOK NAMESPACE */
        else if ( command == "ADD AUDIOBOOKS - Audiobook"  )    { Menu_Audiobook_Book_Add(); }
        else if ( command == "EDIT AUDIOBOOKS - Audiobook" )    { Menu_Audiobook_Book_Edit(); }
        else if ( command == "VIEW AUDIOBOOKS - Audiobook" )    { Menu_Audiobook_Book_View(); }
        else if ( command == "ADD AUDIOBOOKS - Author"  )       { Menu_Audiobook_Author_Add(); }
        else if ( command == "EDIT AUDIOBOOKS - Author" )       { Menu_Audiobook_Author_Edit(); }
        else if ( command == "VIEW AUDIOBOOKS - Author" )       { Menu_Audiobook_Author_View(); }
        else if ( command == "ADD AUDIOBOOKS - Chapter"  )      { Menu_Audiobook_Chapter_Add(); }
        else if ( command == "EDIT AUDIOBOOKS - Chapter" )      { Menu_Audiobook_Chapter_Edit(); }
        else if ( command == "VIEW AUDIOBOOKS - Chapter" )      { Menu_Audiobook_Chapter_View(); }
        /*************************************************************************** PODCAST NAMESPACE */
        else if ( command == "ADD PODCASTS - Podcast"  )        { Menu_Podcast_Show_Add(); }
        else if ( command == "EDIT PODCASTS - Podcast" )        { Menu_Podcast_Show_Edit(); }
        else if ( command == "VIEW PODCASTS - Podcast" )        { Menu_Podcast_Show_View(); }
        else if ( command == "ADD PODCASTS - Creator"  )        { Menu_Podcast_Creator_Add(); }
        else if ( command == "EDIT PODCASTS - Creator" )        { Menu_Podcast_Creator_Edit(); }
        else if ( command == "VIEW PODCASTS - Creator" )        { Menu_Podcast_Creator_View(); }
        else if ( command == "ADD PODCASTS - Episode"  )        { Menu_Podcast_Episodes_Add(); }
        else if ( command == "EDIT PODCASTS - Episode" )        { Menu_Podcast_Episodes_Edit(); }
        else if ( command == "VIEW PODCASTS - Episode" )        { Menu_Podcast_Episodes_View(); }
    }
}


/****************************************************************************************** USER NAMESPACE */
/*                                                                                                    User */
void MenuApplication::Menu_User_User_Add() // @Rsingh13
{
    Utilities::Helper::SubHeader( "ADD > USERS > USER" );

    std::cout << "Enter name of user:" << std::endl;
    std::string name = Utilities::Helper::GetStringLine();

    int newId = User::UserManager::CreateUser( name );
    if ( newId >= 0 )
    {
        std::cout << "New user created at ID " << newId << std::endl;
    }

    User::UserManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_User_User_Edit() // @Rsingh13
{
    Utilities::Helper::SubHeader( "EDIT > USERS > USER" );

    if ( User::UserManager::GetUserCount() == 0 )
    {
        std::cout << "There are no users to edit!" << std::endl;
        Utilities::Helper::Pause();
        return;
    }

    User::UserManager::DisplayTable();

    std::cout << std::endl << "Edit which ID? ";
    int id;
    std::cin >> id;

    User::User userCopy;
    try
    {
        userCopy = User::UserManager::GetUser( id );
    }
    catch( const std::invalid_argument& ex )
    {
        std::cerr << "ERROR: " << ex.what() << std::endl;
        return;
    }

    bool menuDone = false;
    while ( !menuDone )
    {
        Utilities::Helper::SubHeader( "Editing " + userCopy.GetName() + "..." );

        userCopy.Display();

        std::string choice = Utilities::Helper::ShowMenuGetString(
        {
            "Go back",
            "Edit name",
            "Add playlist ID"
        },
        false, false
        );

        if ( choice == "Go back" )
        {
            menuDone = true;
        }
        else if ( choice == "Edit name" )
        {
            std::cout << "Enter new name: ";
            std::string name = Utilities::Helper::GetStringLine();
            userCopy.SetName( name );
        }
        else if ( choice == "Add playlist ID" )
        {
            std::cout << "Available playlists:" << std::endl;

            if ( User::PlaylistManager::GetPlaylistCount() == 0 )
            {
                std::cout << "There are no playlists to add!" << std::endl;
                Utilities::Helper::Pause();
                continue;
            }

            User::PlaylistManager::DisplayTable();

            int playlistId;
            std::cout << std::endl << "Entert playlist ID: ";
            std::cin >> playlistId;

            while ( User::PlaylistManager::IsValidId( playlistId ) == false )
            {
                std::cout << "That ID is not valid. Please try again: ";
                std::cin >> playlistId;
            }

            try
            {
                userCopy.AddPlaylistId( playlistId );
            }
            catch( const std::invalid_argument& ex )
            {
                std::cout << "ERROR! " << ex.what() << std::endl;
            }
        }
    }

    User::UserManager::UpdateUser( id, userCopy );
    User::UserManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_User_User_View() // @Rsingh13
{
    Utilities::Helper::SubHeader( "VIEW > USERS > USER" );
    User::UserManager::DisplayTable();
    Utilities::Helper::Pause();
}

/****************************************************************************************** USER NAMESPACE */
/*                                                                                                Playlist */
void MenuApplication::Menu_User_Playlist_Add() // @Rsingh13
{
    Utilities::Helper::SubHeader( "ADD > USERS > PLAYLIST" );

    std::cout << "Enter name of playlist:" << std::endl;
    std::string name = Utilities::Helper::GetStringLine();

    int playlistCreatorId = -1;

    if ( User::UserManager::GetUserCount() > 0 )
    {
        User::UserManager::DisplayTable();
        std::cout << "Enter ID of playlist creator: ";
        std::cin >> playlistCreatorId;

        while ( User::UserManager::IsValidId( playlistCreatorId ) == false )
        {
            std::cout << "That ID is not valid. Please try again: ";
            std::cin >> playlistCreatorId;
        }
    }

    int newId = User::PlaylistManager::CreatePlaylist( name, playlistCreatorId );
    if ( newId >= 0 )
    {
        std::cout << "New playlist created at ID " << newId << std::endl;
    }

    User::PlaylistManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_User_Playlist_Edit() // @Rsingh13
{
    Utilities::Helper::SubHeader( "EDIT > USERS > PLAYLIST" );
    User::PlaylistManager::DisplayTable();

    if ( User::PlaylistManager::GetPlaylistCount() == 0 )
    {
        std::cout << "There are no playlists to edit!" << std::endl;
        Utilities::Helper::Pause();
        return;
    }

    std::cout << std::endl << "Edit which ID? ";
    int id;
    std::cin >> id;

    User::Playlist playlistCopy;
    try
    {
        playlistCopy = User::PlaylistManager::GetPlaylist( id );
    }
    catch( const std::invalid_argument& ex )
    {
        std::cerr << "ERROR: " << ex.what() << std::endl;
        return;
    }

    bool menuDone = false;
    while ( !menuDone )
    {
        Utilities::Helper::SubHeader( "Editing " + playlistCopy.GetName() + "..." );

        playlistCopy.Display();

        std::string choice = Utilities::Helper::ShowMenuGetString(
        {
            "Go back",
            "Edit name",
            "Add MUSIC track ID",
            "Add PODCAST episode ID",
            "Add AUDIOBOOK chapter ID"
        },
        true, false
        );

        if ( choice == "Go back" )
        {
            menuDone = true;
        }
        else if ( choice == "Edit name" )
        {
            std::string name;
            std::cout << "Enter new name: ";
            getline( std::cin, name );
            playlistCopy.SetName( name );
        }
        else if ( choice == "Add MUSIC track ID" )
        {
            std::cout << "Sorry, this isn't implemented yet." << std::endl;
            Utilities::Helper::Pause();
        }
        else if ( choice == "Add PODCAST episode ID" )
        {
            std::cout << "Sorry, this isn't implemented yet." << std::endl;
            Utilities::Helper::Pause();
        }
        else if ( choice == "Add AUDIOBOOK chapter ID" )
        {
            std::cout << "Sorry, this isn't implemented yet." << std::endl;
            Utilities::Helper::Pause();
        }
    }

    User::PlaylistManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_User_Playlist_View() // @Rsingh13
{
    Utilities::Helper::SubHeader( "VIEW > USERS > PLAYLIST" );
    User::PlaylistManager::DisplayTable();
    Utilities::Helper::Pause();
}

/****************************************************************************************** MUSIC NAMESPACE */
/*                                                                                                    Album */
void MenuApplication::Menu_Music_Album_Add() // @aliuw
{
	Utilities::Helper::SubHeader( "ADD > MUSIC > ALBUM" );

    std::cout << "Title of Album: ";
    std::cin.ignore();
    std::string title = Utilities::Helper::GetStringLine(); //has the cin.ignore()
    int newId = Music::AlbumManager::CreateAlbum(title);

    if (newId >= 0)
    {
        std::cout << "New album added at ID " << newId << std::endl;
    }

    Music::AlbumManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_Music_Album_Edit() // @aliuw
{
	Utilities::Helper::SubHeader( "EDIT > MUSIC > ALBUM" );

    if (Music::AlbumManager::GetAlbumCount() == 0)
    {
        std::cout << "There are no albums to edit." << std::endl;
        Utilities::Helper::Pause();
        return; //?
    }

    Music::AlbumManager::DisplayTable();

    std::cout << "Edit which Album ID? ";
    int id;
    std::cin >> id;

    Music::Album albumCopy; //namesapce: Music, class: Album, object: albumCopy
    try
    {
        albumCopy = Music::AlbumManager::GetAlbum(id);
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << "ERROR: " << ex.what() << std::endl;
        return;
    }
    //end try/catch

    bool menuDone = false;
    while (!menuDone)
    {
        Utilities::Helper::SubHeader("Editing " + albumCopy.GetTitle() + "...");
        albumCopy.Display();

        std::string choice = Utilities::Helper::ShowMenuGetString(
            {
                "Go back",
                "Edit Album Title",
                "Add Artist ID",
                "Add Track ID"
            },
            true, false //?
        );
        if (choice == "Go back")
        {
            menuDone = true;
        }
        else if (choice == "Edit Album Title")
        {


            std::string title;
            std::cout << "Enter new Album Title: ";
            std::cin.ignore();
            getline(std::cin, title);
            albumCopy.SetTitle(title);

        }
        else if (choice == "Add Artist ID")
        {
            int artistId;
            std::cout << "Enter an Artist ID: ";
            std::cin >> artistId;

            try
            {
                albumCopy.AddArtistId(artistId);
            }
            catch (const std::invalid_argument& ex)
            {
                std::cerr << "ERROR: " << ex.what() << std::endl;
                return;
            }//end try/catch
        }
        else if (choice == "Add Track ID")
        {
            int trackId;
            std::cout << "Enter a Track ID: ";
            std::cin >> trackId;

            try
            {
                albumCopy.AddTrackId(trackId);
            }
            catch (const std::invalid_argument& ex)
            {
                std::cerr << "ERROR: " << ex.what() << std::endl;
                return;
            }//end try/catch
        }
    }

    Music::AlbumManager::UpdateAlbum( id, albumCopy ); // << Added this
    Music::AlbumManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_Music_Album_View() // @aliuw
{
    Utilities::Helper::SubHeader("VIEW > MUSIC > ALBUM");

    Music::AlbumManager::DisplayTable();
    Utilities::Helper::Pause();
}

/****************************************************************************************** MUSIC NAMESPACE */
/*                                                                                                   Artist */
void MenuApplication::Menu_Music_Artist_Add() // @giseller30
{
    Utilities::Helper::Header("CREATE ARTIST");

    std::string artist;
    std::cout << "Enter name of artist: ";
    std::cin.ignore();
    getline(std::cin, artist);

    Music::MusicArtist newArtist;
    newArtist.ArtistName(artist);
    // newArtist.ArtistId(m_users.size()); // << Incorrect
    newArtist.ArtistId(m_artists.size());
    m_artists.push_back(newArtist);
}

void MenuApplication::Menu_Music_Artist_Edit() // @giseller30
{
    Utilities::Helper::Header("EDIT ARTIST");
    std::cout << "Here are the available authors: ";

    for (size_t i = 0; i < m_artists.size(); i++)
    {
        std::cout << i << ". " << m_artists[i].GetName() << ", ALBUMS: " << m_artists[i].GetAlbumIds().size() << std::endl;
    }

    std::cout << std::endl << "Edit which ID? ";
    int id;
    std::cin >> id;
    try
    {
        m_artists[id].ArtistId(id);
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << "ERROR! " << ex.what() << std::endl;
    }

    std::cout << "Do which of the following? ";
    std::cout << std::endl << "1. Edit artist" << std::endl << "2. Add album ID" << std::endl;
    int choice;

    std::cin >> choice;

    if (choice == 1)
    {
        std::string name;
        std::cout << "Enter new artist: ";
        getline(std::cin, name);
        m_artists[id].ArtistName(name);
    }
    else if (choice == 2)
    {
        int albumId;
        std::cout << "Enter album ID: ";
        std::cin >> albumId;

        try
        {
            m_artists[id].AddAlbumId(albumId);
        }
        catch (const std::invalid_argument& ex)
        {
            std::cout << "ERROR! " << ex.what() << std::endl;
        }
    }
}

void MenuApplication::Menu_Music_Artist_View() // @giseller30
{
    Utilities::Helper::Header("VIEW ARTISTS");
    for (size_t i = 0; i < m_artists.size(); i++)
    {
        std::cout << i << ". " << m_artists[i].GetName() << ", ALBUMS: " << m_artists[i].GetAlbumIds().size() << std::endl;
    }
}

/****************************************************************************************** MUSIC NAMESPACE */
/*                                                                                                    Track */
void MenuApplication::Menu_Music_Tracks_Add() // @omonroe
{
//    Utilities::Helper::Header("Create Track");
//
//    std::string title;
//    std::cout << "Enter title of track: ";
//    std::cin.ignore();
//    getline(std::cin, title);
//
//    Music::Track newTitle;
//    newTitle.setTitle(title);
//
//    try
//    {
//        newTitle.setTrackId(m_tracks.size());
//        m_tracks.push_back(newTitle);
//        std::cout << "New track created at ID " << newTitle.getTrackId() << std::endl;
//    }
//    catch (const std::invalid_argument& ex)
//    {
//        std::cout << "ERROR: " << ex.what() << std::endl;
//    }

    Utilities::Helper::SubHeader( "ADD > USERS > USER" );

    std::cout << "Enter name of user:" << std::endl;
    std::string name = Utilities::Helper::GetStringLine();

    int newId = Music::TrackManager::CreateTrack( name );
    if ( newId >= 0 )
    {
        std::cout << "New track created at ID " << newId << std::endl;
    }

    Music::TrackManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_Music_Tracks_Edit() // @omonroe
{
//    bool done = false;
//    while (!done)
//    {
//        Utilities::Helper::Header("Update Tracks");
//
//        int id;
//        std::cout << "Edit which ID?: ";
//        std::cin.ignore();
//        std::cin >> id;
//        std::cout << std::endl;
//
//        std::cout << "Do which of the following?" << std::endl;
//        std::cout << "0. Go Back" << std::endl;
//        std::cout << "1. Set TRACK name" << std::endl;
//        std::cout << "2. Set TRACK length" << std::endl;
//        std::cout << "3. Set next TRACK ID" << std::endl;
//        std::cout << "4. Set previous Track ID" << std::endl;
//        std::cout << std::endl;
//
//        int choice;
//        std::cout << ">> ";
//        std::cin >> choice;
//
//        if (choice == 1)
//        {
//            std::cout << "Enter a new track name: ";
//            std::string name;
//            std::cin.ignore();
//            getline(std::cin, name);
//            m_tracks[id].setTitle(name);
//
//        }
//        else if (choice == 2)
//        {
//            std::cout << "Enter a new track length in seconds: ";
//            int length;
//            std:: cin >> length;
//            try
//            {
//                m_tracks[id].setLength(length);
//            }
//            catch(const std::invalid_argument& ex)
//            {
//                std::cout << "ERROR! " << ex.what() << std::endl;
//            }
//        }
//        else if (choice == 3)
//        {
//            std::cout << "Enter the next Track ID: ";
//            int nxt;
//            std::cin >> nxt;
//            try
//            {
//                m_tracks[id].setNextTrackId(nxt);
//            }
//            catch (const std::invalid_argument& ex)
//            {
//                std::cout << "ERROR! " << ex.what() << std::endl;
//            }
//
//        }
//        else if (choice == 4)
//        {
//            std::cout << "Enter the previous Track ID: ";
//            int pre;
//            std::cin >> pre;
//            try
//            {
//                m_tracks[id].setPrevTrackId(pre);
//            }
//            catch (const std::invalid_argument& ex)
//            {
//                std::cout << "ERROR! " << ex.what() << std::endl;
//            }
//
//        }
//        else if (choice == 0)
//        {
//            break;
//        }
//        else
//        {
//            std::cout << "INVALID entry please try again: ";
//            int choice;
//            std::cout << ">> ";
//            std::cin >> choice;
//        }
//    }

    Utilities::Helper::SubHeader( "EDIT > MUSIC > TRACK" );

    if ( Music::TrackManager::GetTrackCount() == 0 )
    {
        std::cout << "There are no tracks to edit!" << std::endl;
        Utilities::Helper::Pause();
        return;
    }

    Music::TrackManager::DisplayTable();

    std::cout << std::endl << "Edit which ID? ";
    int id;
    std::cin >> id;

    Music::Track trackCopy;
    try
    {
        trackCopy = Music::TrackManager::GetTrack( id );
    }
    catch( const std::invalid_argument& ex )
    {
        std::cerr << "ERROR: " << ex.what() << std::endl;
        return;
    }

    bool menuDone = false;
    while ( !menuDone )
    {
        Utilities::Helper::SubHeader( "Editing " + trackCopy.getTitle() + "..." );

        trackCopy.Display();

        std::string choice = Utilities::Helper::ShowMenuGetString(
        {
            "Go back",
            "Edit title",
            "Edit length",
            "Set album ID",
            "Set next track ID",
            "Set previous track ID"
        },
        false, false
        );

        if ( choice == "Go back" )
        {
            menuDone = true;
        }
        else if ( choice == "Edit title" )
        {
            std::cout << "Enter new name: ";
            std::string name = Utilities::Helper::GetStringLine();
            trackCopy.setTitle( name );
        }
        else if ( choice == "Edit length" )
        {
            std::cout << "Enter new length: ";
            int length;
            std::cin >> length;
            trackCopy.setLength( length );
        }
        else if ( choice == "Set album ID" )
        {
            Music::AlbumManager::DisplayTable();
            std::cout << "Enter new id: ";
            int id;
            std::cin >> id;
            trackCopy.setAlbumId( id );
        }
        else if ( choice == "Set next track ID" )
        {
            std::cout << "Enter new id: ";
            int id;
            std::cin >> id;
            trackCopy.setNextTrackId( id );
        }
        else if ( choice == "Set previous track ID" )
        {
            std::cout << "Enter new id: ";
            int id;
            std::cin >> id;
            trackCopy.setPrevTrackId( id );
        }
    }

    Music::TrackManager::UpdateTrack( id, trackCopy );
    Music::TrackManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_Music_Tracks_View() // @omonroe
{
    Utilities::Helper::Header("View Tracks");
    Music::TrackManager::DisplayTable();
    Utilities::Helper::Pause();
}

/************************************************************************************** AUDIOBOOK NAMESPACE */
/*                                                                                                     Book */
void MenuApplication::Menu_Audiobook_Book_Add() // @britter4
{
    Utilities::Helper::SubHeader("ADD > AUDIOBOOK > AUDIOBOOK");

    std::cout << "Enter name of book:" << std::endl;
    std::cin.ignore();
    std::string name = Utilities::Helper::GetStringLine();

    int newId = Audiobook::AudiobookManager::CreateBook(name);
    if (newId >= 0)
    {
        std::cout << "New user created at ID " << newId << std::endl;
    }

    Audiobook::AudiobookManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_Audiobook_Book_Edit() // @britter4
{
    Utilities::Helper::SubHeader("EDIT > AUDIOBOOK > AUDIOBOOK");

    if (Audiobook
        ::AudiobookManager::GetBookCount() == 0)
    {
        std::cout << "There are no users to edit!" << std::endl;
        Utilities::Helper::Pause();
        return;
    }

    Audiobook::AudiobookManager::DisplayTable();

    std::cout << std::endl << "Edit which ID? ";
    int id;
    std::cin >> id;

    Audiobook::Book bookCopy;
    try
    {
        bookCopy = Audiobook::AudiobookManager::GetBook(id);
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << "ERROR: " << ex.what() << std::endl;
        return;
    }

    bool menuDone = false;
    while (!menuDone)
    {
        Utilities::Helper::SubHeader("Editing " + bookCopy.GetTitle() + "...");

        bookCopy.Display();

        std::string choice = Utilities::Helper::ShowMenuGetString(
            {
                "Go back",
                "Edit name",
                "Add Author ID",
                "Add Chapter ID"
            },
            false, false
        );

        if (choice == "Go back")
        {
            menuDone = true;
        }
        else if (choice == "Edit name")
        {
            std::cout << "Enter new name: ";
            std::string name = Utilities::Helper::GetStringLine();
            bookCopy.SetTitle(name);
        }
        else if (choice == "Add Author ID")
        {
            std::cout << "Available Audiobooks:" << std::endl;

            if (Audiobook::AudiobookManager::GetBookCount() == 0)
            {
                std::cout << "There are no Audiobooks to add!" << std::endl;
                Utilities::Helper::Pause();
                continue;
            }

            Audiobook::AudiobookManager::DisplayTable();

            int authorId;
            std::cout << std::endl << "Enter Author ID: ";
            std::cin >> authorId;

            while (authorId < 0)
            {
                std::cout << "That ID is not valid. Please try again: ";
                std::cin >> authorId;
            }

            try
            {
                bookCopy.AddAuthorID(authorId);
            }
            catch (const std::invalid_argument& ex)
            {
                std::cout << "ERROR! " << ex.what() << std::endl;
            }
        }
        else if (choice == "Add Chapter ID")
        {
            std::cout << "Available Audiobooks:" << std::endl;

            if (Audiobook::AudiobookManager::GetBookCount() == 0)
            {
                std::cout << "There are no Audiobooks to add!" << std::endl;
                Utilities::Helper::Pause();
                continue;
            }

            Audiobook::AudiobookManager::DisplayTable();

            int chapterId;
            std::cout << std::endl << "Enter Chapter ID: ";
            std::cin >> chapterId;

            while (chapterId < 0)
            {
                std::cout << "That ID is not valid. Please try again: ";
                std::cin >> chapterId;
            }

            try
            {
                bookCopy.AddChapterID(chapterId);
            }
            catch (const std::invalid_argument& ex)
            {
                std::cout << "ERROR! " << ex.what() << std::endl;
            }
        }
    }

    Audiobook::AudiobookManager::UpdateBook(id, bookCopy);
    Audiobook::AudiobookManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_Audiobook_Book_View() // @britter4
{
    Utilities::Helper::SubHeader("VIEW > AUDIOBOOK > AUDIOBOOK");
    Audiobook::AudiobookManager::DisplayTable();
    Utilities::Helper::Pause();
}

/************************************************************************************** AUDIOBOOK NAMESPACE */
/*                                                                                                   Author */
void MenuApplication::Menu_Audiobook_Author_Add()
{
    std::cout << "NOT YET IMPLEMENTED" << std::endl;
}

void MenuApplication::Menu_Audiobook_Author_Edit()
{
    std::cout << "NOT YET IMPLEMENTED" << std::endl;
}

void MenuApplication::Menu_Audiobook_Author_View()
{
    std::cout << "NOT YET IMPLEMENTED" << std::endl;
}

/************************************************************************************** AUDIOBOOK NAMESPACE */
/*                                                                                                  Chapter */
void MenuApplication::Menu_Audiobook_Chapter_Add()
{
    std::cout << "NOT YET IMPLEMENTED" << std::endl;
}

void MenuApplication::Menu_Audiobook_Chapter_Edit()
{
    std::cout << "NOT YET IMPLEMENTED" << std::endl;
}

void MenuApplication::Menu_Audiobook_Chapter_View()
{
    std::cout << "NOT YET IMPLEMENTED" << std::endl;
}

/**************************************************************************************** PODCAST NAMESPACE */
/*                                                                                                     Show */
void MenuApplication::Menu_Podcast_Show_Add()
{
    std::cout << "NOT YET IMPLEMENTED" << std::endl;
}

void MenuApplication::Menu_Podcast_Show_Edit()
{
    std::cout << "NOT YET IMPLEMENTED" << std::endl;
}

void MenuApplication::Menu_Podcast_Show_View()
{
    std::cout << "NOT YET IMPLEMENTED" << std::endl;
}

/**************************************************************************************** PODCAST NAMESPACE */
/*                                                                                                  Creator */
void MenuApplication::Menu_Podcast_Creator_Add() // @akice21
{
    Utilities::Helper::Header("Creator - Add"); //Header

    //Ask user input
    std::string name;
    std::cout << "Enter creator name: ";
    std::cin.ignore();
    getline(std::cin, name);

    //Call functions, make Creator, and add them to creator_vector
    int newId = Podcast::CreatorManager::CreateCreator(name);

    //output confirmation
    if (newId >= 0)
    {
        std::cout << "New creator created at ID " << newId << std::endl;
    }

    Podcast::CreatorManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_Podcast_Creator_Edit() // @akice21
{
    Utilities::Helper::Header("Creator - Edit");//header

    //Displays all creators
    Podcast::CreatorManager::DisplayTable();

    std::cout << std::endl << "Edit which Creator ID? ";
    int id;
    std::cin >> id;
    std::cout << std::endl;

    std::cout << "Do which of the following? " << std::endl
              << "1. Edit name" << std::endl
              << "2. Edit bio" << std::endl
              << "3. Add podcast ID" << std::endl << std::endl;
    int choice;
    std::cin >> choice;

    //Edits according to user selection
    if (choice == 1)
    {

        std::string name;
        std::cout << "Enter new name: ";
        std::cin.ignore();
        getline(std::cin, name);
        Podcast::Creator newCreator = Podcast::CreatorManager::GetCreator(id);
        newCreator.SetName(name);
        Podcast::CreatorManager::UpdateCreator(id, newCreator);
    }
    else if (choice == 2)
    {

        std::string bio;
        std::cout << "Enter new bio: ";
        std::cin.ignore();
        getline(std::cin, bio);
        Podcast::Creator newCreator = Podcast::CreatorManager::GetCreator(id);
        newCreator.SetBio(bio);
        Podcast::CreatorManager::UpdateCreator(id, newCreator);
    }
    else if (choice == 3)
    {

        int podcastId;
        bool validId = false;

        //exception and loop in case negative number is entered
        while (!validId)
        {
            try
            {
//                Podcast::ShowManager::DisplayTable();
                std::cout << "Enter podcast ID: ";
                std::cin >> podcastId;
                Podcast::Creator newCreator = Podcast::CreatorManager::GetCreator(id);
                newCreator.AddPodcastId(podcastId);
                Podcast::CreatorManager::UpdateCreator(id, newCreator);
                validId = true;
            }
            catch (const std::invalid_argument& ex)
            {

                std::cout << "invalid_argument Exception: " << ex.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    }

    Podcast::CreatorManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_Podcast_Creator_View() // @akice21
{
    Utilities::Helper::Header("View a Show Artist");
    Podcast::CreatorManager::DisplayTable();
    Utilities::Helper::Pause();
}

/**************************************************************************************** PODCAST NAMESPACE */
/*                                                                                                  Episode */
void MenuApplication::Menu_Podcast_Episodes_Add() // @Jniyonzima
{
    Utilities::Helper::SubHeader("ADD > PODCAST > PODCAST");
    Utilities::Helper::Header("CREATE EPISODE");

    std::cout << "Enter name of EPISODE: " << std::endl;
    std::cin.ignore();
    std::string title = Utilities::Helper::GetStringLine();

    int newId = Podcast::EpisodeManager::CreateEpisode(title);

    if (newId >= 0) {
        std::cout << "New Episode created at ID " << newId << std::endl;
    }
    Podcast::EpisodeManager::SaveData();
    Utilities::Helper::Pause();
}

void MenuApplication::Menu_Podcast_Episodes_Edit() // @Jniyonzima
{
    Utilities::Helper::SubHeader("Edit > Podcasts > Podcast");

    if (Podcast::EpisodeManager::GetEpisodeCount() == 0)
    {
        std::cout << "There are no episodes to edit " << std::endl;
        Utilities::Helper::Pause();
        return;
    }


    Podcast::EpisodeManager::DisplayTable();

    std::cout << std::endl << "Edit which ID? ";
    int id;
    std::cin >> id;
    Podcast::Episode episodeCopy;

    try
    {
       episodeCopy =  Podcast::EpisodeManager::GetEpisode(id);

    }
    catch (const std::invalid_argument& ex)
    {

        std::cout << "ERROR! " << ex.what() << std::endl;
        return;
    }




    bool done = false;
    while (!done)
    {
        Utilities::Helper::SubHeader("Editing " + episodeCopy.GetNewTitle() + " **** ");
        episodeCopy.Display();
        std::string choice = Utilities::Helper::ShowMenuGetString(
            {
             "Go back",
            "Edit Title",
            "Add podcast ID",
            "Add episode Id"
            },
            true, false
        ); // end of showMenuGetString list
        if (choice == "Go back")
        {
            done = true;
        }
        else if (choice == "Edit Title")
        {

            std::cout << "Enter new title: ";
            std::cin.ignore();
            std::string  title = Utilities::Helper::GetStringLine();
            episodeCopy.SetTitle(title);
        }
        else if (choice == "Add podcast ID")
        {
            int podcastId;
            std::cout << " enter the Podcast Id: ";
             std::cin >> podcastId;
            try
            {
                episodeCopy.SetPodcastId(podcastId);
            }
            catch (const std::invalid_argument& ex)
            {
                std::cout << "ERROR " << ex.what() << std::endl;
                return;
             }
        }
        else if (choice == "Add episode Id")
        {
            std::cout << "Available Ids " << std::endl;
            if (Podcast::EpisodeManager::GetEpisodeCount() == 0) {
                std::cout << "There no availabe episodes" << std::endl;
                Utilities::Helper::Pause();
                continue;
            }
            Podcast::EpisodeManager::DisplayTable();
            int episodeId;
            std::cout << "Enter the episode Id: ";
            std::cin >> episodeId;
            while (Podcast::EpisodeManager::IsValidId(episodeId) == false)
            {
                std::cout << "Invalid episode Id entered, please try agin: ";
                std::cin >> episodeId;

            }

            try
            {

                episodeCopy.AddEpisodeId(episodeId);
            }
            catch (const std::invalid_argument& ex)
            {
                std::cout << "ERROR! " << ex.what() << std::endl;
            } // end of try and catch

        }
    }
    Utilities::Helper::Pause();

}// end of my  podcast edit function

void MenuApplication::Menu_Podcast_Episodes_View() // @Jniyonzima
{

    Utilities::Helper::SubHeader("VIEW > PODCAST > EPISODES");
    Podcast::EpisodeManager::DisplayTable();
    Utilities::Helper::Pause();

}// end of podcast episode view function

}
