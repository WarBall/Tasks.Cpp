#pragma once
#include<string>

class Time
{
public:
	Time();
	Time(int, int, int);
	Time addTime(const Time&, const Time&);
	void printTime() const;
	int getHours();
	int getMinutes();
	int getSecondss();

	class TimeErrorHours
	{
	public:
		TimeErrorHours();
		std::string message;
	};

	class TimeErrorMin
	{
	public:
		TimeErrorMin();
		std::string message;
	};

	class TimeErrorSec
	{
	public:
		TimeErrorSec();
		std::string message;
	};

	
private:
	unsigned int _hours, _minutes, _seconds;
};