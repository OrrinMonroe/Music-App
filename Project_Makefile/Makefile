#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -Wall -std=c++17
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = ./MusicApp_debug

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = ./MusicApp_release

OBJ_DEBUG = $(OBJDIR_DEBUG)/__/Namespace_Testing/TesterBase.o $(OBJDIR_DEBUG)/__/Namespace_User/User.o $(OBJDIR_DEBUG)/__/Namespace_User/PlaylistManager.o $(OBJDIR_DEBUG)/__/Namespace_User/Playlist.o $(OBJDIR_DEBUG)/__/Namespace_Testing/TesterManager.o $(OBJDIR_DEBUG)/__/Namespace_Podcast/ShowManager.o $(OBJDIR_DEBUG)/__/Namespace_Podcast/ShowArtist.o $(OBJDIR_DEBUG)/__/Namespace_Podcast/Show.o $(OBJDIR_DEBUG)/__/Namespace_Podcast/EpisodeManager.o $(OBJDIR_DEBUG)/__/main.o $(OBJDIR_DEBUG)/__/Namespace_Utilities/ScreenDrawer.o $(OBJDIR_DEBUG)/__/Namespace_Utilities/Platform.o $(OBJDIR_DEBUG)/__/Namespace_Utilities/Messager.o $(OBJDIR_DEBUG)/__/Namespace_Podcast/Episode.o $(OBJDIR_DEBUG)/__/Namespace_Utilities/Logger.o $(OBJDIR_DEBUG)/__/Namespace_Utilities/Helper.o $(OBJDIR_DEBUG)/__/Namespace_Utilities/CsvParser.o $(OBJDIR_DEBUG)/__/Namespace_User/UserManager.o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/BookArtist.o $(OBJDIR_DEBUG)/__/Namespace_Metadata/Language.o $(OBJDIR_DEBUG)/__/Namespace_Metadata/Genre.o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/ChapterManager.o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/Chapter.o $(OBJDIR_DEBUG)/__/Namespace_Metadata/Role.o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/AuthorManager.o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/AudiobookManager.o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/Audiobook.o $(OBJDIR_DEBUG)/__/Namespace_Application/ProgramManager.o $(OBJDIR_DEBUG)/__/Namespace_Music/ArtistManager.o $(OBJDIR_DEBUG)/__/Namespace_Podcast/CreatorManager.o $(OBJDIR_DEBUG)/__/Namespace_Music/TrackManager.o $(OBJDIR_DEBUG)/__/Namespace_Music/Track.o $(OBJDIR_DEBUG)/__/Namespace_Music/MusicArtist.o $(OBJDIR_DEBUG)/__/Namespace_Application/MenuApp.o $(OBJDIR_DEBUG)/__/Namespace_Music/AlbumManager.o $(OBJDIR_DEBUG)/__/Namespace_Music/Album.o $(OBJDIR_DEBUG)/__/Namespace_Metadata/StatusCodeManager.o $(OBJDIR_DEBUG)/__/Namespace_Metadata/StatusCode.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/__/Namespace_Testing/TesterBase.o $(OBJDIR_RELEASE)/__/Namespace_User/User.o $(OBJDIR_RELEASE)/__/Namespace_User/PlaylistManager.o $(OBJDIR_RELEASE)/__/Namespace_User/Playlist.o $(OBJDIR_RELEASE)/__/Namespace_Testing/TesterManager.o $(OBJDIR_RELEASE)/__/Namespace_Podcast/ShowManager.o $(OBJDIR_RELEASE)/__/Namespace_Podcast/ShowArtist.o $(OBJDIR_RELEASE)/__/Namespace_Podcast/Show.o $(OBJDIR_RELEASE)/__/Namespace_Podcast/EpisodeManager.o $(OBJDIR_RELEASE)/__/main.o $(OBJDIR_RELEASE)/__/Namespace_Utilities/ScreenDrawer.o $(OBJDIR_RELEASE)/__/Namespace_Utilities/Platform.o $(OBJDIR_RELEASE)/__/Namespace_Utilities/Messager.o $(OBJDIR_RELEASE)/__/Namespace_Podcast/Episode.o $(OBJDIR_RELEASE)/__/Namespace_Utilities/Logger.o $(OBJDIR_RELEASE)/__/Namespace_Utilities/Helper.o $(OBJDIR_RELEASE)/__/Namespace_Utilities/CsvParser.o $(OBJDIR_RELEASE)/__/Namespace_User/UserManager.o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/BookArtist.o $(OBJDIR_RELEASE)/__/Namespace_Metadata/Language.o $(OBJDIR_RELEASE)/__/Namespace_Metadata/Genre.o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/ChapterManager.o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/Chapter.o $(OBJDIR_RELEASE)/__/Namespace_Metadata/Role.o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/AuthorManager.o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/AudiobookManager.o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/Audiobook.o $(OBJDIR_RELEASE)/__/Namespace_Application/ProgramManager.o $(OBJDIR_RELEASE)/__/Namespace_Music/ArtistManager.o $(OBJDIR_RELEASE)/__/Namespace_Podcast/CreatorManager.o $(OBJDIR_RELEASE)/__/Namespace_Music/TrackManager.o $(OBJDIR_RELEASE)/__/Namespace_Music/Track.o $(OBJDIR_RELEASE)/__/Namespace_Music/MusicArtist.o $(OBJDIR_RELEASE)/__/Namespace_Application/MenuApp.o $(OBJDIR_RELEASE)/__/Namespace_Music/AlbumManager.o $(OBJDIR_RELEASE)/__/Namespace_Music/Album.o $(OBJDIR_RELEASE)/__/Namespace_Metadata/StatusCodeManager.o $(OBJDIR_RELEASE)/__/Namespace_Metadata/StatusCode.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d $(OBJDIR_DEBUG)/__/Namespace_Testing || mkdir -p $(OBJDIR_DEBUG)/__/Namespace_Testing
	test -d $(OBJDIR_DEBUG)/__/Namespace_User || mkdir -p $(OBJDIR_DEBUG)/__/Namespace_User
	test -d $(OBJDIR_DEBUG)/__/Namespace_Podcast || mkdir -p $(OBJDIR_DEBUG)/__/Namespace_Podcast
	test -d $(OBJDIR_DEBUG)/__ || mkdir -p $(OBJDIR_DEBUG)/__
	test -d $(OBJDIR_DEBUG)/__/Namespace_Utilities || mkdir -p $(OBJDIR_DEBUG)/__/Namespace_Utilities
	test -d $(OBJDIR_DEBUG)/__/Namespace_Audiobook || mkdir -p $(OBJDIR_DEBUG)/__/Namespace_Audiobook
	test -d $(OBJDIR_DEBUG)/__/Namespace_Metadata || mkdir -p $(OBJDIR_DEBUG)/__/Namespace_Metadata
	test -d $(OBJDIR_DEBUG)/__/Namespace_Application || mkdir -p $(OBJDIR_DEBUG)/__/Namespace_Application
	test -d $(OBJDIR_DEBUG)/__/Namespace_Music || mkdir -p $(OBJDIR_DEBUG)/__/Namespace_Music

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/__/Namespace_Testing/TesterBase.o: ../Namespace_Testing/TesterBase.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Testing/TesterBase.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Testing/TesterBase.o

