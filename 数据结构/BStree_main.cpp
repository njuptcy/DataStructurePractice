#include"which_to_run.h"
#ifdef BSTREE
#include"bstree.h"
int main()
{
	BSTree<int> bs;
	int result = 0;
	char * r = NULL;
	result = bs.insert(10);
	r = get_result_str(result);
	cout << r << endl;
	result = bs.insert(5);
	r = get_result_str(result);
	cout << r << endl;
	result = bs.insert(15);
	r = get_result_str(result);
	cout << r << endl;
	result = bs.insert(3);
	r = get_result_str(result);
	cout << r << endl;
	result = bs.insert(6);
	r = get_result_str(result);
	cout << r << endl;
	result = bs.insert(8);
	r = get_result_str(result);
	cout << r << endl;
	bs.print_nodes();
	cout <<endl<< "****************" << endl;
	bs.remove(5);
	bs.print_nodes();
	bs.insert(16);
	cout << endl << "******************" << endl;
	bs.printf_nodes();
	getchar();


}
#endif