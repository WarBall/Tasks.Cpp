#include <math.h>
#include "Dot.h"

Dot::Dot(): _x(0), _y(0){}

Dot::Dot(double x, double y) : _x(x), _y(y) {}

double Dot::distanceTo(Dot point)
{
	return sqrt(pow(this->_x - point._x, 2) + pow(this->_y - point._y, 2));
}
