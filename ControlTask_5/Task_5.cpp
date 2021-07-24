#include "controlTasks_5.h"
#include <iostream>

int main()
{
    //Task_1
    const unsigned int SIZE = 10;
    int arrNum [SIZE];

     enteringArray(arrNum, SIZE);

     std::cout << "Сумма всех элиментов: " << summArray(arrNum, SIZE) << std::endl;
     std::cout << "Среднее значение: " << averageValue(arrNum, SIZE) << std::endl;
     std::cout << "Сумма отрицательных элиментов: " << summNegative(arrNum, SIZE) << std::endl;
     std::cout << "Сумма положительных элиментов: " << summPositive(arrNum, SIZE) << std::endl;
     std::cout << "Сумма элиментов с нечетными индексами: " << summOddIndex(arrNum, SIZE) << std::endl;
     std::cout << "Сумма элиментов с четными индексами: " << summEvenIndex(arrNum, SIZE) << std::endl;
     
     delete[]arrNum;

     //Task_2
     int a[] = {1,2,3,4,5,6,7,2};
     int b[] = {7,6,5,4,3,2,1,3};

     int kc = sizeof(a) / sizeof(a[0]); 
     int* c; 
     
     c = max_vect(kc, a, b); 
     for (int i = 0; i < kc; i++) 
         std::cout << c[i] << " ";

     std::cout << std::endl;

     delete[]c; 

}

//Task_1
void enteringArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << "mas[" << i << "]=";
        std::cin >> arr[i];
    }
}

int summArray(int* arr, int size) 
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

double averageValue(int* arr, int size) 
{
    double average = 0;
     
    for (int i = 0; i < size; i++)
    {
        average += arr[i];
    }

    return average = average / size;
}

int summNegative(int* arr, int size) 
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] <= 0) 
        {
            sum += arr[i];
        }
    }
    return sum;
}

int summPositive(int* arr, int size) 
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int summOddIndex(int* arr, int size) 
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 != 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int summEvenIndex(int* arr, int size) 
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

//Task_2

int* max_vect(int size, int* arr_1, int* arr_2)
{
    int* newArr = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        newArr[i] = arr_1[i] > arr_2[i] ? arr_1[i] : arr_2[i];
    }
    return newArr;
}