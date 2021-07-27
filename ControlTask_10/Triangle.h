#pragma once
#include "Dot.h"

class Triangle
{
public:
	Triangle(Dot, Dot, Dot);
	
	void getSides(double &, double &, double &);
	double getPerimeter();
	double getArea();

private:
	Dot _line1, _line2, _line3;
};
