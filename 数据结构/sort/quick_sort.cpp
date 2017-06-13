#include"../which_to_run.h"
#ifdef QUICK_SORT
#include<iostream>
#include<algorithm>
//存在死循环的quick_sort
template<typename T>
void quick_sort_infinite_loop(T arr[], int begin, int end)
{
	int i = begin + 1;
	int j = end;
	if(begin >= end)
	{
		return;
	}
	do
	{
		//当输入序列 2 2 1 1 2（begin 与 i 与 j指向的三个元素都相等时，
		//会造成死循环）
		while (arr[i] < arr[begin]) i++;
		while (arr[j] > arr[begin]) j--;
		if(i < j)
		{
			std::swap(arr[i], arr[j]);
		}
	} while (i < j);
	std::swap(arr[begin], arr[j]);
	//Arr_utility::print_all(arr, end - begin + 1);
	quick_sort(arr, begin, j - 1);
	quick_sort(arr, j+1, end);
}

template<typename T>
void quick_sort(T arr[], int begin, int end)
{
	int i = begin;
	int j = end + 1;
	if(begin >= end)
	{
		return;
	}
	do
	{
		//当输入序列 2 2 1 1 2（begin 与 i 与 j指向的三个元素都相等时，
		//会造成死循环）
		//while (arr[i] < arr[begin]) i++;
		do i++; while ( arr[i] < arr[begin]);
		//while (arr[j] > arr[begin]) j--;
		do j--; while (arr[j] > arr[begin]);
		if(i < j)
		{
			std::swap(arr[i], arr[j]);
		}
	} while (i < j);
	std::swap(arr[begin], arr[j]);
	//Arr_utility::print_all(arr, end - begin + 1);
	quick_sort(arr, begin, j - 1);
	quick_sort(arr, j+1, end);
}



int main()
{
	int arr[] = {4,3,2,1,3,2,2,1,0,10000};
	quick_sort(arr, 0, ARR_LEN(arr) - 2);
	Arr_utility::print_all(arr, ARR_LEN(arr)-1);
	getchar();

}
#endif