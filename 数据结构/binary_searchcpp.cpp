#include"which_to_run.h"
#ifdef BINARY_SEARCH
#include<iostream>
using namespace std;
int binary_search(int arr[], int n, int tar)
{
	int left = 0;
	int right = n-1;
	while (left <= right)
	{
		int median= (left + right)/2;
		if (tar < arr[median])
		{
			right = median-1;
		}
		else if (tar > arr[median])
		{
			left = median+1;
		}
		else
		{
			return median;
		}
	}
	return -1;
}
int main()
{
	int arr1[] = {1,2,2,3,4,5,7,7,8};
	int result = binary_search(arr1, ARR_LEN(arr1), 3);
	cout << result << endl;
	result = binary_search(arr1, ARR_LEN(arr1), 10);
	cout << result << endl;
	int arr2[] = {1,2,2,3,4,5,7,7};
	result = binary_search(arr2, ARR_LEN(arr2), 3);
	cout << result << endl;
	result = binary_search(arr2, ARR_LEN(arr2), 6);
	cout << result << endl;
	int arr3[] = {1,2,3,4,5,7,8};
	result = binary_search(arr3, ARR_LEN(arr3), 4);
	cout << result << endl;
	result = binary_search(arr3, ARR_LEN(arr3), 6);
	cout << result << endl;
	getchar();
}

#endif 