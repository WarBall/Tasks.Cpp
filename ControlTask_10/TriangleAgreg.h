#pragma once
#include "Dot.h"

class TriangleA
{
public:
	TriangleA(Dot*, Dot*, Dot*);

	void getSides(double&, double&, double&);
	double getPerimeter();
	double getArea();

private:
	Dot *_line1, *_line2, *_line3;
};
