#include "Triangle.h"
#include "TriangleAgreg.h"
#include <iostream>

int main()
{
    //Агрегация
    Dot* d1 = new Dot(2, 3);
    Dot* d2 = new Dot(4, 6);
    Dot* d3 = new Dot(7, 9);
    {
        TriangleA triangle1(d1, d2, d3);

        double lineA, lineB, lineC;

        triangle1.getSides(lineA, lineB, lineC);

        std::cout << "\nДлина отрезка А: " << lineA << "\nДлина отрезка В: " << lineB << "\nДлина отрезка С: " << lineC;

        std::cout << "\nПериметр треугольника: " << triangle1.getPerimeter();

        std::cout << "\nПлощадь треугольника: " << triangle1.getArea();
    }

    std::cout << "Расстояние между точками А и Б: " << d1->distanceTo(*d2) << "Расстояние между точками Б и С" << d2->distanceTo(*d3); ;

    delete d1, delete d2, delete d3;


    //Композиция
    
    Triangle* triangle1 = new Triangle(Dot(2, 3), Dot(4, 6), Dot(7, 9));
    
    double lineA, lineB, lineC;

    triangle1->getSides(lineA, lineB, lineC);

    std::cout << "\nДлина отрезка А: " << lineA << "\nДлина отрезка В: " << lineB << "\nДлина отрезка С: " << lineC;

    std::cout << "\nПериметр треугольника: "<< triangle1->getPerimeter();

    std::cout << "\nПлощадь треугольника: "<< triangle1->getArea();

    delete triangle1;
    
}
