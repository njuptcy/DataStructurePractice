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
	while(i < j)
	{
		while (a[i] < par_val) i++;
		while (a[j] > par_val) j--;
		if (i < j)
		{
			swap(a[i], a[j]);
		}
	}
	swap(a[j], a[p]);
	return j;
}

int find_k_max_ele(int a[], int len, int k)
{
	int real_index = len - k;
	int part_index = partition(a, 0, len-1);
	while (part_index != real_index)
	{
		if (part_index < real_index)
		{
			part_index = partition(a, part_index+1, len-1);
		}
		else if (part_index > real_index)
		{
			part_index = partition(a, 0, part_index-1);
		}
	}
	return a[part_index];
}

int main()
{
	int a[] = {5,2,4,1,3};
	int result = find_k_max_ele(a, ARR_LEN(a), 2);
	cout << result << endl;
	getchar();
}


#endif