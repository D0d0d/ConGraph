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


class graphConsole
{
private:
	CONSOLE_FONT_INFOEX cell;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD Width, Height;
	int** m;
public:
	graphConsole();
	std::string palette[64] = {"","", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "","","", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
	void cls();
	void setCell(int x, int y);
	void setCursorPosition(int x, int y);
	void showScreen();
	void setMatrix();
	void setWinScale();
	void setP(std::pair<int,int> P, int p);
	void setP(std::vector<std::pair<int, int>> P, int p, std::pair<int, int> cor);
};

