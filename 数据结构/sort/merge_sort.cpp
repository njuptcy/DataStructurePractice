#include"../which_to_run.h"
#ifdef _MERGE_SORT_MERGE_
#include<iostream>

#define ARR_LEN(a) (sizeof(a)/sizeof(a[0]))

using namespace std;

void m_merge(int a[], int left1, int right1, int left2, int right2 )
{

	int total_len = (right1 - left1 + 1) + (right2 - left2 + 1);
	//申请长度为临时数组
	int *temp = new int[total_len];
	int i = left1, j = left2;

	int index = 0;
	while(i <= right1 && j <= right2)
	{
		if(a[i] < a[j])
		{
			temp[index++] = a[i++];
		}
		else
		{
			temp[index++] = a[j++];
		}
	}
	while(i <= right1)
	{
		temp[index++] = a[i++];
	}
	while(j <= right2)
	{
		temp[index++] = a[j++];
	}

	i = left1;
	index = 0;
	while (index < total_len)
	{
		a[i++] = temp[index++];
	}
	delete[] temp;

}

void merge_sort(int a[], int left, int right)
{
	if(left >= right)
	{
		return;
	}
	int median = (left + right) / 2;
	merge_sort(a, left, median);
	merge_sort(a, median+1, right);
	m_merge(a, left, median, median+1, right);
}

void wrap_merge_sort(int a[], int len)
{
	merge_sort(a, 0, len-1);
}


int* merge(int a[], int len1, int b[], int len2)
{

	int *temp = new int[len1 + len2];
	int i = 0, j = 0;
	int index = 0;
	while(i < len1 && j < len2)
	{
		if(a[i] < b[j])
		{
			temp[index++] = a[i++];
		}
		else
		{
			temp[index++] = b[j++];
		}
	}
	while(i < len1)
	{
		temp[index++] = a[i++];
	}
	while(j < len2)
	{
		temp[index++] = b[j++];
	}
	return temp;
}

int main()
{
	//int a[] = {1,2,3,4,5,6};
	//int b[] = {2,3};
	//int *result = merge(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]));
	//for(int i = 0; i < sizeof(a)/sizeof(a[0]) + sizeof(b)/sizeof(b[0]); i++)
	//{
	//	cout << result[i] << endl;
	//}
	int a[] = {8,6,4,1,2,3,4,3,2};
	wrap_merge_sort(a, sizeof(a)/sizeof(a[0]));
	int len = ARR_LEN(a);
	cout << "len:"<<len << endl;
	for(int i = 0; i < ARR_LEN(a); i++)
	{
		cout << a[i];
	}
	cout << endl;
	getchar();
}


#endif