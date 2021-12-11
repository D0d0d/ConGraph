#pragma once
class Circle
{
private:
	int R;
	int** a;
	int x0, y0; // центр окружности 
	void buildCircle();
public:
	void setR(int r);
	int getR();
	Circle();
	Circle(int r);
	~Circle();
	int** getCirlce();
};

