#pragma once
#include <iostream>
class Point
{
private:
	double _x;
	double _y;
public:
	Point(double x, double y);
	double distanceToCenter();
	bool operator< (Point&);
	friend std::ostream& operator<<(std::ostream&, const Point&);
};