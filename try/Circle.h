#pragma once
#include <vector>
class Circle
{
private:
	int R;
	std::vector<std::pair<int, int>> a;
	int x0, y0; // центр окружности 
	void buildCircle();
public:
	void setR(int r);
	int getR();
	Circle();
	Circle(int r);
	std::vector<std::pair<int,int>> getCircle();
};

