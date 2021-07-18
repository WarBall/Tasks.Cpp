#include "controlTasks_3.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>


int main()
{
    //Task_1
    Point points[5] =
    {
        { Point('a', 5, 11) },
        { Point('b', 3, 4) },
        { Point('c', 12, 4) },
        { Point('d', 15, 7) },
        { Point('e', 10, 15) }
    };
    
    double areaPentagon = 0;

    areaPentagon += areaOfTheTriangle(points[0], points[1], points[2]);
    areaPentagon += areaOfTheTriangle(points[0], points[2], points[3]);
    areaPentagon += areaOfTheTriangle(points[0], points[3], points[4]);

    std::cout << "Площадь пятиугольника: " << areaPentagon;

    //Task_2

}

//Task_1
double areaOfTheTriangle(const Point& a, const Point& b, const Point& c)
{
    double* sidesOfTriangle = new double[3];

    sidesOfTriangle[0] = distancePiont(a, b);
    sidesOfTriangle[1] = distancePiont(a, c);
    sidesOfTriangle[2] = distancePiont(b, c);

    return formulaHerons(sidesOfTriangle);
};

double formulaHerons(const double* sidesOfTriangle)
{
    double halfPerimeter = (sidesOfTriangle[0] + sidesOfTriangle[1] + sidesOfTriangle[2]) / 2;

    return sqrt(halfPerimeter * (halfPerimeter - sidesOfTriangle[0]) * (halfPerimeter - sidesOfTriangle[1]) * (halfPerimeter - sidesOfTriangle[2]));
};

double distancePiont(const Point & a, const Point & b )
{
    return sqrt(pow(a._x - b._x, 2.0) + pow(a._y - b._y, 2.0));
};

//Task_2