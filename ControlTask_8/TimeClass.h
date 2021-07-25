#pragma once
#include <iostream>

class Time 
{
	public:
		Time();
		Time(int, int, int);
		void printTime() const;
		Time addTime(const Time&);
		int getHours();
		int getMinutes();
		int getSecondss();

	private:
		unsigned int _hours, _minutes, _seconds;
};