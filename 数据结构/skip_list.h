#pragma once
#include"I_DynamicSet.h"
#include<random>

template<typename T>
struct SNode
{
	SNode(int mSize)
	{
		link = new SNode*[mSize];
	}
	~SNode()
	{
		delete[] link;
	}
	SNode **link;
	T element;
};

template<typename T>
class SkipList
{
public:
	SkipList(const T& guard, int maxLev)
	{
		//当前head的最大level index
		level = 0;
		//最大支持的level index
		maxLevel = maxLev;
		head = new SNode(maxLev+1);
		tail = new SNode(0);
		last = new SNode*[maxLev+1];
		tail->element = guard;
		for (int i = 0; i <= maxLev; i++)
		{
			head->link[i] = tail;
		}
	}
	int search(const T&tar)
	{
		int result = 0;
		if (tar >= tail->element)
		{
			result |= OUTOFRANGE;
			result |= FAILURE;
			return result;
		}
		SNode<T> *p = head;
		for (int i = level; i >= 0; i--)
		{
			while (p->link[i]->element < tar)
			{
				p = p->link[i];
			}
		}
		if (p->link[0]->element == tar)
		{
			result |= SUCCESS;
			return result;
		}
		else
		{
			result |= NOEXIST;
			return result;
		}

	}
	
	int insert(const T &x)
	{
		int result = 0;
		if (x >= tail->element)
		{
			result |= OUTOFRANGE;
			result |= FAILURE;
			return result;
		}
		SNode<T> * p = saveSearch(x);
		if (p->element == x)
		{
			result |= DUMPLICATE;
			return result;
		}
		int ran_lev = random_level();
		if (ran_lev > level)
		{
			ran_lev = ++level;
		}
		SNode<T> *new_node = new SNode(ran_lev + 1);
		new_node->element = x;
		for (int i = 0; i <= ran_lev; i++)
		{
			new_node->link[i] = last[i]->link;
			last[i]->link = new_node;
		}

	}
	int remove(const T&tar)
	{
		int result = 0;
		if (tar >= tail->element)
		{
			result |= NOTEXITS;
			result |= FAILURE;
			return result;
		}
		SNode<T>*p = saveSearch(tar);
		if (p->element != tar)
		{
			result |= NOEXIST;
			result |= FAILURE;
			return result;
		}
		for (int i = 0; i <= level && last[i]->link[i] == p; i++)
		{
			last[i]->link = p->link[i];
		}
		while (level > 0 && head->link[level] == tail)
		{
			level--;
		}
		delete p;
		result |= SUCCESS;
		return result;
	}
private:
	SNode<T> * head, *tail;
	SNode<T> **last;
	int maxLevel, level;


	int random_level()
	{
		int level = 0;
		std::random_device rd;
		std::default_random_engine e(rd());
		std::uniform_int_distribution d(0, 1);
		while (d(e) == 0)
		{
			level++;
		}
		level = level > maxLevel ? maxLevel : level;
		return level;
	}
	int saveSearch(const T& tar)
	{
		SNode<T> *p = head;
		for (int i = level; i >= 0; i--)
		{
			while (p->link[i]->element < tar)
			{
				p = p->link[i];
			}
			//last记录新结点要插在哪些结点的后面
			last[i] = p;
		}
		return p->link[0];
	}
};
