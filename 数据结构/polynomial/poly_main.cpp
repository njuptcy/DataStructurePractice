#include"../which_to_run.h"
#ifdef _POLY_MAIN_

#include<iostream>
#include<fstream>
#include"polynomial.h"
using namespace std;

istream & operator >> (istream& in, Poly & p)
{
	while (true)
	{
		int c, e;
		in >> c >> e;
		if (e < 0)
		{
			break;
		}
		p.append(c, e);
	}
	return in;

}
ostream & operator << (ostream & out, const Poly & p)
{
	p.display(out);
	return out;
}

int main()
{
	ifstream in("poly_input.txt");
	Poly* p1 = new Poly();
	in >> *p1;
	cout << *p1 << endl;
	p1->sort();
	cout << *p1 << endl;

	ifstream in2("poly_input2.txt");
	Poly* p2 = new Poly();
	in2 >> *p2;
	cout << *p2 << endl;
	p2->sort();
	cout << *p2 << endl;

	//Copy Elision
	//返回值，并且该值是右值，
	{
		Poly result = *p1 + *p2;
		//
		//Poly result( *p1 + *p2);
		cout << result << endl;
	}
	delete p1;
	delete p2;
	getchar();
}

#endif