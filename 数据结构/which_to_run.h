#pragma once
#ifndef _WHICH_TO_RUN_
#define _WHICH_TO_RUN_
#include<iostream>

//#define _SEQ_LIST_MAIN_
//#define _QUEUE_MAIN_
//#define _STACK_MAIN_
//#define _POLY_MAIN_
//#define _MERGE_SORT_MERGE_
//#define MAX_MIN_SIM
//#define K_MAX_ELE
//#define INSERT_SORT
//#define BUBBLE_SORT
//#define QUICK_SORT
//#define FIND_SUBSTR
//#define KMP_SUBSTR
//#define BINARY_SEARCH
//#define BSTREE
//#define SKIP_LIST

//#define SIMPLE_GRAPH
//#define TWO_DIMENSION_ARR_TEST
//#define STANDARD_CIN


//****************C++ features*****************
//#define C_PLUS_FEATURES_TYPEID_JUDEGE_TEMPLATE_TYPE
//#define VIRTUAL_FUNCTION
//*********************************************


//****************graph*********************
//#define EXTRA_GRAPH_BFS_DFS_TOPOSORT
//#define GRAPTH_INSERT_EXIST_REMOVE
//#define HEAP_CPP
//#define SIMPLE_GRAPH_PRIM_KRUSKAL_DIJKSTRA
//#define SIMPLE_HEAP_MAIN
//#define UFSET_MAIN
//********************************************

#define ARR_LEN(a) (sizeof(a)/sizeof(a[0]))


class Dcout
{
public:
	bool debug;
	Dcout()
	{
		debug = false;
	}
	template<typename T>
	Dcout& operator << (T num)
	{
		if (debug)
		{
			cout << num;
		}
		return *this;
	}
};

class Arr_utility
{
private:
	static Dcout *dcout;
public:
	static Dcout& get_dcout()
	{
		if(dcout == NULL) 
		{
			dcout = new Dcout();
		}
		return *dcout;
	}
	template<typename T>
	static void print_all(T arr[], int len)
	{
		using std::cout;
		using std::endl;
		for(int i = 0; i < len; i++)
		{
			cout << arr[i]<<"  ";
		}
		cout << endl;
	}
};


#endif
