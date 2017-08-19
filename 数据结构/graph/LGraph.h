#include"Graph.h"
#include<iostream>

template<typename T>
struct ENode
{
	ENode():nextArc(NULL)
	{
	}
	ENode(int a, const T&w, ENode*n) :
		adjVex(a), weight(w), nextArc(n)
	{

	}
	int adjVex;
	T weight;
	ENode * nextArc;
};

template<typename T>
class LGraph :public Graph<T>
{
public:
	LGraph(int n)
	{
		this->n = n;
		this->e = 0;
		list = new ENode<T>*[n];
		for (int i = 0; i < n; i++)
		{
			list[i] = NULL;
		}
	}
	~LGraph()
	{
		ENode<T> *p;
		ENode<T> *temp_next;
		for (int i = 0; i < n; i++)
		{
			p = list[i];
			while (p)
			{
				temp_next = p->nextArc;
				delete p;
				p = temp_next;
			}
		}
		delete[]list;
	}
	bool Insert(int u, int v, const T& w)
	{
		if (u < 0 || u>n - 1 || v<0 || v>n - 1 || u == v)
			return false;
		if (Exist(u, v))
		{
			return false;
		}
		ENode<T> *new_node = new ENode<T>(v, w, list[u]);
		list[u] = new_node;
		e++;
		return true;
	}
	bool Exist(int u, int v)
	{
		if (u < 0 || u > n - 1 || v<0 || v>n - 1 || u == v)
			return false;
		ENode<T> *p = list[u];
		while (p)
		{
			if (p->adjVex == v)
			{
				return true;
			}
			p = p->nextArc;
		}
		return false;
	}
	bool Remove(int u, int v)
	{
		if (u < 0 || u>n - 1 || v<0 || v>n - 1 || u == v)
			return false;
		/*if (!Exist(u, v))
			return false;*/
		ENode<T> *cur = list[u];
		ENode<T> *pre = NULL;
		while (cur)
		{
			if (cur->adjVex == v)
				break;
			pre = cur;
			cur = cur->nextArc;
		}
		if (cur == NULL)
		{
			return false;
		}
		if (pre == NULL)
		{
			list[u] = cur->nextArc;
		}
		else
		{
			pre->nextArc = cur->nextArc;
		}
		delete cur;
		e--;
		return true;
	}
protected:
	ENode<T> **list;
};