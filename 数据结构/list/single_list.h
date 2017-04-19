#pragma once
#include<iostream>
#include"i_seq_list.h"
using namespace std;
template<typename T>
struct Node 
{
	T data;
	Node *next;
};


template<typename T>
class Single_list:public I_seq_list<T>
{
private:
	Node<T> *head;

public:
	Single_list()
	{
		head = new Node<T>();
	}
	~Single_list()
	{
		int count = 0;
		Node<T> * p = head;
		Node<T> * q = head;
		while(p != nullptr)
		{
			count++;
			q = p->next;
			delete p;
			p = q;
		}
		printf("the total number of deleted nodes is %d.\n", count);
	}
	virtual bool is_empty() const override
	{
		return head->next == nullptr;
	}
	virtual bool is_full() const override
	{
		return false;
	}
	virtual bool at(int i, T &x) override
	{
		if( i < 0 || i > n-1)
		{
			return false;
		}
		Node<T> * tar = head;
		for(int j = 0; j <= i; j++)
		{
			tar = tar->next;
		}
		x = tar->data;
		return true;
	}
	virtual T& operator[](int i ) override
	{
		if (i < 0 || i > n - 1)
		{
			std::cout << "index overstep the boundary!" << endl;
			return head->data;
		}
		Node<T> *target = head;
		for(int j = 0; j <= i; j++)
		{
			target = target->next;
		}
		return target->data;
		//return data[i];
	}
	virtual int search(const T &x) const override
	{
		int i = 0;
		Node<T> *cur = head->next;
		while( cur != nullptr)
		{
			if( cur ->data == x )
			{
				return i;
			}
			cur = cur->next;
			i++;
		}
		return -1;
	}
	virtual bool insert(int i, const T &x) override
	{
		if (i < -1 || i > n-1)
		{
			return false;
		}
		Node<T> *new_node = new Node<T>();
		new_node->data = x;
		Node<T> * cur = head;
		for (int j = 0; j <= i; j++)
		{			
			cur = cur->next;
		}
		new_node->next = cur->next;
		cur->next = new_node;
		n++;
		return true;
	}
	virtual bool  remove(int i) override
	{
		if( i < 0 || i > n-1)
		{
			return false;
		}
		Node<T> * cur = head;
		Node<T> * pre = head;
		for (int j = 0; j <= i; j++)
		{
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		delete cur;	
		n--;
		return true;
	}
	//virtual int length() { return n; }

};
