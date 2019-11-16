
#if 0
//题目一：不使用运算符计算A+B

//思路：使用位运算

#include<iostream>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		while (B != 0)
		{
			int sum = A^B;
			//^ 符号，相同为0，不同为1
			//& 符号全1才为1
			int ret = (A&B) << 1;
			A = sum;
			B = ret;
		}
		return A;
	}
};

int main()
{
	UnusualAdd sum;
	int ret = sum.addAB(10, 20);
	cout << ret << endl;
	return 0;
}

#endif

//题目：请编写一个函数（允许增加子函数），计算n x m的棋盘格子
//     （n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，
//      总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。


//思路：
//当n=1时，结果为m+1
//当m=1时，结果为n+1
//很明显可以用递归来解决这个问题
//简单推算得出递归式
#include<iostream>
using namespace std;

int ways(int n, int m)
{
	if (1 == n)
		return m + 1;
	else if (1 == m)
		return n + 1;
	return ways(n - 1, m) + ways(n, m - 1);
}

int main()
{
	int n = 0, m = 0;
	while (cin >> n >> m)
	{
		cout << ways(n, m) << endl;
	}
	return 0;
}