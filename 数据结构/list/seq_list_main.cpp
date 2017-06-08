#include"../which_to_run.h"
#ifdef _SEQ_LIST_MAIN_
#include<iostream>
#include"i_seq_list.h"
#include"seq_list.h"
#include<iostream>
#include"single_list.h"
//using namespace std;
//
//ostream& operator<<(ostream & out, const Seq_list<int> &list)
//{
//	
//}

//void func(Seq_list<T> &a)
//{
//	std::cout << a.data[0] << std::endl;
//	std::cout << a.data[0] << std::endl;
//}


int main()
{

	using std::cout;
	using std::endl;
	const int max_size = 10;
	//I_seq_list<int> * list = new Seq_list<int>( max_size );
	I_seq_list<int> * list = new Single_list<int>();


	if (list->is_empty())
	{
		cout << "list is empty" << endl;
	}
	for (int i = 0; i < max_size; i++)
	{
		list->insert(-1, i);
	}
	for (int i = max_size; i > 0; i--)
	{
		list->insert(-1, i);
	}
	cout << "before sort:" << endl;
	list->display();
	cout << "after sort:" << endl;
	list->sort();
	list->display();
	int index = list->search(0);
	//cout << "the index of 0 is:"<<
	printf("the index of %d is %d\n", 0, index);


	//func( *list );
	cout << *list << endl;
	list->insert(max_size - 1, max_size - 1);
	if (list->is_full())
	{
		cout << "the list is full" << endl;
	}

	printf("the list->length() is %d\n", list->length());
	cout << *list << endl;
	list->remove(2);
	printf("the list->length() is %d\n", list->length());
	cout << *list << endl;
	//int x;
	//(*list).at(1,x);
	//cout << x << endl;
	cout << (*list)[0] << endl;
	(*list)[0] = 100;
	cout << (*list)[0] << endl;
	delete list;
	getchar();

}

#endif