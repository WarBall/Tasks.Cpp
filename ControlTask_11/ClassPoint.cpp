#include "Point.h"
#include <math.h>

Point::Point(double x, double y) : _x(x), _y(y) {}

double Point::distanceToCenter()
{
	return sqrt(pow(this->_x, 2) + pow(this->_y, 2));
}

bool Point::operator< (Point& point)
{
	return Point::distanceToCenter() < point.distanceToCenter() ? true : false;
}
std::ostream& operator<<(std::ostream& os, const Point& point) 
{
	return os << "x: " << point._x << "\t" << "y: " << point._y << std::endl;
}