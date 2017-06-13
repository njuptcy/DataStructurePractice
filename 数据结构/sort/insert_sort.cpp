#include"../which_to_run.h"
#ifdef INSERT_SORT
#include<iostream>
using namespace std;
template<typename T>


void insert_sort(T arr[], int len)
{
	int i, j;
	T temp;
	for(i = 1; i < len; i++)
	{
		temp = arr[i];
		//插入的位置应该在第一个比temp小的元素之后
		for(j = i-1; j >= 0 && arr[j] > temp; j--)
		{
			arr[j + 1] = arr[j];
		}
		//离开循环后，j<0||arr[j] <= temp
		arr[j + 1] = temp;
	}
}
int main()
{
	int test_arr[] = {4,2,4,1,3,4};
	insert_sort(test_arr, ARR_LEN(test_arr));
	Arr_utility::print_all(test_arr, ARR_LEN(test_arr));
	getchar();
}
#endif