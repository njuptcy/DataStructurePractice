#include"../which_to_run.h"
#ifdef SIMPLE_GRAPH_PRIM_KRUSKAL_DIJKSTRA
#include<queue>
#include<list>
#include<vector>
#include<iostream>
#include<limits>
#include"UFset.h"
#include"heap.h"
using namespace std;

struct Edge
{

	Edge()
	{

	}
	Edge(int u, int v, int w)
	{
		this->u = u;
		this->v = v;
		this->w = w;
	}
	int u, v, w;
	operator int()
	{
		return w;
	}
};



//使用list与vector实现的简单无向图
struct ENode
{
	/*operator int() const
	{
		return vertex;
	}
	ENode(int v) :vertex(v)
	{
		
	}
	bool operator < (const ENode&b)
	{
		return w < b.w;
	}
	*/

	ENode(int v, int weight) :vertex(v), w(weight)
	{

	}
	int vertex;
	int w;
};
//template<typename T>
class SGraph
{
private:
	int node, edge;
	//vector<list<T>> list;
	vector<list<ENode>> list;
	void dfs(int u, bool *visit)
	{
		if (!visit[u])
		{
			cout << u << " ";
			visit[u] = true;
			for (auto it = list[u].begin(); it != list[u].end(); it++)
			{
				dfs(it->vertex, visit);
			}
		}
	}

	void bfs(int u, bool *visit)
	{
		queue<int> q;
		q.push(u);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			if (!visit[cur])
			{
				cout << cur << " ";
				visit[cur] = true;
				for (auto it = list[cur].begin(); it != list[cur].end(); it++)
				{
					q.push(it->vertex);
				}
			}
		}
	}

	int choose(bool *mark,int *d)
	{
		int min_pos = -1;
		int min = numeric_limits<int>::max();
		for (int i = 0; i < node; i++)
		{
			if (!mark[i] && d[i] < min)
			{
				min = d[i];
				min_pos = i;
			}
		}
		return min_pos;
	}
	void dijkstra(int v, int *d, int *path)
	{
		bool *mark = new bool[node];
		for (int i = 0; i < node; i++)
		{
			mark[i] = false;
		}
		mark[v] = true;
		d[v] = 0;
		for (auto it = list[v].begin(); it != list[v].end(); it++)
		{
			d[it->vertex] = it->w;
			path[it->vertex] = v;
		}
		for (int i = 1; i < node; i++)
		{
			int min_pos = choose(mark, d);
			mark[min_pos] = true;
			for (auto it = list[min_pos].begin(); it != list[min_pos].end(); it++)
			{
				if (!mark[it->vertex])
				{
					int new_d = d[min_pos] + it->w;
					d[it->vertex] = d[it->vertex] < new_d ? d[it->vertex] : new_d;
					path[it->vertex] = min_pos;
				}
			}
		}
		delete[]mark;
	}
