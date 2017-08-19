#include"../which_to_run.h"
#ifdef EXTRA_GRAPH_BFS_DFS_TOPOSORT
#include"ExtLGraph.h"
#include"test_macro.h"
#include<iostream>

#define NODE_COUNT 7
int main()
{
	using std::cout;
	using std::endl;
	ExtLGraph<int> lg(NODE_COUNT);

	lg.Insert(0, 1, 1);
	lg.Insert(0, 2, 1);
	lg.Insert(4, 1, 1);
	lg.Insert(3, 2, 1);
	lg.Insert(1, 5, 1);
	lg.Insert(2, 5, 1);
	lg.Insert(5, 6,1);
	/*lg.Insert(4, 1, 1);
	lg.Insert(5, 4, 1);
	lg.Insert(5, 3, 1);
	lg.Insert(6, 5, 1);
	lg.Insert(6, 4, 1);*/

	/*cout << lg.Exist(0, 1) << endl;
	cout << lg.Exist(1, 3) << endl;
	cout << lg.Exist(1, 2) << endl;
	cout << lg.Exist(2, 0) << endl;
	cout << lg.Exist(3, 0) << endl;
	cout << lg.Exist(3, 2) << endl;
	cout << lg.Exist(4, 1) << endl;
	cout << lg.Exist(5, 4) << endl;
	cout << lg.Exist(5, 3) << endl;
	cout << lg.Exist(6, 5) << endl;
	cout << lg.Exist(6, 4) << endl;

	TEST_MACRO(lg.Remove(5, 4));
	TEST_MACRO(lg.Exist(5, 4));
	TEST_MACRO(lg.Exist(5, 3));
	TEST_MACRO(lg.Remove(6, 5));
	TEST_MACRO(lg.Exist(6, 4));*/
	lg.DFS();
	cout << "*******************" << endl;
	lg.BFS();
	cout << "*******************" << endl;
	int order[NODE_COUNT];
	lg.topo_sort(order);
	getchar();
}
#endif