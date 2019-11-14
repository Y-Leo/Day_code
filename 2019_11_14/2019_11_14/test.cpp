#if 0
//题目：考拉有n个字符串字符串, 任意两个字符串长度都是不同的
//方法1：根据字符字典排序
//	 例如
//	 car<carriage<cats<doggies
//方法2根据字符串的长度排序。
//   例如
//	 car<cars<doggies<carriage
//	 考拉想知道自己的这些字符串排列顺序是否满足这两种
//输入描述：
//	 第一行为字符串个数n(n≤100)
//	 接下来的n行, 每行一个字符串, 字符串长度均小于100,
//输出描述:
//   如果这些字符串是根据字典序排列而不是根据长度排序islexicalorder
//   如果根据长度排列而不是字典序排列输出lengths
//   如果两种方式都符合输出"both", 否则输出none

#include<iostream>
using namespace std;
#include<vector>
#include<string>

bool is_leng(vector<string>& v)
{
	for (int i = 0; i<v.size() - 1; ++i)
	{
		if (v[i].size()>v[i + 1].size())
			return false;
	}
	return true;
}

bool is_lexi(vector<string>& v)
{
	for (int i = 0; i<v.size() - 1; ++i)
	{
		if (v[i]>v[i + 1])
			return false;
	}
	return true;
}

void judge(int n)
{
	vector<string> v;
	v.resize(n);

	for (int i = 0; i<n; ++i)
	{
		getline(cin, v[i]);
	}

	if (is_leng(v) && is_lexi(v))
		cout << "both" << endl;
	else if (is_leng(v))
		cout << "lengths" << endl;
	else if (is_lexi(v))
		cout << "lexicographically" << endl;
	else
		cout << "none" << endl;
}


int main()
{
	int n = 0;
	while (cin >> n)
	{
		judge(n);
	}
	return 0;
}

#endif


//题目：
//    正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
//输入描述:
//    输入两个正整数A和B。
//输出描述 :
//    输出A和B的最小公倍数。
#include<iostream>
using namespace std;
int LCM(int a, int b)
{
	int Max = a>b ? a : b;
	int Min = a<b ? a : b;
	for (int i = Max; i <= Min*Max; ++i)
	{
		if (i%Max == 0 && i%Min == 0)
		{
			return i;
		}
	}
}

int main()
{
	int A = 0, B = 0;
	while (cin >> A >> B)
	{
		cout << LCM(A, B) << endl;
	}
	return 0;
}