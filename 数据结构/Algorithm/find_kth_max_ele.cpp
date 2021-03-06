#include"../which_to_run.h"

#include<iostream>
using namespace std;
#ifdef K_MAX_ELE
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int a[], int p, int r)
{
	int par_val = a[p];
	int i = p +1 , j = r;
	//while(i < j)
	do
	{
		while (a[i] < par_val) i++;
		while (a[j] > par_val) j--;
		if (i < j)
		{
			swap(a[i], a[j]);
		}
	} while (i < j);
	//if(a[j] <= a[p])
	swap(a[j], a[p]);
	return j;
}

int find_k_max_ele(int a[], int len, int k)
{

	/*
	void quick_sort(int arr[], int left, int right)
	{
	if (left >= right)
	{
	return;
	}
	int i = left;
	int j = right + 1;
	do
	{
	do i++; while (arr[i] < arr[left]);
	do j--; while (arr[j] > arr[left]);
	if ( i < j)
	{
	swap(arr[i], arr[j]);
	}
	} while ( i < j);
	swap(arr[j], arr[left]);
	quick_sort( arr, left, j-1 );
	quick_sort(arr, j +1, right);
	}
	
	*/


	int begin = 0, end = len - 1;
	int real_index = len - k;
	int part_index = partition(a, begin, end);
	//cout << part_index << endl;
	/*Dcout dcout;
	dcout.debug = true;
	dcout << part_index << '\n';*/

	Arr_utility<int>::get_dcout().debug = true;
	Arr_utility<int>::get_dcout() << part_index << "\n";
	Arr_utility<int>::print_all(a, len);

	
	while (part_index != real_index)
	{
		if (part_index < real_index)
		{
			begin = part_index + 1;
			part_index = partition(a, begin, end);
		}
		else if (part_index > real_index)
		{
			end = part_index - 1;
			part_index = partition(a, begin, end);
		}
		cout << "begin:" << begin << ";end:" << end << ";part_index:"<<part_index<<endl;
		Arr_utility<int>::print_all(a,len);
		getchar();
	}
	return a[part_index];
}

int main()
{
	int a[] = {5,2,4,1,3,10000};
	int result = find_k_max_ele(a, ARR_LEN(a)-1, 2);
	cout << result << endl;
	getchar();
}


#endif