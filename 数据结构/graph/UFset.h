#include<iostream>
class UFSet
{
	int ele_n;
	int *parent;
public:
	UFSet(int n) :ele_n(n)
	{
		parent = new int[n];
		memset(parent, -1, sizeof(int)*n);
	}
	~UFSet()
	{
		delete[]parent;
	}
	int find(int x)
	{
		int r = x;
		while (parent[r] >= 0 )
		{
			r = parent[r];
		}

		if (parent[x] < 0)
		{
			return x;
		}

		int i = x;
		int temp;
		//必须保证该集合至少有两个结点，否则会出错
		while (parent[i] != r)
		{
			temp = parent[i];
			parent[i] = r;
			i = temp;
		}
		return r;
	}

	void uf_union(int x, int y)
	{
		int node_count = parent[x] + parent[y];
		if (parent[x] < parent[y])
		{
			parent[y] = x;
			parent[x] = node_count;
		}
		else
		{
			parent[x] = y;
			parent[y] = node_count;
		}
	}
};