$(OBJDIR_DEBUG)/__/Namespace_User/User.o: ../Namespace_User/User.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_User/User.cpp -o $(OBJDIR_DEBUG)/__/Namespace_User/User.o

$(OBJDIR_DEBUG)/__/Namespace_User/PlaylistManager.o: ../Namespace_User/PlaylistManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_User/PlaylistManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_User/PlaylistManager.o

$(OBJDIR_DEBUG)/__/Namespace_User/Playlist.o: ../Namespace_User/Playlist.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_User/Playlist.cpp -o $(OBJDIR_DEBUG)/__/Namespace_User/Playlist.o

$(OBJDIR_DEBUG)/__/Namespace_Testing/TesterManager.o: ../Namespace_Testing/TesterManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Testing/TesterManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Testing/TesterManager.o

$(OBJDIR_DEBUG)/__/Namespace_Podcast/ShowManager.o: ../Namespace_Podcast/ShowManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Podcast/ShowManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Podcast/ShowManager.o

$(OBJDIR_DEBUG)/__/Namespace_Podcast/ShowArtist.o: ../Namespace_Podcast/ShowArtist.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Podcast/ShowArtist.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Podcast/ShowArtist.o

$(OBJDIR_DEBUG)/__/Namespace_Podcast/Show.o: ../Namespace_Podcast/Show.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Podcast/Show.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Podcast/Show.o

