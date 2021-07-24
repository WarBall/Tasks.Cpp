#include "controlTasks_6.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string writ;

    //Task_1
    #define SIZE 300
    
    const char fdelim = '\t';
    std::string filePath_1 = "verses.txt";
    char buffer[SIZE];

    std::cout << "Введите стих(чтобы сохранить тектс нажмите TAB затем ENTER) \n";
    std::cin.get(buffer, SIZE, fdelim);
    
    writ = writengVerse(filePath_1, buffer) ? "Запись успешно завершена\n" : "Произошла ошибка при записи\n";

    std::cout << writ;

    //Task_2
    #define N 10
    
    std::string filePath_2 = "arrays.txt";
    
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    
    writ = writingArray(filePath_2, a, N) ? "Запись успешно завершена\n" : "Произошла ошибка при записи\n";
    std::cout << writ;

    sortingByChoice(a,N);

    writ = writingArray(filePath_2, a, N) ? "Запись успешно завершена\n" : "Произошла ошибка при записи\n";
    std::cout << writ;
}


bool writengVerse(std::string filePath, const char* buffer)
{
    std::ofstream out(filePath);
    if (out.is_open()) 
    {
        out << buffer << std::endl;
        out.close();
        return true;
    }
    else
    {
        return false;
    }
}

bool writingArray(std::string filePath, const int* arr,const int size)
{
    std::ofstream out(filePath, std::ios::app);
    if (out.is_open())
    {
        for (size_t i = 0; i < size; i++)
        {
            out << arr[i] << "\t";
        }
        out << std::endl;
        out.close();
        return true;
    }
    else
    {
        return false;
    }
}

void sortingByChoice(int* arr, const int size)
{
    int min = 0; 
    int buf = 0;

    for (size_t i = 0; i < size; i++)
    {
        min = i;
        for (size_t j = i+1; j < size; j++)
        {
            min = (arr[j] < arr[min]) ? j : min;
        }

        if (i != min)
        {
            buf = arr[i];
            arr[i] = arr[min];
            arr[min] = buf;
        }
    }
}