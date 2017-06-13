#include"../which_to_run.h"
#ifdef MAX_MIN_SIM
#include<iostream>
using namespace std;

int find_max_min(int a[], int len, int&max, int&min)
{
	int compCount = 0;
	max = min = a[0];
	for(int i = 0; i < len - 1; i++)
	{
		compCount++;
		if(a[i] < a[i+1])
		{
			compCount++;
			if(a[i] < min)
			{
				min = a[i];
			}
		}
		else
		{
			compCount++;
			if(a[i] > max)
			{
				max = a[i];
			}
		}
	}
	return compCount;
}


int main()
{
	int a[] = {3,2,1,5,2,1,3};
	int max, min,count;
	count = find_max_min(a,ARR_LEN(a), max, min);
	cout << max << " " <<min << " " << count;
	getchar();
}

#endif