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
    std::cout << "Кубический корень (пример 1): " << cubicRootOne(27) << std::endl;
    std::cout << "Кубический корень (пример 2): " << cubicRootTwo(27) << std::endl;

    //Task_3
    whatTriangle();

    ////Task_4
    std::cout << sumOfNumbers(3);

    //Task_5
    std::cout << binaryView(12);

}

//Task_1
double areaOfTheTriangle(const Point& a, const Point& b, const Point& c)
{
    double sidesOfTriangle[3];

    sidesOfTriangle[0] = distancePiont(a, b);
    sidesOfTriangle[1] = distancePiont(a, c);
    sidesOfTriangle[2] = distancePiont(b, c);

    return formulaHerons(sidesOfTriangle);
};

double formulaHerons(const double * sidesOfTriangle)
{
    double halfPerimeter = (sidesOfTriangle[0] + sidesOfTriangle[1] + sidesOfTriangle[2]) / 2;

    return sqrt(halfPerimeter * (halfPerimeter - sidesOfTriangle[0]) * (halfPerimeter - sidesOfTriangle[1]) * (halfPerimeter - sidesOfTriangle[2]));
};

double distancePiont(const Point & a, const Point & b )
{
    return sqrt(pow(a._x - b._x, 2.0) + pow(a._y - b._y, 2.0));
};

//Task_2

double cubicRootOne(double number)
{
    return pow(number,1.0/3);
};

double cubicRootTwo(double number)
{
    double y = 0.0001, x = 1 , xi = 0;

    do
    {   
        xi = ( (number / (x * x) ) + (2 * x) ) / 3;
        
        if (fabs(xi - x) < y)
            break; 
        
        x = xi;
    } 
    while (true);

    return xi;  
};

//Task_3

void whatTriangle() 
{
    enum triangle{equilTriangle = 1, triangleWith = 2};
    double a, b, c;
    int whatTriangle;

    std::cout << "Введите номер нужного вам треугольник: " << std::endl << "1) Равносторонний" << std::endl << "2) Разносторонний" << std::endl;

    std::cin >> whatTriangle;

    switch (whatTriangle)
    {

        case equilTriangle:
            std::cout << "Введите длину отрезка: " << std::endl;
            std::cin >> a;
            equilateralTriangle(a);
            break;

        case triangleWith:
            std::cout << "Введите длину трех отрезков: " << std::endl;
            std::cin >> a >> b >> c;
            triangleWithDifferentSides(a,b,c);
            break;

        default:
            std::cout << "У нас нет такой фигуры" << std::endl;
            break;
    }

};

void equilateralTriangle(double &a)
{
    double halfPerimeter = (a * 3) / 2;

    double square = sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - a) * (halfPerimeter - a));

    std::cout << "Площадь равностороннего треугольника: " << square << std::endl;
};

void triangleWithDifferentSides(double &a, double &b, double &c)
{
    double halfPerimeter = (a + b + c) / 2;

    double square = sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));

    std::cout << "Площадь разсностороннего треугольника: " << square << std::endl;
};

//Task_4

int sumOfNumbers(int num) 
{
    if (num == 1)
        return 5;

    return num * 5 + sumOfNumbers(num - 1);
};

//Task_5

int binaryView(int num)
{
    if (num == 0)
        return 0;

    return (num % 2 + 10 * binaryView(num / 2));
};