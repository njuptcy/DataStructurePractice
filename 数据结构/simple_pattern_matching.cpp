#include"which_to_run.h"
#ifdef FIND_SUBSTR
#include<iostream>
#include<string>
using namespace std;
bool simple_pattern_matching(string str, string sub)
{
	for (int i = 0; i < str.size(); i++)
	{
		int j = 0;
		for ( ;j < sub.size(); j++)
		{
			if (sub.at(j) != str.at(i + j))
			{
				break;
			}
		}
		if (j == sub.size())
		{
			return true;
		}
	}
	return false;
}
int main()
{
	string str = "main_str_is_hello_world";
	string sub = "str";
	bool result = simple_pattern_matching(str, sub);
	cout << std::boolalpha;
	cout << result << endl;
	string sub2 = "main2";
	result = simple_pattern_matching(str, sub2);
	cout << result << endl;
	getchar();

}
#endif