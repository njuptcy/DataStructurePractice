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

	void sort() override
	{
		if(head->next == nullptr || head->next->next == nullptr)
		{
			return;
		}
		
		
		int until = 100000;
		while(until != 0)
		{
			Node<T> * cur = head->next;
			Node<T> * pre = head;
			int i = 0;
			int flag = 0;
			while (cur->next != nullptr && i < until)
			{
				if (cur->data > cur->next->data)
				{
					flag = i;
					Node<T> * next_cur = cur->next;
					pre->next = next_cur;
					cur->next = next_cur->next;
					next_cur->next = cur;
				}
				else
				{
					cur = cur->next;
				}
				pre = pre->next;
				i++;
			}
			until = flag;
			cout << until << endl;
			display();
		}
		
		/*
		while( until > 1)
		{
			pre = head;
			cur = head->next;
			int flag = 1;
			int i = 0;
			while( i < until)
			{
				if( cur->data > cur->next->data)
				{
					Node<T>*next_cur = cur->next;
					pre->next = next_cur;
					cur->next = next_cur->next;
					next_cur->next = cur;
				}
				else
				{
					cur = cur->next;
				}
				pre = pre->next;
				i++;
			}
		}
*/



	}


	//指针操作有个问题，until指针指向的结点原来是第2个元素，但是对它进行了重新
	//连接后，或许他就变成了第一个元素了
	//所以可以考虑用计数的方式
	//void sort() override
	//{
	//	//Node<T> *data_head = head->next;
	//	if( head->next == nullptr || head ->next->next == nullptr )
	//	{
	//		return;
	//	}

	//	//until极until之后的元素是有序的
	//	Node<T>*until = nullptr;

	//	while(  until != head -> next ->next)
	//	{
	//		Node<T> * pre_cur = head;
	//		Node<T>* flag = nullptr;
	//		Node<T> * cur = head->next;
	//		while(cur->next != until)
	//		{
	//			Node<T> *cur_next = cur->next;
	//			if(  cur->data > cur_next->data)
	//			{					
	//				pre_cur->next = cur_next;
	//				cur->next = cur_next->next;
	//				cur_next->next = cur;	
	//				pre_cur = pre_cur->next;
	//				flag = cur;
	//			}
	//			else
	//			{
	//				pre_cur = pre_cur->next;
	//				cur = cur_next;
	//			}
	//		}
	//		if(flag != nullptr)
	//		{
	//			until = flag;
	//		}
	//		else
	//		{
	//			until = head->next->next;
	//		}
	//		
	//	}


	//}

	void display() const override
	{
		Node<T> * cur = head->next;
		while(cur != nullptr)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}

	//virtual int length() { return n; }

};
