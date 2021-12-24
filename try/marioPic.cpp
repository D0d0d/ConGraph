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
#include "Figure.h"/*
int main()
{
	graphConsole GrCon = graphConsole(true);

	Figure F;
	F.makeLine({ 3,0 }, { 8,0 }, { "[]",ForeRed,BackRed }); //LightRed
	F.makeLine({ 2,1 }, { 11,1 }, { "[]",ForeRed,BackRed });

	F.makeLine({ 2,2 }, { 9,2 }, { "[]",ForeYellow,BackYellow });
	F.makeLine({ 1,3 }, { 11,3 }, { "[]",ForeYellow,BackYellow });
	F.makeLine({ 1,4 }, { 12,4 }, { "[]",ForeYellow,BackYellow });
	F.makeLine({ 1,5 }, { 11,5 }, { "[]",ForeYellow,BackYellow });
	F.makeLine({ 3,6 }, { 10,6 }, { "[]",ForeYellow,BackYellow });

	F.makeLine({ 2,7 }, { 8,7 }, { "[]",ForeGreen,BackGreen });
	F.makeLine({ 1,8 }, { 11,8 }, { "[]",ForeGreen,BackGreen });
	F.makeLine({ 0,9 }, { 12,9 }, { "[]",ForeGreen,BackGreen });

	F.makeLine({ 0,10 }, { 12,10 }, { "[]",ForeYellow,BackYellow });
	F.makeLine({ 0,11 }, { 12,11 }, { "[]",ForeYellow,BackYellow });
	F.makeLine({ 0,12 }, { 12,12 }, { "[]",ForeYellow,BackYellow });

	F.makeLine({2,13},{5,13}, { "[]",ForeRed,BackRed });
	F.makeLine({ 8,13 },{ 11,13 }, { "[]",ForeRed,BackRed });

	F.makeLine({ 1,14 }, { 4,14 }, { "[]",ForeGreen,BackGreen });
	F.makeLine({ 8,14 }, { 11,14 }, { "[]",ForeGreen,BackGreen });

	F.makeLine({ 0,15 }, { 4,15 }, { "[]",ForeGreen,BackGreen });
	F.makeLine({ 9,15 }, { 12,15 }, { "[]",ForeGreen,BackGreen });



	F.makeLine({ 2,2 }, { 5,2 }, { "[]",ForeGreen,BackGreen });
	F.makeLine({ 3,2 }, { 3,5 }, { "[]",ForeGreen,BackGreen });
	F.makeLine({ 1,3 }, { 1,5 }, { "[]",ForeGreen,BackGreen });
	F.makeLine({ 7,5 }, { 11,5 }, { "[]",ForeGreen,BackGreen });

	F.setP({ 2,5 }, { "[]",ForeGreen,BackGreen });
	F.setP({ 8,4},{ "[]", ForeGreen, BackGreen });
	F.setP({ 7,2}, { "[]", ForeGreen, BackGreen });
	F.setP({ 7,3 }, { "[]", ForeGreen, BackGreen });

	F.makeLine({ 4,7 }, { 4,13 }, { "[]",ForeLightRed,BackRed });
	F.makeLine({ 5,9 }, { 5,12 }, { "[]",ForeLightRed,BackRed });
	F.makeLine({ 6,9 }, { 6,12 }, { "[]",ForeLightRed,BackRed });
	F.makeLine({ 7,8 }, { 7,13 }, { "[]",ForeLightRed,BackRed });

	F.makeLine({ 3,10 }, { 3,13 }, { "[]",ForeLightRed,BackRed });
	F.makeLine({ 8,10 }, { 8,13 }, { "[]",ForeLightRed,BackRed });

	F.makeLine({ 2,12 }, { 2,13 }, { "[]",ForeLightRed,BackRed });
	F.makeLine({ 9,12 }, { 9,13 }, { "[]",ForeLightRed,BackRed });

	F.setP({ 4,10 }, { "[]",ForeBlack,BackYellow });
	F.setP({ 7,10 }, { "[]",ForeBlack,BackYellow });
	GrCon.setCell(6, 12);
	GrCon.cls();
	GrCon.setMatrix();
	GrCon.setP({ 10,10 }, F.getD(), F.getM());
	GrCon.showScreen();

	_getch();
	
	GrCon.showScreen();
	Sleep(20);
	_getch();
}*/

