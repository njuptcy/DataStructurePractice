#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

#include"I_DynamicSet.h"
template<typename T>
struct Node
{
	Node(const T &d)
	{
		data = d;
		left=right= NULL;
	}
	T data;
	Node *left;
	Node *right;
};


template<typename T>
class BSTree:public I_DynamicSet<T>
{
public:
	BSTree()
	{
		root = NULL;
	}
	~BSTree()
	{

	}
	int search(const T& tar) override
	{
		int result = 0;
		Node<T> *p = root;
		while (p)
		{
			if (tar < p->data)
			{
				p = p->left;
			}
			else if (tar > p->data)
			{
				p = p->right;
			}
			else
			{
				result |= SUCCESS;
				return result;
			}
		}
		result |= FAILURE;
		return result;
	}
	int insert(const T&tar) override
	{
		int result = 0;
		Node<T> *p = NULL;
		Node<T> *c = root;
		while (c != NULL)
		{
			if (tar <c->data)
			{
				p = c;
				c = c->left;
			}
			else if(tar > c->data)
			{
				p = c;
				c = c->right;
			}
			else
			{
				result |= FAILURE;
				result |= DUMPLICATE;
				return result;
			}
		}
		Node<T> *new_node = new Node<T>(tar);
		if (p == NULL)
		{
			root = new_node;
			result |= SUCCESS;
			return result;
		}
		else if(tar < p->data)
		{
			p->left = new_node;
		}
		else
		{
			p->right = new_node;
		}
		result |= SUCCESS;
		return result;
	}
	int remove(const T&tar)
	{
		//cout << "not implement yet" << endl;
		//return 0;
		int result = 0;
		Node<T> *cur, *par;
		Node<T>*r_cur, *r_par;
		cur = root;
		par = NULL;
		while (cur != NULL)
		{
			par = cur;
			if (tar < cur->data)
			{
				cur = cur->left;
			}
			else if (tar > cur->data)
			{
				cur = cur->right;
			}
			else
			{
				break;
			}
		}
		if (cur == NULL)
		{
			result |= NOTEXIST;
			return result;
		}
		if (cur->left && cur->right)
		{
			r_par = cur;
			r_cur = cur->right;
			while (r_cur->left)
			{
				r_par = r_cur;
				r_cur = r_cur->left;
			}
			cur->data = r_cur->data;
			cur = r_cur;
			par = r_par;
		}
		Node<T> *temp;
		if (cur->left)
		{
			temp = cur->left;
		}
		else
		{
			temp = cur->right;
		}
		if (cur == root)
		{
			root = temp;
		}
		else if (cur == par->left)
		{
			par->left = temp;
		}
		else
		{
			par->right = temp;
		}
		delete cur;
		result |= SUCCESS;
		return result;
	}
	bool is_empty() override
	{
		return root == NULL;
	}
	bool is_full() override
	{
		return false;
	}
	void print_nodes()
	{
		queue<Node<T>*> q;
		queue<int> lev_q;
		q.push(root);
		lev_q.push(0);
		int pre_level = -1;
		bool first_line = true;
		while (!q.empty())
		{
			
			int child_count = 0;
			Node<T> *np = q.front();
			int level = lev_q.front();
			q.pop();
			lev_q.pop();
			if (level != pre_level)
			{
				pre_level = level;
				if (!first_line)
				{
					cout << endl;
				}
			}
			first_line = false;
			cout << np->data<<" ";
			if (np->left)
			{
				child_count++;
				q.push(np->left);
			}
			if (np->right)
			{
				child_count++;
				q.push(np->right);
			}
			while (child_count--)
			{
				lev_q.push(level + 1);
			}
		}
	}
	void printf_nodes()
	{

	}
private:
	Node<T>* root;
};
