#include "Time.h"
#include <iostream>

int main()
{
    Time time1(1, 70, 63);
    time1.printTime();

    Time time2(12, 53, 99);
    time2.printTime();

    Time time3 = time3.addTime(time1, time2);
    time3.printTime();
}
