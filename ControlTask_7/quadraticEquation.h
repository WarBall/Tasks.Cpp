#pragma once
#include <iostream>

struct rootsQuadEquation
{
	double _x1, _x2;
    rootsQuadEquation(double x1,double x2) : _x1(x1),_x2(x2) {}

    void printRoots()
    {
        if (_x1 == 0 && _x2 == 0)
            std::cout << "Корни уронения не найдены" << std::endl;
        else if (_x1 == _x2 && _x1 != 0)
            std::cout << "Корни уовнения найдены: x1 = x2= " << _x1 << std::endl;
        else if (_x1 != _x2)
            std::cout << "Корни уовнения найдены: x1 = " << _x1 << "\tx2 = " << _x2 << std::endl;
    }
};

rootsQuadEquation quadraticEquation(double a, double  b, double c)
{
    rootsQuadEquation roots(0,0);

    if (a != 0)
    {
        
        double disc = b * b - 4 * a * c;

        if (disc > 0)
        {
            roots._x1 = (-b + sqrt(disc)) / (2 * a);
            roots._x2 = (-b - sqrt(disc)) / (2 * a);
            return roots;
        }
        else if (disc == 0)
        {
            roots._x1 = roots._x2 = -b / (2 * a);
            return roots;
        }
        else
        {
            return roots;
        }
    }

    return roots;
};