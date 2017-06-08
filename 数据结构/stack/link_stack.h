#pragma once
#include"I_stack.h"

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
class Link_stack :public I_stack<T>
{
private:
	Node<T> *head;
public:
	virtual bool pop() override
	{
		if(is_empty())
		{
			return false;
		}
		Node<T> *temp = head->next;
		delete head;
		head = temp;
		return true;
	}
	virtual bool push(const T &x)  override
	{
		Node<T> * new_node = new Node<T>();
		new_node->data = x;
		new_node->next = head;
		head = new_node;
		return true;
	}
	virtual bool top(T &x) const override
	{
		if(is_empty())
		{
			return false;
		}
		x = head->data;
		return true;
	}
	virtual bool is_empty() const override
	{
		return head == nullptr;
	}
	virtual bool is_full() const override
	{
		return false;
	}

};