$(OBJDIR_DEBUG)/__/Namespace_Podcast/EpisodeManager.o: ../Namespace_Podcast/EpisodeManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Podcast/EpisodeManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Podcast/EpisodeManager.o

$(OBJDIR_DEBUG)/__/main.o: ../main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../main.cpp -o $(OBJDIR_DEBUG)/__/main.o

$(OBJDIR_DEBUG)/__/Namespace_Utilities/ScreenDrawer.o: ../Namespace_Utilities/ScreenDrawer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Utilities/ScreenDrawer.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Utilities/ScreenDrawer.o

$(OBJDIR_DEBUG)/__/Namespace_Utilities/Platform.o: ../Namespace_Utilities/Platform.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Utilities/Platform.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Utilities/Platform.o

$(OBJDIR_DEBUG)/__/Namespace_Utilities/Messager.o: ../Namespace_Utilities/Messager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Utilities/Messager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Utilities/Messager.o

$(OBJDIR_DEBUG)/__/Namespace_Podcast/Episode.o: ../Namespace_Podcast/Episode.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Podcast/Episode.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Podcast/Episode.o

$(OBJDIR_DEBUG)/__/Namespace_Utilities/Logger.o: ../Namespace_Utilities/Logger.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Utilities/Logger.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Utilities/Logger.o

$(OBJDIR_DEBUG)/__/Namespace_Utilities/Helper.o: ../Namespace_Utilities/Helper.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Utilities/Helper.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Utilities/Helper.o

$(OBJDIR_DEBUG)/__/Namespace_Utilities/CsvParser.o: ../Namespace_Utilities/CsvParser.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Utilities/CsvParser.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Utilities/CsvParser.o

$(OBJDIR_DEBUG)/__/Namespace_User/UserManager.o: ../Namespace_User/UserManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_User/UserManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_User/UserManager.o

$(OBJDIR_DEBUG)/__/Namespace_Audiobook/BookArtist.o: ../Namespace_Audiobook/BookArtist.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Audiobook/BookArtist.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/BookArtist.o

$(OBJDIR_DEBUG)/__/Namespace_Metadata/Language.o: ../Namespace_Metadata/Language.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Metadata/Language.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Metadata/Language.o

$(OBJDIR_DEBUG)/__/Namespace_Metadata/Genre.o: ../Namespace_Metadata/Genre.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Metadata/Genre.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Metadata/Genre.o

$(OBJDIR_DEBUG)/__/Namespace_Audiobook/ChapterManager.o: ../Namespace_Audiobook/ChapterManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Audiobook/ChapterManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/ChapterManager.o

$(OBJDIR_DEBUG)/__/Namespace_Audiobook/Chapter.o: ../Namespace_Audiobook/Chapter.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Audiobook/Chapter.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/Chapter.o

$(OBJDIR_DEBUG)/__/Namespace_Metadata/Role.o: ../Namespace_Metadata/Role.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Metadata/Role.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Metadata/Role.o

$(OBJDIR_DEBUG)/__/Namespace_Audiobook/AuthorManager.o: ../Namespace_Audiobook/AuthorManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Audiobook/AuthorManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/AuthorManager.o

$(OBJDIR_DEBUG)/__/Namespace_Audiobook/AudiobookManager.o: ../Namespace_Audiobook/AudiobookManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Audiobook/AudiobookManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/AudiobookManager.o

$(OBJDIR_DEBUG)/__/Namespace_Audiobook/Audiobook.o: ../Namespace_Audiobook/Audiobook.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Audiobook/Audiobook.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Audiobook/Audiobook.o

