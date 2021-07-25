#include "Triangle.h"
#include <iostream>
#include <string>
#include <math.h>

Triangle::TriagleError::TriagleError(double a, double b, double c)
{
		if (a > b + c)
		{
			TriagleError::message = "Сторона 'a' больше суммы 2х других";
		}
		else if (b > a + c)
		{
			TriagleError::message = "Сторона 'b' больше суммы 2х других";
		}
		else if(c > a + b)
		{
			TriagleError::message = "Сторона 'c' больше суммы 2х других";
		}
}

void Triangle::TriagleError::printMessage() const
{
	std::cout << this -> message << std::endl;
}

Triangle::Triangle(double a, double b, double c) 
{
	if(a > b + c || b > a + c || c > a + b)
	{
		throw TriagleError(a,b,c);
	}
	
	Triangle::_sideA = a;
	Triangle::_sideB = b;
	Triangle::_sideC = c;
	Triangle::_sPerim = (a + b + c) / 2;
}

double Triangle::getArea() 
{
	return sqrt(this->_sPerim*(this->_sPerim-this->_sideA) * (this->_sPerim - this->_sideB) * (this->_sPerim - this->_sideC));
}

