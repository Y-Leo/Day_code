//幸运的袋子

#if 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

bool isLuck(int add, int mul)
{
	if (add > mul)
		return true;
	return false;
}

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

#endif

#if 0
//手套
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (left[i] * right[i] == 0)
			{
				sum += left[i] + right[i];
			}
			else
			{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};

#endif 