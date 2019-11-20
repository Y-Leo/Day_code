#if 0

//输入一个日期，输出是该年的第多少天

#include<iostream>
using namespace std;
#include<vector>

int countDays(int year, int month, int day)
{
	vector<int> v{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int count = 0;
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		v[2] += 1;
	for (int i = 1; i < month; i++)
	{
		count += v[i];
	}
	return count + day;
}

int main()
{
	int year = 0, month = 0, day = 0;
	while (cin >> year >> month >> day)
	{
		cout << countDays(year, month, day) << endl;
	}
	return 0;
}

#endif


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

bool isLuck(int mul, int add)
{
	if (mul <= add)
		return false;
	return true;
}

int n = 0;
vector<int> v;

int Luckbaggies(int pos, int add, int mul)
{
	int count = 0;
	for (int i = pos; i < v.size(); ++i)
	{
		mul *= v[i];
		add += v[i];

		if (isLuck(mul, add))
			count += 1 + Luckbaggies(i + 1, add, mul);
		else if (v[i] == 1)
			count += Luckbaggies(i + 1, add, mul);
		else
			break;

		add -= v[i];
		mul /= v[i];

		while (v[i + 1] == v[i] && i + 1 < v.size())
		{
			++i;
		}
	}
	return count;
}



int main()
{
	while (cin >> n)
	{
		int pos = 0;
		int add = 0;
		long long mul = 1;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		if (v.empty())
		{
			return 0;
		}
		sort(v.begin(), v.end());
		cout << Luckbaggies(pos, add, mul) << endl;
	}
	return 0;
}