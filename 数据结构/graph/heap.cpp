#include"../which_to_run.h"
#ifdef HEAP_CPP
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

void adjust_down(int arr[], int i, int j)
{
	int temp = arr[i];
	int child = 2 * i + 1;
	while (child <= j)
	{
		if (child < j && arr[child + 1] < arr[child])
		{
			child++;
		}
		if (temp < arr[child])
		{
			break;
		}
		else
		{
			arr[(child - 1) / 2] = arr[child];
			child = 2 * child + 1;
		}
	}
	arr[(child - 1) / 2] = temp;
}

void create_heap(int arr[], int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		adjust_down(arr, i, n-1);
	}
}

void adjust_up(int arr[], int j)
{
	int temp = arr[j];
	int dest_index = j;
	while (dest_index > 0 && temp < arr[(dest_index-1)/2])
	{
		arr[dest_index] = arr[(dest_index - 1) / 2];
		dest_index = (dest_index - 1) / 2;
	}
	arr[dest_index] = temp;
}

int main()
{
	int arr[] = {10,8,9,3,5,7,1};
	create_heap(arr,sizeof(arr)/sizeof(sizeof(arr[0])));
	ostream_iterator<int> out_iterator(cout, " ");
	copy(arr, arr +  sizeof(arr)/sizeof(arr[0]),out_iterator);
	cout << endl;

	vector<int> input(arr, arr+sizeof(arr)/sizeof(arr[0]));
	input.push_back(2);
	adjust_up(input.data(),input.size()-1);
	copy(input.begin(), input.end(), out_iterator);
	getchar();
}

#endif