$(OBJDIR_DEBUG)/__/Namespace_Application/ProgramManager.o: ../Namespace_Application/ProgramManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Application/ProgramManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Application/ProgramManager.o

$(OBJDIR_DEBUG)/__/Namespace_Music/ArtistManager.o: ../Namespace_Music/ArtistManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Music/ArtistManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Music/ArtistManager.o

$(OBJDIR_DEBUG)/__/Namespace_Podcast/CreatorManager.o: ../Namespace_Podcast/CreatorManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Podcast/CreatorManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Podcast/CreatorManager.o

$(OBJDIR_DEBUG)/__/Namespace_Music/TrackManager.o: ../Namespace_Music/TrackManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Music/TrackManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Music/TrackManager.o

$(OBJDIR_DEBUG)/__/Namespace_Music/Track.o: ../Namespace_Music/Track.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Music/Track.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Music/Track.o

$(OBJDIR_DEBUG)/__/Namespace_Music/MusicArtist.o: ../Namespace_Music/MusicArtist.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Music/MusicArtist.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Music/MusicArtist.o

$(OBJDIR_DEBUG)/__/Namespace_Application/MenuApp.o: ../Namespace_Application/MenuApp.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Application/MenuApp.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Application/MenuApp.o

$(OBJDIR_DEBUG)/__/Namespace_Music/AlbumManager.o: ../Namespace_Music/AlbumManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Music/AlbumManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Music/AlbumManager.o

$(OBJDIR_DEBUG)/__/Namespace_Music/Album.o: ../Namespace_Music/Album.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Music/Album.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Music/Album.o

$(OBJDIR_DEBUG)/__/Namespace_Metadata/StatusCodeManager.o: ../Namespace_Metadata/StatusCodeManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Metadata/StatusCodeManager.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Metadata/StatusCodeManager.o

$(OBJDIR_DEBUG)/__/Namespace_Metadata/StatusCode.o: ../Namespace_Metadata/StatusCode.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ../Namespace_Metadata/StatusCode.cpp -o $(OBJDIR_DEBUG)/__/Namespace_Metadata/StatusCode.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf $(OBJDIR_DEBUG)/__/Namespace_Testing
	rm -rf $(OBJDIR_DEBUG)/__/Namespace_User
	rm -rf $(OBJDIR_DEBUG)/__/Namespace_Podcast
	rm -rf $(OBJDIR_DEBUG)/__
	rm -rf $(OBJDIR_DEBUG)/__/Namespace_Utilities
	rm -rf $(OBJDIR_DEBUG)/__/Namespace_Audiobook
	rm -rf $(OBJDIR_DEBUG)/__/Namespace_Metadata
	rm -rf $(OBJDIR_DEBUG)/__/Namespace_Application
	rm -rf $(OBJDIR_DEBUG)/__/Namespace_Music

before_release: 
	test -d $(OBJDIR_RELEASE)/__/Namespace_Testing || mkdir -p $(OBJDIR_RELEASE)/__/Namespace_Testing
	test -d $(OBJDIR_RELEASE)/__/Namespace_User || mkdir -p $(OBJDIR_RELEASE)/__/Namespace_User
	test -d $(OBJDIR_RELEASE)/__/Namespace_Podcast || mkdir -p $(OBJDIR_RELEASE)/__/Namespace_Podcast
	test -d $(OBJDIR_RELEASE)/__ || mkdir -p $(OBJDIR_RELEASE)/__
	test -d $(OBJDIR_RELEASE)/__/Namespace_Utilities || mkdir -p $(OBJDIR_RELEASE)/__/Namespace_Utilities
	test -d $(OBJDIR_RELEASE)/__/Namespace_Audiobook || mkdir -p $(OBJDIR_RELEASE)/__/Namespace_Audiobook
	test -d $(OBJDIR_RELEASE)/__/Namespace_Metadata || mkdir -p $(OBJDIR_RELEASE)/__/Namespace_Metadata
	test -d $(OBJDIR_RELEASE)/__/Namespace_Application || mkdir -p $(OBJDIR_RELEASE)/__/Namespace_Application
	test -d $(OBJDIR_RELEASE)/__/Namespace_Music || mkdir -p $(OBJDIR_RELEASE)/__/Namespace_Music

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/__/Namespace_Testing/TesterBase.o: ../Namespace_Testing/TesterBase.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Testing/TesterBase.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Testing/TesterBase.o

