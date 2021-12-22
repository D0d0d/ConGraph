#pragma once
#include <vector>
class Elipse
{
private:
	int R1, R2;
	std::vector<std::pair<int, int>> a;
	int x0, y0; // центр окружности 
	void buildElipse();
public:
	void setR1(int r);
	void setR2(int r);
	int getR1();
	int getR2();
	Elipse();
	Elipse(int r1,int r2);
	std::vector<std::pair<int, int>> getElipse();
};

