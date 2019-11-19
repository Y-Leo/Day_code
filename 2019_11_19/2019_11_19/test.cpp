#if 0

//参数解析

#include<iostream>
using namespace std;
#include<string>

void SeparateStr(string& s)
{
	int i = 0, j = 0;
	for (i; i < s.size(); ++i)
	{
		if (s[i] == '"')
		{
			for (j = i + 1; j < s.size(); ++j)
			{
				if (s[j] != '"')
					cout << s[j];
				else
				{
					cout << endl;
					break;
				}
			}
			if (s[j + 1] != ' ')
				i = j + 1;
			else
				i = j + 2;
		}
		if (s[i] != ' ')
			cout << s[i];
		else
			cout << endl;
	}
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		SeparateStr(s);
		cout << endl;
	}
	return 0;
}
#endif

//跳石板
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

#define Max 100001

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v(m + 1, Max);
		v[n] = 0;
		for (int i = n; i <= m; ++i)
		{
			for (int j = 2; j*j <= i; j++)
			{
				if (i%j == 0)
				{
					if (i + j <= m)
					{
						v[i + j] = min(v[i + j], v[i] + 1);
					}
					if (i + i / j <= m)
						v[i + i / j] = min(v[i + i / j], v[i] + 1);
				}
			}
		}
		if (v[m] == Max)
			cout << "-1" << endl;
		else
			cout << v[m] << endl;
	}
}