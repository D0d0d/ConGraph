#include "graphConsole.h"
void graphConsole::setWinScale() {
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hWndCon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (FALSE != hWndCon)GetConsoleScreenBufferInfo(hWndCon, &csbi);
	Width = csbi.dwSize.X/2; //csbi.dwSize.X;
	Height = csbi.srWindow.Bottom;

}
graphConsole::graphConsole()
{
	setWinScale();
	this->m = new int*[this->Width];
	for (int i = 0; i < this->Width; i++) {
		this->m[i] = new int[this->Height]();
	}
}

void graphConsole::cls()
{
	// Get the Win32 handle representing standard output
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

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

void graphConsole::setCell(int x, int y)
{
	cell.cbSize = sizeof(cell);
	cell.nFont = 0;
	cell.dwFontSize.X = x;                   // Width of each character in the font 5/9
	cell.dwFontSize.Y = y;                  // Height
	cell.FontFamily = FF_DONTCARE;
	cell.FontWeight = FW_NORMAL;
	wcscpy_s(cell.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cell);
}

void graphConsole::setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void graphConsole::showScreen()
{
	palette[0] = "  "; palette[1] = "[]";
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			for (int i = 0; i < Width; i++) {
				for (int j = 0; j < Height; j++) {

					if (m[i][j] == 1) {
						SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY /*| FOREGROUND_GREEN | FOREGROUND_GREEN*/);  // комбинации цветов FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
					};
						setCursorPosition(i*2, j);
						std::cout << palette[m[i][j]];
					if (m[i][j] == 1) { SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); }
				}
			}
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void graphConsole::setMatrix()
{

	for (int i = 0; i < this->Width; i++) {
		delete[] this->m[i];
	}
	delete[] this->m;
	setWinScale();
	this->m = new int*[this->Width];
	for (int i = 0; i < this->Width; i++) {
		this->m[i] = new int[this->Height]();
	}
}

void graphConsole::setP(std::pair<int, int> P, int p)
{
	m[P.first][P.second] = p;
}

void graphConsole::setP(std::vector<std::pair<int, int>> P, int p, std::pair<int, int> cor)
{
	for (std::pair<int, int> i : P)
	{
		m[i.first+cor.first][i.second+cor.second] = p;
	}
}
