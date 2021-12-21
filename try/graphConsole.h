#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cwchar>
#pragma comment(lib, "user32")
#include <stdio.h>
#define PP printf
#include "Circle.h"
#include <string>
#include <vector>
enum colors_background
{
	BackBlack = 0,
	BackGrey = BACKGROUND_INTENSITY,
	BackLightGrey = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	BackWhite = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY,
	BackBlue = BACKGROUND_BLUE,
	BackGreen = BACKGROUND_GREEN,
	BackCyan = BACKGROUND_GREEN | BACKGROUND_BLUE,
	BackRed = BACKGROUND_RED,
	BackPurple = BACKGROUND_RED | BACKGROUND_BLUE,
	BackLightBlue = BACKGROUND_BLUE | BACKGROUND_INTENSITY,
	BackLightGreen = BACKGROUND_GREEN | BACKGROUND_INTENSITY,
	BackLightCyan = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY,
	BackLightRed = BACKGROUND_RED | BACKGROUND_INTENSITY,
	BackLightPurple = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY,
	BackOrange = BACKGROUND_RED | BACKGROUND_GREEN,
	BackYellow = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
};
enum colors_foreground
{
	ForeBlack = 0,
	ForeGrey = FOREGROUND_INTENSITY,
	ForeLightGrey = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	ForeWhite = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	ForeBlue = FOREGROUND_BLUE,
	ForeGreen = FOREGROUND_GREEN,
	ForeCyan = FOREGROUND_GREEN | FOREGROUND_BLUE,
	ForeRed = FOREGROUND_RED,
	ForePurple = FOREGROUND_RED | FOREGROUND_BLUE,
	ForeLightBlue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	ForeLightGreen = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	ForeLightCyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	ForeLightRed = FOREGROUND_RED | FOREGROUND_INTENSITY,
	ForeLightPurple = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	ForeOrange = FOREGROUND_RED | FOREGROUND_GREEN,
	ForeYellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
};
struct Dot {
	std::string ch="";
	colors_foreground color_f;
	colors_background color_b;
};
class graphConsole
{
private:
	CONSOLE_FONT_INFOEX cell;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD Width, Height;
	Dot** m;
public:
	colors_background clrblck = BackBlack;
	graphConsole();
	graphConsole(bool fullscr);
	~graphConsole();
	void cls();
	void setCell(int x, int y);
	void setCursorPosition(int x, int y);
	void showScreen();
	void setMatrix();
	void setWinScale();
	void setP(std::pair<int,int> cors, Dot p);
	void setP(std::pair<int, int> cors, Dot p, std::vector<std::pair<int, int>> P);
};

