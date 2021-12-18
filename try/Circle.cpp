#include "Circle.h"
void Circle::setR(int r)
{
	this->R = r;
	this->x0 = this->R; this->y0 = this->R;
}
int Circle::getR()
{
	return this->R;
}
Circle::Circle()
{
	this->R = 2;
	this->x0 = this->R; this->y0 = this->R;
}

Circle::Circle(int r)
{
	this->R = r;
	this->x0 = this->R; this->y0 = this->R;
}


std::vector<std::pair<int, int>> Circle::getCircle()
{
	this->buildCircle();
	return this->a;
}

void Circle::buildCircle()
{
	int x = 0, y = this->R;

	int del = 2 * (1 - this->R);  // 1 - 2 * R;
	while (y >= x) {
		a.push_back({this->x0 + x,this->y0 + y});
		a.push_back({ this->x0 + y,this->y0 + x });    //
		a.push_back({ this->x0 - x,this->y0 + y });
		a.push_back({ this->x0 - y,this->y0 + x });    //
		a.push_back({ this->x0 + x,this->y0 - y });
		a.push_back({ this->x0 + y,this->y0 - x });    //
		a.push_back({ this->x0 - x,this->y0 - y });
		a.push_back({ this->x0 - y,this->y0 - x });    //

		if (del < 0) {
			int er = 2 * (del + y) - 1;
			if (er <= 0) {
				x++;
				del += 2 * x + 1;
				continue;
			}
		}
		if (del > 0) {
			int er = 2 * (del - x) - 1;
			if (er > 0) {
				y--;
				del += 1 - 2 * y;
				continue;
			}
		}
		x++; y--;
		del += 2 * (x - y);
	}
}
