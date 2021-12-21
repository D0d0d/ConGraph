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
	this->m = new Dot*[this->Width];
	for (int i = 0; i < this->Width; i++) {
		this->m[i] = new Dot[this->Height]();
	}
}

graphConsole::graphConsole(bool fullscr)
{
	if (fullscr) {
		SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
		graphConsole();
	}
	else {
		graphConsole();
	}
}

graphConsole::~graphConsole()
{
	for (int i = 0; i < this->Width; i++) {
		delete[] this->m[i];
	}
	delete[] this->m;
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
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			for (int i = 0; i < Width; i++) {
				for (int j = 0; j < Height; j++) {

					SetConsoleTextAttribute(handle, m[i][j].color_b | m[i][j].color_f);
					
					setCursorPosition(i * 2, j);
					std::cout << m[i][j].ch;
					SetConsoleTextAttribute(handle, clrblck); 
				}
			}
			SetConsoleTextAttribute(handle, clrblck);

}

void graphConsole::setMatrix()
{

	for (int i = 0; i < this->Width; i++) {
		delete[] this->m[i];
	}
	delete[] this->m;
	setWinScale();
	this->m = new Dot*[this->Width];
	for (int i = 0; i < this->Width; i++) {
		this->m[i] = new Dot[this->Height]();
	}
}

void graphConsole::setP(std::pair<int, int> cors, Dot p)
{
	m[cors.first][cors.second] = p;
}

void graphConsole::setP(std::pair<int, int> cors, Dot p, std::vector<std::pair<int, int>> P)
{
	for (std::pair<int, int> i : P)
	{
		m[i.first+cors.first][i.second+cors.second] = p;
	}
}
