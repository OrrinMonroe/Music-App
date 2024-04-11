#include "ScreenDrawer.h"

#include <iostream>
#include <sstream>

namespace Utilities
{

int ScreenDrawer::s_screenWidth;
int ScreenDrawer::s_screenHeight;
ScreenTile** ScreenDrawer::s_grid;
std::map<std::string, int> ScreenDrawer::s_foregrounds;
std::map<std::string, int> ScreenDrawer::s_backgrounds;
ScreenTile ScreenDrawer::s_borderColors;
ScreenTile ScreenDrawer::s_windowColors;
ScreenTile ScreenDrawer::s_backgroundColors;
ScreenTile ScreenDrawer::s_winTitleColors;

void ScreenDrawer::Setup( int screenWidth, int screenHeight )
{
  SetBorderColors( "white", "white" );
  SetWindowColors( "white", "black" );
  SetBackgroundColors( "cyan", "blue", '/' );
  SetWinTitleColors( "white", "blue" );

  s_screenWidth = screenWidth;
  s_screenHeight = screenHeight;

  s_grid = new ScreenTile*[ s_screenWidth ];
  for ( int x = 0; x < s_screenWidth; x++ )
    {
      s_grid[x] = new ScreenTile[ s_screenHeight ];
    }

  s_backgrounds["black"] = 40;
  s_backgrounds["red"] = 41;
  s_backgrounds["green"] = 42;
  s_backgrounds["yellow"] = 43;
  s_backgrounds["blue"] = 44;
  s_backgrounds["magenta"] = 45;
  s_backgrounds["cyan"] = 46;
  s_backgrounds["white"] = 47;

  s_foregrounds["black"] = 30;
  s_foregrounds["red"] = 31;
  s_foregrounds["green"] = 32;
  s_foregrounds["yellow"] = 33;
  s_foregrounds["blue"] = 34;
  s_foregrounds["magenta"] = 35;
  s_foregrounds["cyan"] = 36;
  s_foregrounds["white"] = 37;

  Fill( '/', "cyan", "blue" );
}

void ScreenDrawer::Teardown()
{
  for ( int x = 0; x < s_screenWidth; x++ )
    {
      delete [] s_grid[x];
    }
  delete [] s_grid;
}

void ScreenDrawer::Fill( char symbol, std::string foreground, std::string background )
{
  for ( int y = 0; y < s_screenHeight; y++ )
    {
      for ( int x = 0; x < s_screenWidth; x++ )
	{
	  Set( x, y, symbol, foreground, background );
	}
    }
}

void ScreenDrawer::Clear(int x, int y)
{
  Set(x, y, ' ');
}

void ScreenDrawer::Set(int x, int y, char symbol, std::string foreground /*= white*/, std::string background /*= black */)
{
  if (IsValidRange(x, y))
    {
      s_grid[x][y].symbol = symbol;
      s_grid[x][y].foreground = foreground;
      s_grid[x][y].background = background;
    }
}

void ScreenDrawer::Set(int x, int y, std::string str, std::string foreground /*= white*/, std::string background /*= black */)
{
  for (unsigned int i = 0; i < str.size(); i++)
    {
      if ( i >= s_screenWidth ) { break; }
      Set( x+i, y, str[i], foreground, background );
    }
}

void ScreenDrawer::Draw()
{
  ClearConsole();
  for ( int y = 0; y < s_screenHeight ;y++ )
    {
      for (int x = 0; x < s_screenWidth; x++ )
	{
	  SetCoutStyle( s_grid[x][y].background, s_grid[x][y].foreground );
	  std::cout << s_grid[x][y].symbol;
	  ResetCoutStyle();
	}
      std::cout << std::endl;
    }
  std::cout << std::endl;
}

int ScreenDrawer::GetScreenWidth()
{
  return s_screenWidth;
}

int ScreenDrawer::GetScreenHeight()
{
  return s_screenHeight;
}

void ScreenDrawer::ClearConsole()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
  system("cls");
#else
  system("clear");
#endif
}

bool ScreenDrawer::IsValidRange(int x, int y)
{
  return (x >= 0 && x < s_screenWidth && y >= 0 && y < s_screenHeight );
}

void ScreenDrawer::SetCoutStyle(std::string bg, std::string fg)
{
  int foreCode;
  int backCode;

  try
    {
      foreCode = s_foregrounds[fg];
      backCode = s_backgrounds[bg];
    }
  catch( ... )
    {
      // :(
      std::cout << "Bad fg or bg code!" << std::endl;
      foreCode = s_foregrounds["white"];
      backCode = s_backgrounds["black"];
    }

  std::cout << "\033[3;" << foreCode << ";" << backCode << "m";
}

void ScreenDrawer::ResetCoutStyle()
{
  std::cout << "\033[0m";
}

void ScreenDrawer::DrawFillRect( int left, int top, int right, int bottom, char symbol, std::string foreground /*= "white"*/, std::string background /*="black"*/ )
{
  for ( int y = top; y < bottom; y++ )
    {
      for ( int x = left; x < right; x++ )
	{
	  Set( x, y, symbol, foreground, background );
	}
    }
}

void ScreenDrawer::DrawRect( int left, int top, int right, int bottom, char symbol, std::string foreground /*= "white"*/, std::string background /*="black"*/ )
{
  DrawLine( left, top, right, top, symbol, foreground, background );
  DrawLine( left, bottom, right, bottom, symbol, foreground, background );
  DrawLine( left, top, left, bottom, symbol, foreground, background );
  DrawLine( right, top, right, bottom, symbol, foreground, background );
}


void ScreenDrawer::DrawLine( int x1, int y1, int x2, int y2, char symbol, std::string foreground /*= "white"*/, std::string background /*= "black"*/ )
{
  int x = x1;
  int y = y1;
  while ( true )
    {
      Set( x, y, symbol, foreground, background );

      if ( x == x2 && y == y2 ) { break; }

      if ( x > x2 ) { x--; }
      else if ( x < x2 ) { x++; }
      if ( y > y2 ) { y--; }
      else if ( y < y2 ) { y++; }
    }
}

void ScreenDrawer::DrawBackground()
{
  DrawRect( 0, 0, s_screenWidth, s_screenHeight, s_backgroundColors.symbol, s_backgroundColors.foreground, s_backgroundColors.background );
}

void ScreenDrawer::DrawWindow( std::string title, int left, int top, int right, int bottom )
{
  DrawFillRect( left, top, right, bottom, ' ', s_windowColors.foreground, s_windowColors.background );
  DrawRect( left, top, right, bottom, ' ', s_borderColors.foreground, s_borderColors.background );
  DrawLine( left+1, top+1, right-1, top+1, ' ', s_winTitleColors.foreground, s_winTitleColors.background );
  Set( left+2, top+1, title, s_winTitleColors.foreground, s_winTitleColors.background );
}

void ScreenDrawer::SetBorderColors( std::string foreground, std::string background )
{
  s_borderColors.foreground = foreground;
  s_borderColors.background = background;
}

void ScreenDrawer::SetWindowColors( std::string foreground, std::string background )
{
  s_windowColors.foreground = foreground;
  s_windowColors.background = background;
}

void ScreenDrawer::SetBackgroundColors( std::string foreground, std::string background, char texture )
{
  s_backgroundColors.foreground = foreground;
  s_backgroundColors.background = background;
  s_backgroundColors.symbol = texture;
}

void ScreenDrawer::SetWinTitleColors( std::string foreground, std::string background )
{
  s_winTitleColors.foreground = foreground;
  s_winTitleColors.background = background;
}

}
