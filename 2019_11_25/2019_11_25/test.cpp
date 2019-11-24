#if 0

//兔子数
//思路：总数分为两部分，大兔子和不能生育的小兔子
//count = f(n-1)+f(n-2)
//其实就是斐波那契数列

#include<iostream>
using namespace std;

int rabbits(int month)
{
	if (month < 3)
		return 1;
	int count = 0;
	if (month >= 4)
		count = rabbits(month - 1) + rabbits(month - 2);
	else
		count = 2;
	return count;
}

int main()
{
	int month = 0;
	while (cin >> month)
	{
		cout << rabbits(month) << endl;
	}
	return 0;
}

#endif

//字符串通配符

#include<iostream>
using namespace std;
#include<string>

bool Cmp(const char* s, const char* s1)
{
	if (*s == '\0'&&*s1 == '\0')
		return true;
	if (*s == '\0' || *s1 == '\0')
		return false;

	if (*s == '?')
		return Cmp(s + 1, s1 + 1);
	else if (*s == '*')
		return Cmp(s + 1, s1) || Cmp(s + 1, s1 + 1) || Cmp(s, s1 + 1);
	else if (*s == *s1)
		return Cmp(s + 1, s1 + 1);
	return false;
}

int main()
{
	string s;
	string s1;
	while (cin >> s >> s1)
	{
		if (Cmp(s.c_str(), s1.c_str()))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}