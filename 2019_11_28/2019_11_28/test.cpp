#if 0
//1到n之间总共出现多少个1
//思路：把数字全部转为字符存在string里，统计string里‘1’的个数

#include<iostream>
using namespace std;
#include<string>


class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		string s = "";

			for (int i = 1; i <= n; ++i)
			{
				int tmp = i;
				while (tmp)
				{
					s += (tmp % 10 + '0');
					tmp /= 10;
				}
			}
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == '1')
				count++;
		return count;
	}
};

int main()
{
	int n = 0;
	cin >> n;
	Solution A;
	cout << A.NumberOf1Between1AndN_Solution(n) << endl;
	return 0;
}

#endif

#if 0

//字符串中第一个只出现一次的字符

#include<iostream>
using namespace std;
#include<vector>
#include<string>

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.empty())
			return -1;
		vector<int> v(256, 0);
		//类似哈希表存储计数
		for (int i = 0; i < str.size(); ++i)
			v[str[i]]++;
		for (int i = 0; i < str.size(); ++i)
		{
			if (v[str[i]] == 1)
				return i;
		}
		return 0;
	}
};

int main()
{
	Solution A;
	string s = "aBcabc";
	cout << A.FirstNotRepeatingChar(s) << endl;
	return 0;
}

#endif

//拼接数字使数字字符串最小


#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		int size = numbers.size();
		if (numbers.empty())
			return "";
		sort(numbers.begin(), numbers.end(), cmp);
		string ret;
		for (int i = 0; i < size; ++i)
			ret += to_string(numbers[i]);
		return ret;
	}
	static bool cmp(int a, int b)
	{
		string s1 = to_string(a) + to_string(b);
		string s2 = to_string(b) + to_string(a);
		return s1 < s2;
	}
};

int main()
{
	Solution A;
	vector<int> v = { 123,321,3,32,31 };
	cout << A.PrintMinNumber(v) << endl;

	return 0;
}