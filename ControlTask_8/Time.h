#pragma once
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

	private:
		unsigned int _hours, _minutes, _seconds;
};