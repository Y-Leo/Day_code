#if 0
//1、统计回文
//输入两个字符串，让第二个字符串插入第一个字符串形成回文串，共有多少种插法

//分析：
//遍历字符串一，插入字符串二，判断是否为回文串
#include<iostream>
using namespace std;
#include<string>

bool Palindromic(string& s)
{
	int begin = 0;
	int end = s.size() - 1;
	while (begin<end)
	{
		if (s[begin] != s[end])
		{
			return false;
		}
		end--;
		begin++;
	}
	return true;
}

int main()
{
	string s1, s2, s;
	int count = 0;
	while (cin >> s1 >> s2)
	{
		s = s1;
		int left = 0, right = s1.size();
		while (left <= right)
		{
			s = s1;
			s.insert(right, s2);//s1中插入s2
			if (Palindromic(s))
				count++;
			right--;
		}
		cout << count << endl;
	}
	return 0;
}

#endif

#if 1
//2、连续最大和
//数组中最大连续子数组的和
//
//分析：

#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}
		int ret = v[0];
		int count1 = 0, count2 = 0;
		for (size_t i = 0; i<v.size(); ++i)
		{
			count2 = (count1 >= 0 ? count1 + v[i] : v[i]);
			if (count2>ret)
				ret = count2;
			if (count2<0)
				count2 = 0;
			count1 = count2;
		}
		cout << ret << endl;
	}
	return 0;
}
#endif

