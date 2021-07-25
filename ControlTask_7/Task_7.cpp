#include <iostream>
#include <string>

//Task_1
struct Time
{
	unsigned int _hours, _minutes, _seconds;

	Time() : _hours(0), _minutes(0), _seconds(0) {}
	Time(int hours, int minutes, int seconds) :_hours(hours), _minutes(minutes), _seconds(seconds) {}

	Time addingTime(const Time& tim1, const Time& tim2)
	{
		Time newTime
		(
			tim1._hours + tim2._hours,
			tim1._minutes + tim2._minutes,
			tim1._seconds + tim2._seconds
		);


		if (newTime._seconds > 59)
		{
			newTime._seconds -= 60;
			newTime._minutes++;
		}

		if (newTime._minutes > 59)
		{
			newTime._minutes -= 60;
			newTime._hours++;
		}

		return newTime;
	}

	Time subtractingTime(const Time& tim1, const Time& tim2)
	{
		Time newTime(tim1._hours, tim1._minutes, tim1._seconds);

		if (newTime._seconds < tim2._seconds)
		{
			--newTime._minutes;
			newTime._seconds += 60;
		}

		if (newTime._minutes < tim2._minutes)
		{
			--newTime._hours;
			newTime._minutes += 60;
		}

		newTime._seconds -= tim2._seconds;
		newTime._minutes -= tim2._minutes;
		newTime._hours -= tim2._hours;

		return newTime;
	}
};

Time inputTime()
{
	enum tim { hou = 23, min = 59 };
	unsigned int hours, minutes, seconds;

	do
	{
		std::cout << "\nВведите часы(от 0 до 23): \t";
		std::cin >> hours;

		std::cout << "\nВведите минуты(от 0 до 59): \t";
		std::cin >> minutes;

		std::cout << "\nВведите секунды(от 0 до 59): \t";
		std::cin >> seconds;

		if (hours <= hou && minutes <= min && seconds <= min) {
			break;
		}
		else
		{
			std::cout << "\n\nВведены некорекные данные, повторите попытку!!!\n\n";
		}


	} while (true);


	return Time(hours, minutes, seconds);
};

void showTime(const Time& tim)
{
	int sec;
	sec = tim._hours * 3600 + tim._minutes * 60 + tim._seconds;
	std::cout << "Время в секундах: " << sec;
};

//Task_2
struct rootsQuadEquation
{
	double _x1, _x2;
	rootsQuadEquation(double x1, double x2) : _x1(x1), _x2(x2) {}

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
	rootsQuadEquation roots(0, 0);

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