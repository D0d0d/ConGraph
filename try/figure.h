#pragma once
#include <vector>
#include "Dot.h"
class Figure
{
private:
	std::vector <std::pair<int, int>> m;
	std::vector<Dot> dots;
public:
	void setP(std::pair<int, int> p, Dot d);
	void setP(std::vector<std::pair<int, int>> P, Dot d);
	void makeLine(std::pair<int, int> d1, std::pair<int, int> d2, Dot d);
	std::vector<std::pair<int, int>> getM();
	std::vector<Dot> getD();

};

