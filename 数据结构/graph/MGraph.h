#include"Graph.h"
template<typename T>
class MGraph:public Graph
{
public:
	MGraph(int node, const T&ne)
	{
		e = 0;
		n = node;
		noEdge = ne;
		mat = new int*[n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[n];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mat[i][j] = noEdge;
			}
			mat[i][i] = 0;
		}
	}
	~MGraph()
	{
		for (int i = 0; i < n; i++)
		{
			delete[] mat[i];
		}
		delete[] mat;
	}
	bool Insert(int u, int v, const T &w) override
	{
		//不带自回路
		if (u<0 || u>n - 1 || v<0 || v>n - 1 || Exist(u, v) || u == v)
		{
			return false;
		}
		mat[u][v] = w;
		e++;
		return true;
	}
	bool Exist(int u, int v) override
	{
		if (u<0 || u>n - 1 || v<0 || v>n - 1||u == v || mat[u][v] == noEdge)
			return false;
		return true;
	}
	bool Remove(int u, int v) override
	{
		if (u<0 || u>n - 1 || v<0 || v>n - 1 || u == v)
		{
			return false;
		}
		if (mat[u][v] != noEdge)
		{
			e--;
			mat[u][v] = noEdge;
			return true;
		}
		return false;
	}
protected:
	T **mat;
	T noEdge;
};