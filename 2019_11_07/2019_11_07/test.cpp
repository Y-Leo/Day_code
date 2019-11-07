#if 1

#include<iostream>
using namespace std;
#include<vector>
//牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。牛牛有
//一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个
//数组分为几段排序子序列。

int SortNum()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> arr;
		arr.resize(n + 1);
		long long num = 0;
		for (int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}

		//arr[n] = 0;
		int i = 0;
		while (i<n)
		{
			if (arr[i]<arr[i + 1])
			{
				while (i<n&&arr[i] <= arr[i + 1])
					i++;
				num++;
				i++;
			}
			else if (arr[i] == arr[i + 1])
				i++;
			else
			{
				while (i<n&&arr[i] >= arr[i + 1])
					i++;
				num++;
				i++;
			}
		}
		return num;
	}
}

int main()
{
	cout << SortNum() << endl;
	return 0;
}

#endif

#if 0
//题目：反转字符串（反转字符串里单词）
//分析：1、先对字符串进行整体反转
//      2、再对每个单词进行反转（迭代器向后走，遇到空格反转两个迭代器之间的字符串）
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

string ReverseStr(string& s)
{
	if (s.empty()||s.size()>100)
	{
		return s;
	}
	reverse(s.begin(), s.end());
	auto it = s.begin();
	auto It = s.begin();
	while (it != s.end())
	{
		if (*it == ' ')
		{
			reverse(It, it);
			It = ++it;
		}
		++it;
	}
	reverse(It, s.end());
	return s;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		ReverseStr(s);
		for (auto& e : s)
		{
			cout << e;
		}
		cout << endl;
	}

	return 0;
}
#endif
