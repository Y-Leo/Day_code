#if 0
//杨辉三角的变形

#include<iostream>
using namespace std;
#include<vector>

vector<vector<int>> CreatTriangle(int n)
{
	vector<vector<int>> v(n, vector<int>(2 * n + 1, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2 * i + 1; ++j)
		{
			//第一行置为1
			if (i == 0 || i == 1)
				v[i][j] = 1;
			//第一列置为1
			else if (j == 0)
				v[i][j] = 1;
			//第二列只有两个数可加
			else if (j == 1)
				v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
			else
				v[i][j] = v[i - 1][j] + v[i - 1][j - 1] + v[i - 1][j - 2];
		}
	}
	return v;
}


int findEvenIndex(int n)
{
	vector<vector<int>> v = CreatTriangle(n);
	for (int i = 0; i < 2 * n + 1; ++i)
	{
		if (v[n - 1][i] % 2 == 0)
		{
			return (i + 1);
		}
	}
	return -1;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << findEvenIndex(n) << endl;
	}
	return 0;
}

#endif

//长整形数字相加

#include<iostream>
using namespace std;
#include<string>
#include<algorithm> 

string AddLongInteger(string s1, string s2)
{
	string s = "";
	int i = s1.size() - 1;
	int j = s2.size() - 1;

	//从后往前按位加
	int cur = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			cur += (s1[i] - '0');
		if (j >= 0)
			cur += (s2[j] - '0');
		s += (char)(cur % 10 + '0');
		cur /= 10;
		i--;
		j--;
	}

	if (cur == 1)
		s += '1';

	//整体逆置
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << AddLongInteger(s1, s2) << endl;
	}
	return 0;
}


