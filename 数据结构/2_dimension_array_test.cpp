#include"which_to_run.h"
#ifdef TWO_DIMENSION_ARR_TEST
#include<iostream>
using namespace std;



void print_2d_array(int adj[][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", adj[i][j]);
		}
		cout << endl;
	}

}

void print_2d_array_pp(int **adj, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ", adj[i][j]);
		}
		cout << endl;
	}
}



int main()
{
	int adj[10][10];
	memset(adj, 0, sizeof(adj));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%p  ", &adj[i][j]);
		}
		printf("\n");
	}
	print_2d_array(adj, 10);
	cout << "*************************" << endl;

	int **adj2 = new int*[10];
	for (int i = 0; i < 10; i++)
	{
		adj2[i] = new int[10];
		memset(adj2[i], 0, sizeof(int)*10);
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%p  ", &adj2[i][j]);
		}
		printf("\n");
	}
	print_2d_array_pp(adj2, 10);
	getchar();
	getchar();


}
#endif