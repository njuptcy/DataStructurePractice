#pragma once
#include<iostream>
using namespace std;
#include"i_queue.h"
template<typename T>
class Seq_queue:public I_queue<T>
{
private:
	T *data;
	int max_size;
	int head;
	int tail;
public:
	Seq_queue(int m ) : max_size(m),head(0),tail(0)
	{
		data = new T[max_size];
	}
	~Seq_queue()
	{
		delete[] data;
	}
	virtual bool en_queue(const T&x) override
	{
		if(  is_full() )
		{
			cout << "the queue is full" << endl;
			return false;
		}
		data[tail] = x;
		tail = (tail + 1) % max_size;
	}
	virtual bool de_queue() override
	{
		if(is_empty())
		{
			cout << "the queue is empty,can't dequeue any more" << endl;
			return false;
		}
		head = (head + 1) % max_size;
		return true;
	}
	virtual bool front(T &x) const override
	{
		if(is_empty())
		{
			return false;
		}
		x = data[head];
		return true;
	}
	virtual bool is_empty() const override
	{
		return tail == head;
	}
	virtual bool is_full() const override
	{
		return (tail + 1) % max_size == head;
	}

};