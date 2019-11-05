#include<iostream>
using namespace std;

#if 0

//问题一： 斐波那契数列问题
//当n = 0 或者  n = 1 时，f(n) = n;
//当n > 1时，f(n) = f(n-1) + f(n-2);


//方法一：传统的递归解决
//这种办法我们需要很多重复计算，时间复杂度很高
long long Fibonacci1(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}

//方法二：从下往上循环求解
//时间复杂度O(n)
long long Fibonacci2(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
	{
		return result[n];
	}

	long long fibOne = 1;
	long long fibTwo = 0;
	long long fibN = 0;
	
	for (unsigned int i = 2; i <= n; ++i)
	{
		fibN = fibOne + fibTwo;

		fibTwo = fibOne;
		fibOne = fibN;
	}
	return fibN;
}


int main()
{
	cout << Fibonacci1(10) << endl;
	cout << Fibonacci2(10) << endl;
	return 0;
}

#endif

#if 1

//问题二：青蛙跳台阶问题
//一只青蛙一次可以跳一台也可以跳两台，问青蛙上一个n级台阶共有多少种跳法。

//分析：
//如果只有一级台阶，只有一种跳法；
//如果有两级台阶，那就有两种跳法，每次跳一级和每次跳两级；
//如果有n级台阶，那就有两种选择，第一种是第一次只跳一级，后面 n-1 级台阶有f(n-1)种跳法；第二种是第一次跳两级，后面 n-2 级台阶有 f(n-2)种跳法。

//所以总的跳法  f(n) = f(n-1) + f(n-2); ------------>这也就是斐波那契数列的一种使用。

//法一：递归

long long solution1(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];

	return solution1(n - 1) + solution1(n - 2);
}

//法二：循环
long long solution2(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];

	long long s1 = 1;
	long long s2 = 0;
	long long sn = 0;

	for (unsigned int i = 2; i <= n; ++i)
	{
		sn = s1 + s2;

		s2 = s1;
		s1 = sn;
	}
	return sn;
}

int main()
{
	cout << solution1(5) << endl;
	cout << solution2(5) << endl;
	return 0;
}

#endif

//类似的还有用2*1的小矩形去覆盖2*8的大矩形  等等......
//遇到这类问题先分析小问题，往后递推，问题就会很简单了