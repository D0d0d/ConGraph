#include "Figure.h"
#include <utility>
#include <iostream>

void Figure::setP(std::pair<int, int> p, Dot d)
{
	m.push_back(p);
	dots.push_back(d);
}

void Figure::setP(std::vector<std::pair<int, int>> P, Dot d)
{
	for (std::pair<int, int> p : P) {
		m.push_back(p);
		dots.push_back(d);
	}
}

void Figure::makeLine(std::pair<int, int> d1, std::pair<int, int> d2, Dot d )
{
	int dx = abs(d1.first - d2.first);
	int dy = -abs(d1.second - d2.second);
	int ix = d1.first < d2.first ? 1 : -1;
	int iy = d1.second < d2.second ? 1 : -1;
	int er = dx + dy;
	while (true) {
		setP({ d1.first, d1.second }, d);
		if (d1.first == d2.first && d1.second == d2.second) break;
		int er2 = er * 2;

		if (er2 >= dy) {
			er += dy;
			d1.first += ix;
		}
		if (er2 <= dx) {
			er += dx;
			d1.second += iy;
		}
	}

}

std::vector<std::pair<int, int>> Figure::getM()
{
	return m;
}

std::vector<Dot> Figure::getD()
{
	return dots;
}
