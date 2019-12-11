//пртк╣д╢Эвс


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int n;
vector<int> v;

int Luckbaggies(int pos, int add, long long mul)
{
	int count = 0;
	for (int i = pos; i < n; ++i)
	{
		mul *= v[i];
		add += v[i];

		if (add > mul)
			count += 1 + Luckbaggies(i + 1, add, mul);
		else if (v[i] == 1)
			count += Luckbaggies(i + 1, add, mul);
		else
			break;

		add -= v[i];
		mul /= v[i];

		while (v[i + 1] == v[i] && i + 1 < n)
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
		cout << Luckbaggies(0, add, mul) << endl;
	}
	return 0;
}
