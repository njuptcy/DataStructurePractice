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
class Single_queue: public I_queue<T>
{

private:
	Node<T> *head;
	Node<T> *tail;

public:

	Single_queue()
	{
		head = tail = new Node<T>();
	}

	virtual bool en_queue(const T &x) override
	{
		//attach to tial
		Node<T> * new_node = new Node<T>();
		new_node->data = x;
		new_node->next = nullptr;
		tail->next = new_node;
		tail = new_node;
		//new_node->next = tail;
		//tail = new_node;
		return true;
	}

	virtual bool de_queue() override
	{
		if( is_empty())
		{
			return false;
		}
		Node<T> * temp = head ->next;
		delete head;
		head = temp;
		return true;
	}

	virtual bool front(T &x) const  override
	{
		if(is_empty())
		{
			return false;
		}
		x = (head->next)->data;
		return true;
	}

	virtual bool is_empty()  const override
	{
		if( head == tail )
		{
			return true;
		}
		return false;
	}
	virtual bool is_full() const  override
	{
		return false;
	}

};
