#include"../which_to_run.h"
#ifdef UFSET_MAIN
#include<iostream>
#include<iterator>
#include<algorithm>

using namespace std;
class UFSet
{
public:
	UFSet(int m) : max_size(m)
	{
		parent = new int[m];
		for (int i = 0; i < m; i++)
		{
			parent[i] = -1;
		}
	}
	~UFSet()
	{
		delete parent;
	}
	int find(int x)
	{
		int r = x;
		for (; parent[r] >= 0; r = parent[r]);
		if (r != x)
		{
			int l = x;
			while (parent[l] != r)
			{
				int t = parent[l];
				parent[l] = r;
				l = t;
			}
		}
		return r;
	}
	void ufset_union(int x, int y)
	{
		int temp = parent[x] + parent[y];
		if (parent[x] <= parent[y])
		{
			parent[y] = x;
			parent[x] = temp;
		}
		else
		{
			parent[x] = y;
			parent[y] = temp;
		}
	}
	void display()
	{
		ostream_iterator<int> out_it(cout, " ");
		copy(parent, parent + max_size, out_it);
	}
private:
	int max_size;
	int *parent;
};

int main()
{
	UFSet union_set(7);
	union_set.ufset_union(union_set.find(0),union_set.find(1));
	union_set.ufset_union(union_set.find(2), union_set.find(3));
	union_set.ufset_union(union_set.find(3), union_set.find(0));
	union_set.ufset_union(union_set.find(4), union_set.find(5));
	union_set.ufset_union(union_set.find(6), union_set.find(5));
	union_set.display();
	getchar();
}
#endif
