#pragma once
class Dot
{
private:
	double _x;
	double _y;
public:
	Dot();
	Dot(double x, double y);
	double distanceTo(Dot point);
};