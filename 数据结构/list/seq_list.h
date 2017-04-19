#pragma once
#include<iostream>
#include"i_seq_list.h"



//template<class T>
//ostream& operator<<(ostream & out, const I_seq_list<T> &list);
using std::ostream;
template<class T>
ostream& operator<<(ostream & out, I_seq_list<T> &list)
{
	int x;
	for (int i = 0; i < list.length(); i++)
	{
		//out << list.at(i)<<' ';
		//这样使用没有编译错误，但是得到的输出结果不对 
		//out << list.at(i) << "    ";
		if (list.at(i, x))
			out << x << ' ';
		else
			out << "the index at " << i<<" wrong"<< std::endl;
	}
	//out << '\n';
	return out;
}

//template<typename T> class Seq_list;

//template<typename T>
//void func( I_seq_list<T> &a)
//{
//	//std::cout << a.data[0] << std::endl;
//	//std::cout << a.data[0] << std::endl;
//}


template<class T>
class Seq_list : public I_seq_list<T>
{
public :
	Seq_list(int m)
	{
		max_size = m;
		data = new T[max_size];
	}
	~Seq_list()
	{
		delete[] data;
	}
	virtual bool is_empty() const override
	{
		return 0 == n;
	}
	virtual bool is_full() const override
	{
		return n == max_size;
	}
	virtual bool at(int i, T &x) override
	{
		if (i < 0 || i > max_size - 1)
			return false;
		x = data[i];
		return true;
	}

	virtual T& operator[](int i) override
	{
		if(  i < 0 || i > n-1 )
		{
			std::cout << "index overstep the boundary!" << endl;
			return data[0];
		}
		return data[i];
	}
	virtual int search(const T &x) const override
	{
		for(int i = 0; i < max_size; i++)
		{
			if (data[i] == x)
				return i;
		}
		return -1;
	}
	virtual bool insert(int i, const T &x)
	{
		using std::cout;
		using std::endl;
		if (is_full())
		{
			cout << "list is full!" << endl;
			return false;
		}
			
		if (i < -1 || i > n - 1)
			return false;
		for(int j = n - 1; j > i;j--)
		{
			data[j + 1] = data[j];
		}
		data[i + 1] = x;
		n++;
		return true;
	}
	virtual bool remove( int i) override
	{
		using std::cout;
		using std::endl;
		if (is_empty())
		{
			cout << "underflow!" << endl;
			return false;
		}
			
		if (i < 0 || i > n - 1)
			return false;
		/*for( int j = n-1; j > i; j--)
		{
			data[j - 1] = data[j];
		}*/

		for(int j = i + 1; j < n; j++)
		{
			data[j - 1] = data[j];
		}
		n--;
		return true;

	}
private:

	//friend void func<T>(I_seq_list<T> &a);
	//报错
	//friend void func(I_seq_list<T> &a);
	//friend ostream& operator<<(ostream & out, const I_seq_list<T> &list);
	//friend ostream& operator<<(ostream & out, const I_seq_list<T> &list)
	//{
	//	int x;
	//	for (int i = 0; i < list.n; i++)
	//	{
	//		//out << list.at(i)<<' ';
	//		//这样使用没有编译错误，但是得到的输出结果不对
	//		//out << list.at(i) << "    ";
	//		if (list.at(i, x))
	//			out << x << ' ';
	//	}
	//	out << '\n';
	//}
	T *data;
	int max_size;
};
