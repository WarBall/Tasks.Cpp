#pragma once
#include <string>
#include <vector>

struct Point
{
    char _name;
    double _x, _y;
    Point(char name,double x, double y) :_name(name), _x(x), _y(y) {}
};

double areaOfTheTriangle(const Point& a, const Point& b, const Point& c);
double formulaHerons (const double * pesidesOfTrianglerim);
double distancePiont(const Point& a, const Point& b);