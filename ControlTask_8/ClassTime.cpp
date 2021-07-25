#include "Time.h"
#include <iostream>

Time::Time() : _hours(0), _minutes(0), _seconds(0) {}

Time::Time(int h, int m, int s) : _hours(h), _minutes(m), _seconds(s)
{
#define MAXSEC 60
#define MAXMINUT 60

	if (this->_seconds / MAXSEC >= 1)
	{
		this->_minutes += (int)this->_seconds / MAXSEC;
		this->_seconds %= MAXSEC;
	}
	if (this->_minutes / MAXMINUT >= 1)
	{
		this->_hours += (int)this->_minutes / MAXMINUT;
		this->_minutes %= MAXMINUT;
	}
}

Time Time::addTime(const Time& tim1, const Time& tim2) 
{
#define MAXSEC 60
#define MAXMINUT 60

	Time newTime;	

	newTime._seconds = (tim1._seconds + tim2._seconds) >= MAXSEC ?
		(tim1._seconds + tim2._seconds) - MAXSEC | newTime._minutes++ : (tim1._seconds + tim2._seconds);

	newTime._minutes += (tim1._minutes + tim2._minutes) >= MAXMINUT ? 
		(tim1._minutes + tim2._minutes) - MAXMINUT | newTime._hours++ : (tim1._minutes + tim2._minutes);

	newTime._hours += tim1._hours + tim2._hours ;
	
	return newTime;
}

void Time::printTime() const
{
	std::cout << this->_hours << ":" << Time::_minutes << ":" << Time::_seconds <<std::endl;
}

int Time::getHours()
{
	return Time::_hours;
}

int Time::getMinutes()
{
	return Time::_minutes;
}

int Time::getSecondss()
{
	return Time::_seconds;
}