$(OBJDIR_RELEASE)/__/Namespace_User/User.o: ../Namespace_User/User.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_User/User.cpp -o $(OBJDIR_RELEASE)/__/Namespace_User/User.o

$(OBJDIR_RELEASE)/__/Namespace_User/PlaylistManager.o: ../Namespace_User/PlaylistManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_User/PlaylistManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_User/PlaylistManager.o

$(OBJDIR_RELEASE)/__/Namespace_User/Playlist.o: ../Namespace_User/Playlist.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_User/Playlist.cpp -o $(OBJDIR_RELEASE)/__/Namespace_User/Playlist.o

$(OBJDIR_RELEASE)/__/Namespace_Testing/TesterManager.o: ../Namespace_Testing/TesterManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Testing/TesterManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Testing/TesterManager.o

$(OBJDIR_RELEASE)/__/Namespace_Podcast/ShowManager.o: ../Namespace_Podcast/ShowManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Podcast/ShowManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Podcast/ShowManager.o

$(OBJDIR_RELEASE)/__/Namespace_Podcast/ShowArtist.o: ../Namespace_Podcast/ShowArtist.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Podcast/ShowArtist.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Podcast/ShowArtist.o

$(OBJDIR_RELEASE)/__/Namespace_Podcast/Show.o: ../Namespace_Podcast/Show.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Podcast/Show.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Podcast/Show.o

$(OBJDIR_RELEASE)/__/Namespace_Podcast/EpisodeManager.o: ../Namespace_Podcast/EpisodeManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Podcast/EpisodeManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Podcast/EpisodeManager.o

$(OBJDIR_RELEASE)/__/main.o: ../main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../main.cpp -o $(OBJDIR_RELEASE)/__/main.o

$(OBJDIR_RELEASE)/__/Namespace_Utilities/ScreenDrawer.o: ../Namespace_Utilities/ScreenDrawer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Utilities/ScreenDrawer.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Utilities/ScreenDrawer.o

$(OBJDIR_RELEASE)/__/Namespace_Utilities/Platform.o: ../Namespace_Utilities/Platform.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Utilities/Platform.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Utilities/Platform.o

$(OBJDIR_RELEASE)/__/Namespace_Utilities/Messager.o: ../Namespace_Utilities/Messager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Utilities/Messager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Utilities/Messager.o

$(OBJDIR_RELEASE)/__/Namespace_Podcast/Episode.o: ../Namespace_Podcast/Episode.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Podcast/Episode.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Podcast/Episode.o

$(OBJDIR_RELEASE)/__/Namespace_Utilities/Logger.o: ../Namespace_Utilities/Logger.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Utilities/Logger.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Utilities/Logger.o

$(OBJDIR_RELEASE)/__/Namespace_Utilities/Helper.o: ../Namespace_Utilities/Helper.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Utilities/Helper.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Utilities/Helper.o

$(OBJDIR_RELEASE)/__/Namespace_Utilities/CsvParser.o: ../Namespace_Utilities/CsvParser.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Utilities/CsvParser.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Utilities/CsvParser.o

$(OBJDIR_RELEASE)/__/Namespace_User/UserManager.o: ../Namespace_User/UserManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_User/UserManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_User/UserManager.o

$(OBJDIR_RELEASE)/__/Namespace_Audiobook/BookArtist.o: ../Namespace_Audiobook/BookArtist.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Audiobook/BookArtist.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/BookArtist.o

$(OBJDIR_RELEASE)/__/Namespace_Metadata/Language.o: ../Namespace_Metadata/Language.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Metadata/Language.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Metadata/Language.o

$(OBJDIR_RELEASE)/__/Namespace_Metadata/Genre.o: ../Namespace_Metadata/Genre.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Metadata/Genre.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Metadata/Genre.o

