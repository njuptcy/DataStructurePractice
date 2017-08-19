#include<iostream>
using namespace std;

template<typename T>
class heap
{
private:
	int ele_n;
	int ele_max;
	T *arr;

	void adjust_down(int i, int j)
	{
		T temp = arr[i];
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
		T temp = arr[j];
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
		arr = new T[max];
	}
	~heap()
	{
		delete[]arr;
	}

	T serve()
	{
		if (0 == ele_n)
		{
			cout << "the prior queue is empty" << endl;
			return T();
		}
		T result = arr[0];
		arr[0] = arr[ele_n - 1];
		ele_n--;
		adjust_down(0,ele_n-1);
		return result;
	}
	bool enqueue(T x)
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
	bool empty()
	{
		return ele_n == 0;
	}
};