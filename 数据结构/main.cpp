

#include<iostream>
#include"i_seq_list.h"
#include"seq_list.h"
#include<iostream>

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
	I_seq_list<int> * list = new Seq_list<int>( max_size );
	for(int i = 0; i < max_size; i++)
	{
		list->insert(-1, i);
	}

	func( *list );
	//cout << *list << endl;
	//int x;
	//(*list).at(1,x);
	//cout << x << endl;

	getchar();
	


}

