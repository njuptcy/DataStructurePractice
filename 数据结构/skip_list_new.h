#pragma once
#include"I_DynamicSet.h"
#include<random>
template<typename T>
struct SNode
{
	SNode(int mSize)
	{
		links = new SNode<T>*[mSize];
	}

	~SNode()
	{
		delete[] links;
	}
	SNode<T>** links;
	T data;
};


template<typename T>
class SkipList
{
public:
	SkipList(const T& max_guard, int max_l)
	{
		head = new SNode<T>(max_l+1);
		max_levels = max_l;
		levels = 0;
		tail = new SNode<T>(0);
		tail->data = max_guard;
		for (int i = 0; i < max_l; i++)
		{
			head->links[i] = tail;
		}
		last = new SNode<T>*[max_l + 1];
	}
	SNode<T>* search(const T&x)
	{
		if (x >= tail->data)
		{
			return NULL;
		}
		int result = 0;
		SNode<T> *p = head;
		for (int i = levels; i >= 0; i--)
		{
			while (p->links[i] < x)
			{
				p = p->links[i];
			}
		}
		if (p->links[0] == x)
		{
			return p->links[0];
			//result |= SUCCESS;
			//return result;
		}
		else
		{
			return NULL;
		}
	}
	int insert(const T &x)
	{ 
		int result = 0;
		if (x >= tail->data)
		{
			result |= OUTOFRANGE;
			return result;
		}
		SNode<T>* p = saveSearch(x);
		if (p->data == x)
		{
			result |= DUMPLICATE;
			return result;
		}
		int ran_lev = random_level();
		if (ran_lev > levels)
		{
			ran_lev = ++levels;
			last[ran_lev] = head;
		}
		SNode<T>* new_node = new SNode<T>(ran_lev+1);
		new_node->data = x;
		for (int i = 0; i <= ran_lev; i++)
		{
			new_node->links[i] = last[i]->links[i];
			last[i]->links[i] = new_node;
		}
		result |= SUCCESS;
		return result;
	}
	int remove(const T&x)
	{
		int result = 0;
		SNode<T>*p = saveSearch(x);
		if (p->data != x)
		{
			result |= NOTEXIST;
			return result;
		}
		for (int i = 0; i <= levels && last[i]->links[i] == p; i++)
		{
			last[i]->links[i] = p->links[i];
		}
		while (levels >= 0 && head->links[levels] == tail)
		{
			levels--;
		}
		delete p;
		result |= SUCCESS;
		return result;
	}
private:
	int random_level()
	{
		int rl = 0;
		std::random_device rd;
		std::default_random_engine re(rd());
		std::uniform_int_distribution<int> ud(0,1);
		while (ud(re) == 0)
		{
			rl++;
		}
		return rl > max_levels ? max_levels : rl;
	}
	SNode<T>* saveSearch(const T& x)
	{
		SNode<T> *p = head;
		for (int i = levels; i >= 0; i--)
		{
			while (p->links[i] < x)
			{
				p = p->links[i];
			}
			last[i] = p;
		}
		return p->links[0];
	}
	SNode<T> *head;
	SNode<T> *tail;
	int levels;
	int max_levels;
	SNode<T> **last;
};
