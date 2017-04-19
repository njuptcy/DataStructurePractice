#pragma once
#include"I_stack.h"
template<typename T>
class Seq_stack:public I_stack<T>
{
private:
	int max_size;
	T *data;
	int top_index;
public:
	Seq_stack(int m)
	{
		top_index = -1;
		max_size = m;
		data = new T[max_size];
	}
	~Seq_stack()
	{
		delete[]data;
	}
	virtual bool pop()
	{
		if(is_empty())
		{
			return false;
		}
		top_index--;
		return true;
	}
	virtual bool push(const T &x) 
	{
		if(is_full())
		{
			return false;
		}	
		data[++top_index] = x;
		return true;
	}
	virtual bool top(T &x) const override
	{
		if(is_empty())
		{
			return false;
		}
		x = data[top_index];
		return true;
	}
	virtual bool is_empty() const override
	{
		return top_index == -1;
	}
	virtual bool is_full() const override
	{
		return top_index == max_size - 1;
	}
};