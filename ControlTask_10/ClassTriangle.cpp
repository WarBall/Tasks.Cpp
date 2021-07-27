#include "Triangle.h"
#include <math.h>

Triangle::Triangle(Dot dotA, Dot dotB, Dot dotC) : _line1(dotA), _line2(dotB), _line3(dotC){}

void Triangle::getSides(double &lineA, double &lineB, double &lineC)
{
	lineA = _line1.distanceTo(_line2);
	lineB = _line1.distanceTo(_line3);
	lineC = _line2.distanceTo(_line3);
}

double Triangle::getPerimeter()
{
	return _line1.distanceTo(_line2) + _line1.distanceTo(_line3) + _line2.distanceTo(_line3);
}

double Triangle::getArea()
{
	double halfPerim = getPerimeter()/2;

	return sqrt(halfPerim * (halfPerim - _line1.distanceTo(_line2)) * (halfPerim - _line1.distanceTo(_line3)) * (halfPerim - _line2.distanceTo(_line3)));
}