public:
	void dijkstra()
	{
		int *d = new int[node];
		//memset(d, numeric_limits<int>::max(), sizeof(int)*node);
		for (int i = 0; i < node; i++)
		{
			d[i] = numeric_limits<int>::max();
		}
		int *path = new int[node];
		memset(path, -1, sizeof(int)*node);
		dijkstra(0, d, path);

		for (int i = 0; i < node; i++)
		{
			cout << d[i] << " ";
		}
		cout << endl;

		for (int i = 0; i < node; i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;

	}
	SGraph(int n) :node(n), edge(0)
	{
		list.resize(n);
	}
	void insert(int u, int v, int w)
	{
		if (u < 0 || u > node - 1 || v < 0 || v > node - 1)
		{
			return;
		}
		//list[u].push_back(v);
		list[u].emplace_back(v,w);
		edge++;
	}
	void dfs()
	{
		bool *visit = new bool[node];
		for (int i = 0; i < node; i++)
		{
			visit[i] = false;
		}
		for (int i = 0; i < node; i++)
		{
			dfs(i,visit);
			cout << endl;
		}
		delete[]visit;
	}

	void bfs()
	{
		bool *visit = new bool[node];
		for (int i = 0; i < node; i++)
		{
			visit[i] = false;
		}
		for (int i = 0; i < node; i++)
		{
			bfs(i, visit);
			cout << endl;
		}
		delete[]visit;
	}

	void topo_sort()
	{
		int* in_degree = new int[node];
		memset(in_degree, 0, sizeof(int)*node);
		for (int i = 0; i < node; i++)
		{
			for (auto it = list[i].begin(); it != list[i].end(); it++)
			{
				in_degree[it->vertex]++;
			}
		}

		int top = -1;
		for (int i = 0; i < node; i++)
		{
			if (0 == in_degree[i])
			{
				in_degree[i] = top;
				top = i;
			}
		}

		for (int i = 0; i < node; i++)
		{
			if (-1 == top)
			{
				cout << "has cycle" << endl;
				delete[] in_degree;
				return;
			}
			cout << top << " ";
			int u = top;
			top = in_degree[top];

			for (auto it = list[u].begin(); it != list[u].end(); it++)
			{
				in_degree[it->vertex]--;
				if (0 == in_degree[it->vertex])
				{
					in_degree[it->vertex] = top;
					top = it->vertex;
				}
			}
		}
		delete[]in_degree;

	}

	void prim(int *lowest_cost, int *nearest)
	{
		bool *in_tree = new bool[node];
		for (int i = 0; i < node; i++)
		{
			in_tree[i] = false;
			lowest_cost[i] = numeric_limits<int>::max();
			nearest[i] = -1;
		}

		int k = 0;
		in_tree[k] = true;
		lowest_cost[k] = 0;
		nearest[k] = 0;

		for (int i = 1; i < node; i++)
		{
			for (auto it = list[k].begin(); it != list[k].end(); it++)
			{
				int v = it->vertex;
				if (!in_tree[v] && it->w < lowest_cost[v])
				{
					lowest_cost[v] = it->w;
					nearest[v] = k;
				}
			}
			k = -1;
			int min = numeric_limits<int>::max();
			for (int i = 0; i < node; i++)
			{
				if (!in_tree[i] && lowest_cost[i] < min)
				{
					k = i;
					min = lowest_cost[i];
				}
			}
			if (-1 == k)
			{
				cout << "could not generate minimun spanning tree" << endl;
				return;
			}
			in_tree[k] = true;
		}
		delete[]in_tree;
	}

	void kruskal()
	{
		heap<Edge> h(edge);
		for (int i = 0; i < node; i++)
		{
			for (auto it = list[i].begin(); it != list[i].end(); it++)
			{
				Edge e(i, it->vertex,it->w);
				h.enqueue(e);
			}
		}
		int k = 0;
		UFSet ufset(node);
		while (k < node - 1 && !h.empty())
		{
			Edge e = h.serve();
			int r_u = ufset.find(e.u);
			int r_v = ufset.find(e.v);
			if (r_u != r_v)
			{
				k++;
				ufset.uf_union(r_u,r_v);
				cout << e.u << " " << e.v << " " << e.w << endl;
			}
		}
		if (k < node - 1)
		{
			cout << "connection wrong" << endl;
		}
	}

	
};

int main()
{
	//SGraph sg(8);

	//sg.insert(0,1);
	//sg.insert(1, 2);
	//sg.insert(2, 3);

	//sg.insert(0, 4);
	//sg.insert(0, 5);
	//sg.insert(0, 6);

	//sg.insert(6, 7);


	//*************************
	//SGraph sg(7);
	//sg.insert(0,4,0);
	//sg.insert(0, 3, 0);
	//sg.insert(1, 3 , 0);
	//sg.insert(2, 3, 0);
	//sg.insert(4, 5, 0);
	//sg.insert(3, 5, 0);
	//sg.insert(5, 6, 0);
	//sg.dfs();
	//cout << "***********" << endl;
	//sg.bfs();
	//cout << "***********" << endl;
	//sg.topo_sort();
	//*************************
	SGraph sg(6);
	sg.insert(0, 3, 5);
	sg.insert(3, 0, 5);

	sg.insert(0, 1, 6);
	sg.insert(1, 0, 6);

	sg.insert(0, 2, 1);
	sg.insert(2, 0, 1);

	sg.insert(1, 2, 5);
	sg.insert(2, 1, 5);

	sg.insert(1, 4, 3);
	sg.insert(4, 1, 3);

	sg.insert(2, 4, 6);
	sg.insert(4, 2, 6);

	sg.insert(2, 3, 5);
	sg.insert(3, 2, 5);

	sg.insert(2, 5, 4);
	sg.insert(5, 2, 4);

	sg.insert(5, 3, 2);
	sg.insert(3, 5, 2);

	sg.insert(5, 4, 6);
	sg.insert(4, 5, 6);

	int nearest[6];
	int lowest_cost[6];
	sg.prim(lowest_cost, nearest);
	for (int i = 0; i < 6; i++)
	{
		cout << nearest[i] << " " << i << " " << lowest_cost[i] << endl;
	}
	cout << "*****************" << endl;
	sg.kruskal();
	cout << "*****************" << endl;
	sg.dijkstra();
	getchar();

}

#endif