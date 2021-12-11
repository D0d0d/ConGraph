#include <iostream>
#include <windows.h>
#include <cwchar>
#pragma comment(lib, "user32")
#include <stdio.h>
#define PP printf
#include "Circle.h"
#include <string>

void cls()
{
	// Get the Win32 handle representing standard output
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };
	std::cout.flush();

	if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
		abort();
	}
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD written;

	FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);
	FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);
	SetConsoleCursorPosition(hOut, topLeft);
}
void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}
int main()
{
	CONSOLE_SCREEN_BUFFER_INFO csbiData;
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 7;                   // Width of each character in the font 5/9
	cfi.dwFontSize.Y = 14;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	DWORD dwWidth, dwHeightWnd, dwHeightBuf, dwErrCode, dwWidthWnd;
	CHAR* szSysMsg = NULL; //LPTSTR lpszSysMsg = NULL;
	BOOL bRet;
	int** m;
	std::string st="";
	cls();

	HANDLE hWndCon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (FALSE != hWndCon)GetConsoleScreenBufferInfo(hWndCon, &csbiData);
	dwWidth = csbiData.dwSize.X;			 // Ширина буфера / окна
	dwHeightBuf = csbiData.dwSize.Y;		 // Высота буфера
	dwHeightWnd = csbiData.srWindow.Bottom;  // Высота окна
	Circle crcl;

	while (true) {
		hWndCon = GetStdHandle(STD_OUTPUT_HANDLE);
		if (FALSE != hWndCon)GetConsoleScreenBufferInfo(hWndCon, &csbiData);
		if (dwWidth != csbiData.dwSize.X || dwHeightWnd != csbiData.srWindow.Bottom+1) {
			cls();
			dwWidth = csbiData.dwSize.X; // Ширина буфера / окна
			dwHeightWnd = csbiData.srWindow.Bottom+1;
			if (dwHeightWnd >= dwWidth) crcl.setR((dwWidth - 1) / 2);
			else crcl.setR((dwHeightWnd - 1) / 2);


			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			m = crcl.getCirlce();
			for (int i = 0; i < crcl.getR() * 2 + 1; i++) {
				for (int j = 0; j < crcl.getR() * 2 + 1; j++) {
					
					if (m[i][j] == 1) {
						SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY |BACKGROUND_INTENSITY /*| FOREGROUND_GREEN | FOREGROUND_GREEN*/);  // комбинации цветов FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
						setCursorPosition(i * 2, j);
						std::cout << "[]";
					}
					if (m[i][j] == 1) { SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE ); }
				}
			}
			SetConsoleTextAttribute(handle,  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
		}

		//std::wcout << dwHeightWnd  << "|" <<dwWidth;}
	}
}

