#if 0

//手套
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

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

#if 0
//iNOC产品部--完全数

#include<iostream>
using namespace std;
#include<algorithm>

int PerfectNums(int n)
{
	if (n > 500000 || n < 0)
		return -1;
	int count = 0;
	for (int i = 2; i < n; ++i)
	{
		int ret = 1;
		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (i%j == 0)
			{
				ret += j;
				ret += i / j;
			}
		}
		if (ret == i)
			count++;
	}
	return count;
}


int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << PerfectNums(n) << endl;
	}
	return 0;
}

#endif
