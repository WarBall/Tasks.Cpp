#include "pentagon.h"
#include <iostream>
#include <ctime>
#include <math.h>

int main()
{
    int** arrPoints;

    arrPoints = arrayOfPoints();
    areaPentagon(arrPoints);
    
}

int** arrayOfPoints() 
{
    const char ROWS = 5;
    const char COLS = 2;
    unsigned int x, y;

    int** arrPoints = new int* [ROWS];
    for (size_t i = 0; i < ROWS; i++)
    {
        std::cout << "Введите координаты точки P" << 1 + i << ": \n";
        bool firstParameter = true;
        arrPoints[i] = new int[COLS];
        for (size_t j = 0; j < COLS; j++)
        {
            if (firstParameter)
            {
                firstParameter = false;
                std::cout << "x = ";
                std::cin >> x;
                arrPoints[i][j] = x;
            }
            else
            {
                std::cout << "y = ";
                std::cin >> y;
                arrPoints[i][j] = y;
            }
        }
    }
    return arrPoints;
}

void areaPentagon(int** arrPoints) 
{
    const char COLS = 2;

    double area;
    int point_1[COLS] = { arrPoints[0][0], arrPoints[0][1] };
    int point_2[COLS] = { arrPoints[1][0], arrPoints[1][1] };
    int point_3[COLS] = { arrPoints[2][0], arrPoints[2][1] };
    int point_4[COLS] = { arrPoints[3][0], arrPoints[3][1] };
    int point_5[COLS] = { arrPoints[4][0], arrPoints[4][1] };

    area = abs(
          (point_1[0] * point_2[1])
        + (point_2[0] * point_3[1])
        + (point_3[0] * point_4[1])
        + (point_4[0] * point_5[1])
        + (point_5[0] * point_1[1])

        - (point_2[0] * point_1[1])
        - (point_3[0] * point_2[1])
        - (point_4[0] * point_3[1])
        - (point_5[0] * point_4[1])
        - (point_1[0] * point_5[1])
           ) / 2;
    std::cout << "Площадь пятиугольника: " << area;
}