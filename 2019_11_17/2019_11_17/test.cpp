#if 0
//题目一：求最大连续bit数

#include<iostream>
using namespace std;

int countByte(int n)
{
	int max = 0;
	int cur = 0;
	for (int i = 0; i<32; i++)
	{
		if ((n & 1) == 1)
			cur++;
		else
		{
			max = max>cur ? max : cur;
			cur = 0;
		}
		n = n >> 1;
	}
	return max;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << countByte(n) << endl;
	}
	return 0;
}

#endif

#if 0
//输入两个数，返回最大最小值的方法
#include<iostream>
using namespace std;
#include<algorithm>

int main()
{
	int a = 1, b = 2;
	//1、通过库函数，注意头文件包含
	cout << min(a, b) << endl;
	cout << max(a, b) << endl;

	//2、通过三目运算符
	int Max = a > b ? a : b;
	int Min = a < b ? a : b;
	cout <<Max << endl;
	cout <<Min << endl;
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<algorithm>

class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		if (a == b)
			return a;
		int Max = max(a, b);
		int Min = min(a, b);
		while (Min>1)
		{
			if (seekroot(Max) != Min)
			{
				int tmp = seekroot(Max);
				Max = max(seekroot(Max), Min);
				Min = min(Min, tmp);
			}
			else
			{
				return Min;
			}
		}
		return 1;
	}
public:
	int seekroot(int n)
	{
		if (n % 2 == 0)
			return n / 2;
		else
			return (n - 1) / 2;
	}
};
#endif


