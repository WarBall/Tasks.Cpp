#include "Triangle.h"
#include "Time.h"
#include <iostream>

int main()
{
	std::cout << "Задайте 3 стороны треугольника\n";
	double a, b, c;
	std::cin >> a >> b >> c;

	try
	{
		Triangle triangle1(a, b, c);
		std::cout << "Площадь треугольника: " << triangle1.getArea();
	}
	catch (const Triangle::TriagleError& err)
	{
		std::cout << "Ошибка: ";
		err.printMessage();
	}

	std::cout << std::endl;
	std::cout << "Введите час, минуту и секунду\n";
	int h, m, s;
	std::cin >> h >> m >> s;

	try
	{
		Time time1(h, m, s);

		time1.printTime();
	}
	catch (const Time::TimeErrorSec &err)
	{
		std::cout << "Ошибка: " << err.message;
	}
	catch (const Time::TimeErrorMin& err)
	{
		std::cout << "Ошибка: " << err.message;
	}
	catch (const Time::TimeErrorHours& err)
	{
		std::cout << "Ошибка: " << err.message;
	}

}