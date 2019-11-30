
#if 0
//找出字符串中第一个只出现一次的字符
#include<iostream>
using namespace std;
#include<string>

void FirstOnlyCh(string s)
{
	int hash[256] = { 0 };
	for (int i = 0; i < s.size(); ++i)
		++hash[s[i]];
	int i = 0;
	for (i = 0; i < s.size(); ++i)
		if (hash[s[i]] == 1)
		{
			cout << s[i] << endl;
			break;
		}
	if (i >= s.size())
		cout << "-1" << endl;
}

int main()
{
	string s;
	while (cin >> s)
	{
		FirstOnlyCh(s);
	}
	return 0;
}

#endif

//小易的升级之路
#include<iostream>
using namespace std;
#include<vector>
//辗转相除法求最大公约数
int BiggestCommonDiver(int a, int b)
{
	if (b == 0)
		return a;
	int ret = a % b;
	return BiggestCommonDiver(b, ret);
}

int FinallyPower(int n, int power)
{
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (unsigned long i = 0; i < v.size(); ++i)
	{
		if (v[i] <= power)
			power += v[i];
		else
			power += BiggestCommonDiver(power, v[i]);
	}
	return power;
}

int main()
{
	int n = 0, power = 0;
	while (cin >> n >> power)
	{
		cout << FinallyPower(n, power) << endl;;
	}
	return 0;
}
