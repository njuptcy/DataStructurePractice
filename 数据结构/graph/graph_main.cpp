#include"../which_to_run.h"
#ifdef GRAPTH_INSERT_EXIST_REMOVE
#include"LGraph.h"
#include"test_macro.h"
#include<iostream>
using namespace std;

int main()
{
	LGraph<int> lg(7);

	lg.Insert(0,1,1);
	lg.Insert(1, 3, 1);
	lg.Insert(1, 2, 1);
	lg.Insert(2, 0, 1);
	lg.Insert(3, 0, 1);
	lg.Insert(3, 2, 1);
	lg.Insert(4, 1, 1);
	lg.Insert(5, 4, 1);
	lg.Insert(5, 3, 1);
	lg.Insert(6, 5, 1);
	lg.Insert(6, 4, 1);

	cout << lg.Exist(0, 1) << endl; 
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
	TEST_MACRO(lg.Exist(5,4));
	TEST_MACRO(lg.Exist(5,3));
	TEST_MACRO(lg.Remove(6,5));
	TEST_MACRO(lg.Exist(6,4));

	getchar();
}
#endif