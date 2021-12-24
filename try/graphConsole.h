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
#include "Dot.h"
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
	void setP(std::pair<int, int> cors, std::vector<Dot> p, std::vector<std::pair<int, int>> P);
};


