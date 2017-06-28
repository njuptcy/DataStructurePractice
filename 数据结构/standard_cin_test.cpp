#include"which_to_run.h"
#ifdef STANDARD_CIN
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

void func_1()
{
	FILE * file = freopen("standard_cin_test.txt", "r", stdin);
	if(file ==NULL)
	{
		fprintf(stderr, "freopen():error\n");
	}
	int count = 0;
	while(1)
	{
		int i;
		cin >> i;
		if(cin.fail())
		{
			if(cin.eof())
			{
				break;
			}
			else
			{
				//clear后，不正确的输入依然在流中，需要用一个
				//多余的cin操作将其取出
				cin.clear();
				string dummy;
				cin >> dummy;
				cout << boolalpha;
				cout << cin.good() << endl;
				fprintf(stderr, "pick up %s from stream\n", dummy.c_str());
			}

		

		}
		else
		{
			count++;
			cout << "Iteger:  " << count << "  is:" << i<<endl;
		}
	}
	fclose(file);
	freopen("CON", "r", stdin);
}

struct cin_redirect
{
public:
	cin_redirect(std::streambuf *buf)
	{
		old = cin.rdbuf(buf);
	}
	~cin_redirect()
	{
		cin.rdbuf(old);
	}
private:
	std::streambuf *old;
};
void func_2()
{
	string input = "1 test 2 test 3 test 4 test ";
	stringstream ss(input);
	//std::streambuf *old = cin.rdbuf(ss.rdbuf());
	cin_redirect cr(ss.rdbuf());
	int i;
	while(1)
	{
		cin >> i;
		if(cin.fail())
		{
			if (cin.eof())
				break;
			else
			{
				cin.clear();
				string dummy;
				cin >> dummy;
			}
		}
		else
		{
			cout << i << endl;
		}
	}
	//cin.rdbuf(old);
	//getchar();

}
int main()
{
	func_1();
	getchar();
	cout << "***************************" << endl;
	func_2();
	getchar();
}
#endif