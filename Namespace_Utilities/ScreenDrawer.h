#ifndef _SCREEN_DRAWER_HPP
#define _SCREEN_DRAWER_HPP

#include <string>
#include <map>
#include <vector>

namespace Utilities
{

struct ScreenTile {
  char symbol;
  std::string foreground;
  std::string background;
};

class ScreenDrawer
{
public:
  static void Setup( int screenWidth, int screenHeight );
  static void Teardown();
  static void Fill( char symbol, std::string foreground, std::string background );
  static void Clear(int x, int y);
  static void Set(int x, int y, char symbol, std::string foreground = "white", std::string background = "black");
  static void Set(int x, int y, std::string str, std::string foreground = "white", std::string background = "black");
  static void DrawFillRect( int left, int top, int right, int bottom, char symbol, std::string foreground = "white", std::string background = "black" );
  static void DrawRect( int left, int top, int right, int bottom, char symbol, std::string foreground = "white", std::string background = "black" );
  static void DrawLine( int x1, int y1, int x2, int y2, char symbol, std::string foreground = "white", std::string background = "black" );
  static void Draw();
  static int GetScreenWidth();
  static int GetScreenHeight();

  static void SetCoutStyle(std::string bg, std::string fg);
  static void ResetCoutStyle();

  static void SetBorderColors( std::string foreground, std::string background );
  static void SetWindowColors( std::string foreground, std::string background );
  static void SetBackgroundColors( std::string foreground, std::string background, char texture );
  static void SetWinTitleColors( std::string foreground, std::string background );

  static void DrawBackground();
  static void DrawWindow( std::string title, int left, int top, int right, int bottom );

private:
  static int s_screenWidth;
  static int s_screenHeight;

  static bool IsValidRange(int x, int y);
  static void ClearConsole();

  static ScreenTile** s_grid;

  static std::map<std::string, int> s_backgrounds;
  static std::map<std::string, int> s_foregrounds;

  static ScreenTile s_borderColors;
  static ScreenTile s_windowColors;
  static ScreenTile s_backgroundColors;
  static ScreenTile s_winTitleColors;
};

}

#endif
