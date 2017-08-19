#include"../which_to_run.h"
#ifdef VIRTUAL_FUNCTION
#include<iostream>
using namespace std;
class Base
{
public:
	virtual void func()
	{
		cout << "Base" << endl;
	}
};
class Derived:public Base
{
public:
	virtual void func()
	{
		cout << "Derived" << endl;
	}
};


//the output is：
//Base
//Derived
//Base
//因为每个包含有虚函数的对象都有一个
//虚函数指针,指向该类所对应的虚函数表
int main()
{
	Base * b = new Base();
	Derived *d = new Derived();
	b->func();
	d->func();

	// b = d;
	// b->func();
	//cout <<d<< endl;
	d = (Derived*)b;
	//cout << d << endl;
	d->func();
	getchar();
	return 0;
};
#endif