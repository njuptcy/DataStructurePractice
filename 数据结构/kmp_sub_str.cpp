#include"which_to_run.h"
#ifdef KMP_SUBSTR
#include<iostream>
#include<string>
using namespace std;

void kmp_fail(string s, int fail[])
{
	int j = 0, k = -1;
	fail[0] = -1;
	while (j < s.size())
	{
		if (k == -1 || s.at(j) == s.at(k))
		{
			j++;
			k++;
			fail[j] = k;
		}
		else
		{
			k = fail[k];
		}
	}
}

int kmp_substr(string s, string sub, int fail[])
{
	
	int i = 0; 
	int j = 0;
	int n = s.size();
	int m = sub.size();
	while (i < n && j < m)
	{
		if (j == -1 ||s.at(i) == sub.at(j))
		{
			j++;
			i++;
		}
		else
		{
			j = fail[j];
		}
	}
	return j == sub.size() ? 1 : 0;
}

int main()
{
	string s = "abcabc";
	int fail[128];
	kmp_fail(s,fail);
	for (int i = 0; i < s.size(); i++)
	{

		cout << fail[i] << " ";
	}
	cout << endl;
	string ms = "sddabcabcsdfdf";
	int maching = kmp_substr(ms, s, fail);
	cout << "maching:"<<maching << endl;
	getchar();

}

#endif
