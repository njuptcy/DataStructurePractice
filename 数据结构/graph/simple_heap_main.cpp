#include"../which_to_run.h"
#ifdef SIMPLE_HEAP_MAIN
#include<iostream>
using namespace std;

class heap
{
private:
	int ele_n;
	int ele_max;
	int *arr;

	void adjust_down(int i, int j)
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
			arr[(child - 1) / 2] = arr[child];
			child = 2*child + 1;
		}
		arr[(child - 1) / 2] = temp;
	}


	void adjust_up(int j)
	{
		int temp = arr[j];
		while (j > 0)
		{
			if (arr[(j - 1) / 2] < temp)
			{
				break;
			}
			else
			{
				arr[j] = arr[(j - 1) / 2];
				j = (j - 1) / 2;
			}
		}
		arr[j] = temp;
	}
public:
	heap(int max) :ele_max(max)
	{
		arr = new int[max];
	}
	~heap()
	{
		delete[]arr;
	}

	int serve()
	{
		if (0 == ele_n)
		{
			cout << "the prior queue is empty" << endl;
			return -1;
		}
		int result = arr[0];
		arr[0] = arr[ele_n - 1];
		ele_n--;
		adjust_down(0,ele_n-1);
		return result;
	}
	bool enqueue(int x)
	{
		if (ele_n == ele_max)
		{
			cout << "the prior queue is full" << endl;
			return false;
		}
		arr[ele_n] = x;
		adjust_up(ele_n);
		ele_n++;
	}
};
int main()
{

	heap h(10);
	h.enqueue(20);
	h.enqueue(3);
	h.enqueue(4);
	h.enqueue(10);
	h.enqueue(34);
	h.enqueue(14);
	h.enqueue(44);
	cout << h.serve() << endl;
	cout << h.serve() << endl;
	cout << h.serve() << endl;
	cout << h.serve() << endl;
	cout << h.serve() << endl;
	cout << h.serve() << endl;
	cout << h.serve() << endl;
	cout << h.serve() << endl;
	getchar();


}
#endif