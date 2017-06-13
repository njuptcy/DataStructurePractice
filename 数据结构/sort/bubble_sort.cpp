#include"../which_to_run.h"
#ifdef BUBBLE_SORT
#include<algorithm>
#include<iostream>
template<typename T>
void bubble_sort(T arr[], int len)
{
	int i = len - 1;
	int flag;
	while(i > 0)
	{
		flag = 0;
		for(int j = 0; j < i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				flag = j;
				std::swap(arr[j], arr[j+1]);
			}
		}
		i = flag;
	}
}


int main()
{
	int test_arr[] = { 4,2,4,1,3,4 };
	bubble_sort(test_arr, ARR_LEN(test_arr));
	Arr_utility::print_all(test_arr, ARR_LEN(test_arr));
	getchar();
}



#endif