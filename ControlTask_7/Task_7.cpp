#include <iostream>
#include <string>
#include "Time.h"
#include "quadraticEquation.h"

int main()
{
    //Task_1
    Time time1 (10, 12, 23);
    showTime(time1);
    Time time2 = inputTime();

    Time time3;

    time3 = time3.addingTime(time1, time2);

    std::cout << "Сумма 2х объектов Time \nHours: " << time3._hours << "\nMinutes: " << time3._minutes << "\nSeconds: " << time3._seconds;

    time3 = time3.subtractingTime(time1, time2);

    std::cout << "Разница 2х объектов Time \nHours: " << time3._hours << "\nMinutes: " << time3._minutes << "\nSeconds: " << time3._seconds;

    //Task_2
    double a, b, c;

    std::cout << "Введите три числа для вычисление корней квадратного уравнения: " << std::endl;

    std::cout << "a = ";
    std::cin >> a;

    std::cout << "\nb = ";
    std::cin >> b;

    std::cout << "\nc = ";
    std::cin >> c;

    std::cout << std::endl;
    rootsQuadEquation roots = quadraticEquation(a, b, c);
    
    roots.printRoots();

}

