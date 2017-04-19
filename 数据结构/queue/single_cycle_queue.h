#pragma once
#include"i_queue.h"

#ifndef _NODE_
#define _NODE_
template<typename T>
struct Node
{
	T data;
	Node *next;
};
#endif

template<typename T>
class Single_cycle_queue :public I_queue<T>
{
private:
	Node<T> *head;
	Node<T> *tail;

public:

	Single_cycle_queue(int cycle_size)
	{
		head = tail = new Node<T>();
		head->next = nullptr;
		for(int i = 0; i < cycle_size - 1; i++)
		{
			Node<T>*new_node = new Node<T>();
			new_node->next = head;
			head = new_node;
		}
		tail->next = head;
		tail = head;
	}

	~Single_cycle_queue()
	{
		int count = 0;
		Node<T> *temp = head->next;
		while( temp != head)
		{
			head->next = temp->next;
			delete temp;
			count++;
			temp = head->next;
		}
		delete head;
		count++;
		printf("The total num of del node is: %d .\n", count);
	}

	virtual bool en_queue(const T &x) override
	{
		if( is_full())
		{
			printf("cycle link queue is full\n");
			return false;
		}
		tail->data = x;
		tail = tail->next;
	}

	virtual bool de_queue() override
	{
		if ( is_empty() )
		{
			printf("cycle link queue is empty\n");
			return false;
		}
		head = head->next;
		return true;
	}

	virtual bool front(T &x) const override
	{
		if (is_empty())
		{
			return false;
		}
		x = head->data;
		return true;
	}

	virtual bool is_empty()  const override
	{
		if (head == tail)
		{
			return true;
		}
		return false;
	}
	virtual bool is_full() const  override
	{
		if(tail->next == head)
		{
			return true;
		}
		return false;
	}
};