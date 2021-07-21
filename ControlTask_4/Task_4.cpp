#include "controlTasks_4.h"
#include <iostream>

int main()
{
    double a, b, c, x1, x2;
    int root;

    std::cout << "Введите три числа для вычисление корней квадратного уравнения: " << std::endl;
    
    std::cout << "a = ";
    std::cin >> a;
    
    std::cout << "\nb = ";
    std::cin >> b;
    
    std::cout << "\nc = ";
    std::cin >> c;

    root = myRoot(a, b, c, x1, x2);
    switch (root)
    {
    case -1:
        std::cout << "Корни не найдены или значение а = 0\n";
        break;
    case 0:
        std::cout << "Корни совпадают: ";
        std::cout << "\nx1 = " << x1 << std::endl << "\nx2 = "<< x2;
        break;
    case 1:
        std::cout << "Корни найдены: ";
        std::cout << "\nx1 = " << x1 << std::endl << "\nx2 = " << x2;
        break;
    default:
        std::cout << "Ooops\n";
        break;
    }

    int f, g;
    if (input(f, g) == false) 
    {
        std::cerr << "error";
        return 1;
    }

    int s = f + g;

    return 0;

}


int myRoot(double a, double  b, double c, double& x1, double& x2)
{
    if (a != 0)
    {
        double disc = b * b - 4 * a * c;

        if (disc > 0)
        {
            x1 = (-b + sqrt(disc)) / (2 * a);
            x2 = (-b - sqrt(disc)) / (2 * a);
            return 1;
        }
        else if (disc == 0)
        {
            x1 = x2 = -b / (2 * a);
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
};

bool input(int &a, int &b) 
{
    std::cout << "Введите два числа: \n";
    std::cin >> a >> b;

    if (!std::cin) 
    {
        return 0;
    }
    else {
        return 1;
    }

};