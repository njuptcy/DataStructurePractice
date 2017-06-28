#include"which_to_run.h"
#ifdef SIMPLE_GRAPH
#include<sstream>
#include<queue>
#include<iostream>
using namespace std;


void dfs(int **adj, int n ,bool visit[],int a)
{
	cout << a << endl;
	visit[a] = true;
	for(int b = 0; b < n; b++)
	{
		if(adj[a][b] && !visit[b])
		{
			dfs(adj, n , visit, b);
		}
	}
}

void bfs(int ** adj, int n, bool visit[], int a)
{
	queue<int> q;
	q.push(a);
	while(!q.empty())
	{
		int cur_node = q.front();
		cout << cur_node << endl;
		visit[cur_node] = true;
		q.pop();
		for(int i = 0; i < n;i++)
		{
			if(adj[cur_node][i] && !visit[i])
			{
				q.push(i);
			}
		}
	}
}

int main()
{
	/*const int n = 10;
	int adj[10][10];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			adj[i][j] = 0;
		}
	}*/
	//freopen("dfs.txt","r",stdin);
	const int n = 5;
	int **adj = new int*[n];
	for(int i = 0; i < n;i++)
	{
		adj[i] = new int[n];
		memset(adj[i], 0, sizeof(int)*n);
	}

	string input = "0 1 1 2 2 3 3 4 4 0";
	stringstream ss(input);
	streambuf *old = cin.rdbuf(ss.rdbuf());
	int a, b;
	//cout << cin.good() << endl;
	while(cin >> a>>b)
	{
		adj[a][b] = 1;
	}
	
	bool visit[n];
	for(int i = 0; i < n ;i++)
	{
		visit[i] = false;
	}
	dfs(adj, n, visit, 0);
	/*cout << cin.good() << endl;
	cin.clear();
	cout << cin.good() << endl;
	char ch = getchar();
	cout << ch << endl;
	ch = getchar();
	cout << ch << endl;
	ch = getchar();
	cout << ch << endl;
	ch = getchar();
	cout << ch << endl;*/
	cin.rdbuf(old);
	cout << "*****************" << endl;
	cout << "press enter to test bfs" << endl;
	getchar();
	for(int i = 0; i < n; i++)
	{
		visit[i] = false;
	}
	bfs(adj, n, visit, 0);
	getchar();
	//getchar();
	
}
#endif