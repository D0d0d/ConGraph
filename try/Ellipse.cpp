#include "Ellipse.h"

void Elipse::setR1(int r)
{
	this->R1 = r;
	this->x0 = this->R1;
}
void Elipse::setR2(int r)
{
	this->R2 = r;
	this->y0 = this->R2;
}
int Elipse::getR1()
{
	return this->R1;
}
int Elipse::getR2()
{
	return this->R2;
}
Elipse::Elipse()
{
	this->R1 = 2;
	this->R1 = 3;
	this->x0 = this->R1; this->y0 = this->R2;
}

Elipse::Elipse(int r1, int r2)
{
	this->R1 = r1;
	this->x0 = this->R1;
	this->R2 = r2;
	this->y0 = this->R2;
}


std::vector<std::pair<int, int>> Elipse::getElipse()
{
	this->buildElipse();
	return this->a;
}

void Elipse::buildElipse()
{
	int x = 0, y = this->R2;
	int sqr_r1 = R1 * R1;
	int sqr_r2 = R2 * R2;
	int del = 4 * sqr_r2 * ((x + 1) * (x + 1)) + sqr_r2 * ((2 * y - 1) * (2 * y - 1)) - 4 * sqr_r1 * sqr_r2;  // 1 - 2 * R;
	while (sqr_r1 * ( 2* y -1) > 2*sqr_r2*(x+1)) {
		a.push_back({ this->x0 + x,this->y0 + y });
		a.push_back({ this->x0 - x,this->y0 + y });
		a.push_back({ this->x0 + x,this->y0 - y });
		a.push_back({ this->x0 - x,this->y0 - y });

		if (del < 0) {
			x++;
			del += 4 * sqr_r2 * (2 * x + 3);
		}
		else {
			x++;
			del= del- 8 * sqr_r1 * (y - 1) + 4 * sqr_r2 * (2 * x + 3);
			y--;
		}
		del = sqr_r2 * ((2 * x + 1) * (2 * x + 1)) + 4 * sqr_r1 * ((y + 1) * (y + 1)) - 4 * sqr_r1 * sqr_r2;
		while (y + 1 != 0) // Вторая часть дуги, если не выполняется условие первого цикла, значит выполняется a^2(2y - 1) <= 2b^2(x + 1)
		{
			a.push_back({ this->x0 + x,this->y0 + y });
			a.push_back({ this->x0 - x,this->y0 + y });
			a.push_back({ this->x0 + x,this->y0 - y });
			a.push_back({ this->x0 - x,this->y0 - y });
			if (del < 0) // Переход по вертикали
			{
				y--;
				del += 4 * sqr_r1 * (2 * y + 3);
			}
			else // Переход по диагонали
			{
				y--;
				del = del - 8 * sqr_r2 * (x + 1) + 4 * sqr_r1 * (2 * y + 3);
				x++;
			}
		}
	}
}
