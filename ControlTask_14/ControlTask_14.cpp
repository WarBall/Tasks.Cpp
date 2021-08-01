
#include <iostream>

template <typename T>
T average(T arr[], int size)
{
	T sum = 0;
	for (int i = size-1; i >= 0; --i){sum += arr[i];}

	return (sum / size);
}

int main()
{
	int siz;

	int arr1[] = { 1, 22, 3, 49, 51, 23, 45 };
	siz = sizeof(arr1) / sizeof(arr1[0]);
	std::cout << average(arr1, siz) << std::endl;

	double arr2[] = { 1.2, 22.6, 3.3, 49.2, 51.3, 23.6, 45.8 };
	siz = sizeof(arr2) / sizeof(arr2[0]);
	std::cout << average(arr2, siz) << std::endl;

	char arr3[] = "Char";
	siz = sizeof(arr3) / sizeof(arr3[0]);
	std::cout << average(arr3, siz) << std::endl;

	long arr4[] = { 123123, 2355234, 343523, 14235346 };
	siz = sizeof(arr4) / sizeof(arr4[0]);
	std::cout << average(arr4, siz) << std::endl;

}


