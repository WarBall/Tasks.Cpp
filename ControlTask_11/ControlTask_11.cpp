#include "Time.h"
#include "Point.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort

int main()
{
	Time tim1(1, 23, 19);
	Time tim2(1, 23, 19);
	Time tim3 = tim1 + tim2;
	Time tim4 = tim1 + 12.3;
	Time tim5 = 2.5 + tim2;
	Time tim6 = tim4 - tim1;

	std::string string;

	string = tim1 == tim2 ? "равны" : "не равны";
	std::cout << "Промежутки времени: " << string << std::endl;
	
	string = tim1 != tim3 ? "не равны" : "равны";
	std::cout << "Промежутки времени: " << string << std::endl;

	std::vector<Point> points;
	points.push_back(Point(1, 2));
	points.push_back(Point(10, 12));
	points.push_back(Point(21, 7));
	points.push_back(Point(4, 8));
	std::sort(points.begin(), points.end()); 

	for (auto& point : points)
		std::cout << point << std::endl; 

	return 0;
}