$(OBJDIR_RELEASE)/__/Namespace_Audiobook/ChapterManager.o: ../Namespace_Audiobook/ChapterManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Audiobook/ChapterManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/ChapterManager.o

$(OBJDIR_RELEASE)/__/Namespace_Audiobook/Chapter.o: ../Namespace_Audiobook/Chapter.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Audiobook/Chapter.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/Chapter.o

$(OBJDIR_RELEASE)/__/Namespace_Metadata/Role.o: ../Namespace_Metadata/Role.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Metadata/Role.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Metadata/Role.o

$(OBJDIR_RELEASE)/__/Namespace_Audiobook/AuthorManager.o: ../Namespace_Audiobook/AuthorManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Audiobook/AuthorManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/AuthorManager.o

$(OBJDIR_RELEASE)/__/Namespace_Audiobook/AudiobookManager.o: ../Namespace_Audiobook/AudiobookManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Audiobook/AudiobookManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/AudiobookManager.o

$(OBJDIR_RELEASE)/__/Namespace_Audiobook/Audiobook.o: ../Namespace_Audiobook/Audiobook.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Audiobook/Audiobook.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Audiobook/Audiobook.o

$(OBJDIR_RELEASE)/__/Namespace_Application/ProgramManager.o: ../Namespace_Application/ProgramManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Application/ProgramManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Application/ProgramManager.o

$(OBJDIR_RELEASE)/__/Namespace_Music/ArtistManager.o: ../Namespace_Music/ArtistManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Music/ArtistManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Music/ArtistManager.o

$(OBJDIR_RELEASE)/__/Namespace_Podcast/CreatorManager.o: ../Namespace_Podcast/CreatorManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Podcast/CreatorManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Podcast/CreatorManager.o

$(OBJDIR_RELEASE)/__/Namespace_Music/TrackManager.o: ../Namespace_Music/TrackManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Music/TrackManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Music/TrackManager.o

$(OBJDIR_RELEASE)/__/Namespace_Music/Track.o: ../Namespace_Music/Track.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Music/Track.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Music/Track.o

$(OBJDIR_RELEASE)/__/Namespace_Music/MusicArtist.o: ../Namespace_Music/MusicArtist.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Music/MusicArtist.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Music/MusicArtist.o

$(OBJDIR_RELEASE)/__/Namespace_Application/MenuApp.o: ../Namespace_Application/MenuApp.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Application/MenuApp.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Application/MenuApp.o

$(OBJDIR_RELEASE)/__/Namespace_Music/AlbumManager.o: ../Namespace_Music/AlbumManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Music/AlbumManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Music/AlbumManager.o

$(OBJDIR_RELEASE)/__/Namespace_Music/Album.o: ../Namespace_Music/Album.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Music/Album.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Music/Album.o

$(OBJDIR_RELEASE)/__/Namespace_Metadata/StatusCodeManager.o: ../Namespace_Metadata/StatusCodeManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Metadata/StatusCodeManager.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Metadata/StatusCodeManager.o

$(OBJDIR_RELEASE)/__/Namespace_Metadata/StatusCode.o: ../Namespace_Metadata/StatusCode.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ../Namespace_Metadata/StatusCode.cpp -o $(OBJDIR_RELEASE)/__/Namespace_Metadata/StatusCode.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf $(OBJDIR_RELEASE)/__/Namespace_Testing
	rm -rf $(OBJDIR_RELEASE)/__/Namespace_User
	rm -rf $(OBJDIR_RELEASE)/__/Namespace_Podcast
	rm -rf $(OBJDIR_RELEASE)/__
	rm -rf $(OBJDIR_RELEASE)/__/Namespace_Utilities
	rm -rf $(OBJDIR_RELEASE)/__/Namespace_Audiobook
	rm -rf $(OBJDIR_RELEASE)/__/Namespace_Metadata
	rm -rf $(OBJDIR_RELEASE)/__/Namespace_Application
	rm -rf $(OBJDIR_RELEASE)/__/Namespace_Music

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

