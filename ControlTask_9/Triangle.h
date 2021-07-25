#pragma once
#include <string>

class Triangle
{
public:
	Triangle(double, double, double);
	double getArea();

	class TriagleError
	{
	public:
		TriagleError(double, double, double);
		void printMessage() const;
	private:
		std::string message;
	};

private:
	double _sideA, _sideB, _sideC, _sPerim;
};