#pragma once
#include <iostream>

struct Time
{
    unsigned int _hours, _minutes, _seconds;

	Time() {}
	Time(int hours, int minutes, int seconds) :_hours(hours), _minutes(minutes), _seconds(seconds){}
 
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

		if (newTime._minutes < tim2._minutes )
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
	enum tim { hou = 23, min=59 };
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