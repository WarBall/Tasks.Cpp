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
	
	Time operator + (const Time&);
	Time operator - (const Time&);
	friend Time operator + (const Time&, float variable);
	friend Time operator + (float variable, const Time&);
	bool operator == (const Time&);
	bool operator != (const Time&);

private:
	int _hours, _minutes, _seconds;
};