#include <iostream>
#include <windows.h>
#include <cwchar>
#pragma comment(lib, "user32")
#include <stdio.h>
#define PP printf
#include "Circle.h"
#include "Ellipse.h"
#include <string>
#include "graphConsole.h"
#include <time.h>

int main()
{
	graphConsole GrCon = graphConsole(true);
	Circle C(3);
	Elipse E(4, 3);
	GrCon.setCell(6,12);
	GrCon.cls();
	GrCon.setMatrix();
	_getch();
	while (true) {
		for (int i = 0; i < 6; i++) {
			GrCon.setP({ 10 + i - 1,5 + i - 1 }, { "  ",ForeBlack,BackBlack }, C.getCircle());// верх
			GrCon.setP({ 15 - i + 1,5 + 6 + i - 1 }, { "  ",ForeBlack,BackBlack }, E.getElipse());
			GrCon.setP({ 10 - i + 1,5 + 10 - i + 1 }, { "  ",ForeBlack,BackBlack }, C.getCircle());// низ
			GrCon.setP({ 5 + i - 1,5 + 4 - i + 1 }, { "  ",ForeBlack,BackBlack }, E.getElipse());


			GrCon.setP({ 10 + i,5 + i }, { "[]",ForeBlack,BackRed }, C.getCircle());
			GrCon.setP({ 15 - i,5 + 6 + i }, { "##",ForeWhite,BackPurple }, E.getElipse());
			GrCon.setP({ 10 - i, 5 + 10 - i }, { "[]",ForeBlack,BackRed }, C.getCircle());
			GrCon.setP({ 5 + i,5 + 4 - i }, { "##",ForeWhite,BackPurple }, E.getElipse());

			GrCon.showScreen();
			Sleep(40);

		}
		GrCon.setP({ 15,10 }, { "  ",ForeBlack,BackBlack }, C.getCircle());

		GrCon.setP({ 5, 10 }, { "  ",ForeBlack,BackBlack }, C.getCircle());

		GrCon.setP({ 10,16 }, { "  ",ForeBlack,BackBlack }, E.getElipse());

		GrCon.setP({ 10,4 }, { "  ",ForeBlack,BackBlack }, E.getElipse());
	}
	GrCon.showScreen();
	Sleep(20);
	_getch();
}

