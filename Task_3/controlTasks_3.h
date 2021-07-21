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
double formulaHerons(const double * pesidesOfTrianglerim);
double distancePiont(const Point& a, const Point& b);

double formulaHerons(const double* pesidesOfTrianglerim);
double formulaHerons(const double* pesidesOfTrianglerim);

double cubicRootOne(double number);
double cubicRootTwo(double number);

void whatTriangle();
void equilateralTriangle(double &a);
void triangleWithDifferentSides(double &a, double &b, double &c);

int sumOfNumbers(int num);

int binaryView(int num);