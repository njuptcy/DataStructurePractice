#include"../which_to_run.h"
#ifdef C_PLUS_FEATURES_TYPEID_JUDEGE_TEMPLATE_TYPE
#include<iostream>
#include<typeinfo>
using namespace std;

template<typename T>
class Seq
{
	T * data;
};

template<typename T>
void func( Seq<T> & s )
{
	int bytes = sizeof(T);
	printf("The size of T is %d\n", bytes);

	// type_info inf = typeid(T);
	// printf("the type of T is %s\n", type_info.name());
	printf("the type of T is %s\n", typeid(T).name());

}
int main()
{
	Seq<int> s;
	func(s);
	getchar();
}
#endif