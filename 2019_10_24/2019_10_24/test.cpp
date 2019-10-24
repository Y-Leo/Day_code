#include<iostream>
using namespace std;
#include<string>

string test(string s,string tmps)
{
	if ( NULL == &s)
	{
		return s;
	}
	tmps += s[0];

	string::size_type j;
	for (string::size_type i = 1; i < s.size(); i++)
	{
		for (j = 0; j < tmps.size(); ++j)
		{
			if (tmps[j] == s[i])
				break;
		}
		if (j == tmps.size())
			tmps += s[i];
	}
	return tmps;
}


int main()
{
	string s[128] = { "goole" };
	string tmps("\0");
	for (auto e : tmps)
	{
		cout << e;
	}
	cout << endl;
	
	return 0;
}