#include <iostream>
#include <windows.h>
#include <cwchar>
#pragma comment(lib, "user32")
#include <stdio.h>
#define PP printf
#include "Circle.h"
#include <string>
#include "graphConsole.h"
#include <time.h>

int main()
{

	graphConsole GrCon = graphConsole();
	Circle C(3);
	GrCon.setCell(6,12);
	GrCon.cls();
	GrCon.setMatrix();
	_getch();
	for (int i = 0; i < 15; i++) {
		GrCon.setP(C.getCircle(), 0, {i,i});
		GrCon.setP(C.getCircle(), 1, {i+1, i+1});

		GrCon.setP(C.getCircle(), 0, { 15-i+1,15-i+1 });
		GrCon.setP(C.getCircle(), 1, { 15-i, 15-i });


		GrCon.showScreen();
		Sleep(50);
	}
	_getch();

		//std::wcout << dwHeightWnd  << "|" <<dwWidth;}
}

