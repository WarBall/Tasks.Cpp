#include <iostream>
#include <string>
#include "controlTasks_2.h"

int main()
{
	//Task_1
	int year;

	std::cout << "Enter the year: ";
	std::cin >> year;

	isItaLeapYear(year);

	//Task_2
	const int dataNumbers = 3;

	double* numbers = new double [dataNumbers];

	std::cout << "Enter three numbers:";
	for (size_t i = 0; i < dataNumbers; i++)
	{
		std::cin >> numbers[i];
	}
	std::cout << "Max number: " << maximumFromThereeNumbers(numbers);

	//Task_3
	double wallet;
	std::cout << "Введите какую сумму вы хотите разменять: \n";
	std::cin >> wallet;
	exchangeOfCoins(wallet);

	//Task_4
	shootingGallery();

}

//Task_1
void isItaLeapYear(int year) 
{
	if (year && (year <= 9999)) 
	{
		std::cout << year << "is it a leap year? \t";
		(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? std::cout << "Yes" : std::cout << "No";
	}
	else
	{
		std::cout << "incorrect date";
	}
}

//task_2
double maximumFromThereeNumbers(double* numbers)
{
	double max;

	if (numbers[0] > numbers[1])
	{
		max = numbers[0] > numbers[2] ? numbers[0] : numbers[2];
	}
	else
	{
		max = numbers[1] > numbers[2] ?  numbers[1] :  numbers[2];
	}

	return max;
}

//Task_3
void exchangeOfCoins(double wallet)
{
	constexpr size_t size = 5;
	const double coins[size] = { 10.0, 5.0, 0.5, 0.1, 0.01 };

	double* exchange = new double[size];

	for (size_t i = 0; i < size; i++)
	{
		exchange[i] = trunc(wallet / coins[i]);
		wallet -= trunc(wallet / coins[i]) * coins[i];
	}

	std::cout << "Монет по 10р.: " << exchange[0] << "\n";
	std::cout << "Монет по 5р.: " << exchange[1] << "\n";
	std::cout << "Монет по 50коп.: " << exchange[2] << "\n";
	std::cout << "Монет по 10коп.: " << exchange[3] << "\n";
	std::cout << "Монет по 1коп.: " << exchange[4] << "\n";
	std::cout << "Остаток: " << wallet;
}

//Task_4
int shoot()
{
	enum scores { zeroScore = 0, oneScore = 1, fiveScore = 5, tenScore = 10 };
	enum target { bullseye = 1 , middle = 4, edge = 9};

	double x, y;
	std::cin >> x >> y;

	if (pow(x, 2.0) + pow(y, 2.0) < bullseye)
	{
		return tenScore; //в яблочко
	}
	else if (pow(x, 2.0) + pow(y, 2.0) < middle)
	{
		return fiveScore; //в центральный круг
	}
	else if (pow(x, 2.0) + pow(y, 2.0) < edge)
	{
		return oneScore; //в наружный круг
	}
	else
	{
		return zeroScore; //miss
	}
}

void shootingGallery()
{
	enum theShooter { sniper = 5, experienced = 12 };

	int numberOfShotsFired = 0, score = 0, scores = 30;

	std::cout << "Test your blind shooting skills: (x.x y.y)\n";

	do
	{
		score += shoot();
		numberOfShotsFired++;
	} while (score != scores);

	if (numberOfShotsFired <= sniper)
	{
		std::cout << "\nAre you a sniper";
	}
	else if (numberOfShotsFired <= experienced)
	{
		std::cout << "\nAre you experienced";
	}
	else 
	{
		std::cout << "\nAre you a beginner";
	}
}