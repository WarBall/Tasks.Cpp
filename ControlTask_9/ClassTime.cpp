#include "Time.h"
#include <iostream>

Time::Time() : _hours(0), _minutes(0), _seconds(0) {}

Time::Time(int h, int m, int s) : _hours(h), _minutes(m), _seconds(s)
{
#define MAXSEC 60
#define MAXMINUT 60
#define MAXHOURS 24

	if (this->_seconds > MAXSEC)	
		throw TimeErrorSec();

	if (this->_minutes > MAXMINUT)
		throw TimeErrorMin();

	if(this->_hours > MAXHOURS)
		throw TimeErrorHours();
}

Time Time::addTime(const Time& tim1, const Time& tim2)
{
#define MAXSEC 60
#define MAXMINUT 60
#define MAXHOURS 24

	Time newTime;

	newTime._seconds = (tim1._seconds + tim2._seconds) >= MAXSEC ?
		(tim1._seconds + tim2._seconds) - MAXSEC | newTime._minutes++ : (tim1._seconds + tim2._seconds);

	newTime._minutes += (tim1._minutes + tim2._minutes) >= MAXMINUT ?
		(tim1._minutes + tim2._minutes) - MAXMINUT | newTime._hours++ : (tim1._minutes + tim2._minutes);

	newTime._hours += (tim1._hours + tim2._hours) >= MAXHOURS ? throw TimeErrorHours() : tim1._hours + tim2._hours;

	return newTime;
}

void Time::printTime() const
{
	std::cout << this->_hours << ":" << Time::_minutes << ":" << Time::_seconds << std::endl;
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

Time::TimeErrorHours::TimeErrorHours() : message("Значение часов не может превышать '24'") {}

Time::TimeErrorMin::TimeErrorMin() : message("Значение минут не может превышать '60'"){}

Time::TimeErrorSec::TimeErrorSec() : message("Значение секунд не может превышать '60'") {}