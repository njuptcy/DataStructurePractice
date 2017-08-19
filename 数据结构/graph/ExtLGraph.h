#include"LGraph.h"
#include<queue>
#include<iostream>

template<typename T>
class ExtLGraph:public LGraph<T>
{
public:
	ExtLGraph(int mSize) :LGraph(mSize)
	{
	}
private:
	void DFS(int u, bool *visit)
	{
		using std::cout;
		if (visit[u])
		{
			return;
		}
		visit[u] = true;
		cout << u << " ";
		ENode<T> *p = list[u];
		while (p)
		{
			DFS(p->adjVex, visit);
			p = p->nextArc;
		}
	}
	void BFS(int cur, bool *visit)
	{
		using std::queue;
		using std::cout;
		using std::endl;
		queue<int> q;
		q.push(cur);
		while (!q.empty())
		{
			int next_node = q.front();
			q.pop();
			if (!visit[next_node])
			{
				cout << next_node <<" ";
				visit[next_node] = true;
				ENode<T> *enode = list[next_node];
				while (enode)
				{
					q.push(enode->adjVex);
					enode = enode->nextArc;
				}
			}
		}
	}
public:
	void BFS()
	{
		using std::cout;
		using std::endl;
		bool *visit = new bool[n];
		for (int i = 0; i < n; i++)
		{
			visit[i] = false;
		}
		for (int i = 0; i < n; i++)
		{
			BFS(i,visit);
			cout << endl;
		}

	}
	void DFS()
	{
		using std::endl;
		using std::cout;
		bool *visit = new bool[n];
		for (int i = 0; i < n; i++)
		{
			visit[i] = false;
		}
		for (int i = 0; i < n; i++)
		{
			DFS(i, visit);
			cout << endl;
		}
	}
	void topo_sort(int *order)
	{
		using std::cout;
		using std::endl;
		int *in_degree = new int[n];
		memset(in_degree,0,sizeof(int) * n);
		ENode<T> *p;
		for (int i = 0; i < n; i++)
		{
			p = list[i];
			while (p)
			{
				int k = p->adjVex;
				in_degree[k]++;
				p = p->nextArc;
			}
		}

		int top = -1;
		for (int i = 0; i < n; i++)
		{
			if (0 == in_degree[i])
			{
				in_degree[i] = top;
				top = i;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (top == -1)
			{
				delete[]in_degree;
				cout << "has cycle" << endl;
				return;
			}
			order[i] = top;
			cout << top << endl;
			ENode<T> *p = list[top];
			top = in_degree[top];
			while (p)
			{
				int k = p->adjVex;
				in_degree[k]--;
				if (in_degree[k] == 0)
				{
					in_degree[k] = top;
					top = k;
				}
				p = p->nextArc;
			}
		}
		delete[]in_degree;
	}
};