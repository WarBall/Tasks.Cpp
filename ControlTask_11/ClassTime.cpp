#include "Time.h"
#include <iostream>

#define MAXSEC 60
#define MAXMINUT 60

Time::Time() : _hours(0), _minutes(0), _seconds(0) {}

Time::Time(int h, int m, int s) : _hours(h), _minutes(m), _seconds(s)
{
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
	Time newTime;

	newTime._seconds = (tim1._seconds + tim2._seconds) >= MAXSEC ?
		(tim1._seconds + tim2._seconds) - MAXSEC | newTime._minutes++ : (tim1._seconds + tim2._seconds);

	newTime._minutes += (tim1._minutes + tim2._minutes) >= MAXMINUT ?
		(tim1._minutes + tim2._minutes) - MAXMINUT | newTime._hours++ : (tim1._minutes + tim2._minutes);

	newTime._hours += tim1._hours + tim2._hours;

	return newTime;
}

void Time::printTime() const
{
	std::cout << this->_hours << ":" << this->_minutes << ":" << this->_seconds << std::endl;
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

Time operator + (const Time& tim, float value)
{
	int h = tim._hours + (int)value;
	int m = tim._minutes + (value - (int)value) * MAXMINUT;
	int s = tim._seconds;

	return Time(h, m, s);
}

Time operator + (float value, const Time& tim)
{
	int s = tim._seconds;
	int m = ((value - (int)value) * MAXMINUT) + tim._minutes;
	int h = (int)value + tim._hours;

	return Time(h, m, s);
}

Time Time::operator + (const Time& tim) 
{
	int s = Time::_seconds + tim._seconds;
	int m = Time::_minutes + tim._minutes;
	int h = Time::_hours + tim._hours;

	if (s > MAXSEC) { s -= MAXSEC; m++; }
	if (m > MAXMINUT) { m -= MAXMINUT; h++; }
	return Time(h, m, s);
}

Time Time::operator - (const Time& tim)
{
	int m = 0, h = 0, s = 0;
	if (Time::_hours > tim._hours) 
	{
		s = (Time::_seconds - tim._seconds) < 0 ? MAXSEC + (Time::_seconds - tim._seconds) | m-- : (Time::_seconds - tim._seconds);
		m += (Time::_minutes - tim._minutes) < 0 ? MAXMINUT + (Time::_minutes - tim._minutes) | h-- : (Time::_minutes - tim._minutes);
		h += Time::_hours - tim._hours;	
	}
	else if (Time::_hours < tim._hours)
	{
		s = (tim._seconds  - Time::_seconds) < 0 ? MAXSEC + (tim._seconds - Time::_seconds) | m-- : (tim._seconds - Time::_seconds);
		m += (tim._minutes - Time::_minutes) < 0 ? MAXMINUT + (tim._minutes - Time::_minutes) | h-- : (tim._minutes - Time::_minutes);
		h += tim._seconds - Time::_hours;
	}
	else if (Time::_hours == tim._hours)
	{
		if (Time::_minutes > tim._minutes)
		{
			s = (Time::_seconds - tim._seconds) < 0 ? MAXSEC + (Time::_seconds - tim._seconds) | m-- : (Time::_seconds - tim._seconds);
			m += (Time::_minutes - tim._minutes);
		}
		if (Time::_minutes < tim._minutes)
		{
			s = (tim._seconds - Time::_seconds) < 0 ? MAXSEC + (tim._seconds - Time::_seconds) | m-- : (tim._seconds - Time::_seconds);
			m += (tim._minutes - Time::_minutes);
		}
		if (Time::_minutes == tim._minutes)
		{
			if(Time::_seconds > tim._seconds)
				s =  Time::_seconds - tim._seconds ;

			else if(tim._seconds <= Time::_seconds)
				s =  tim._seconds - Time::_seconds ;
		}
	}
	return Time(h, m, s);
}

bool Time::operator == (const Time& tim)
{
	return (Time::_hours == tim._hours && Time::_minutes == tim._minutes && Time::_seconds == tim._seconds);
}

bool Time::operator != (const Time& tim)
{
	return (Time::_hours != tim._hours && Time::_minutes != tim._minutes && Time::_seconds != tim._seconds);
}
