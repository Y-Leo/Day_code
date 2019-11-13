#if 0
//问题：
//输入一个数，若是斐波那契数则输出0
//若不是，如果让它变成斐波那契数，需要最少几步
//每次只能+1或者-1

//分析：
//用循环方式来求斐波那契数，边求边与n比较，直到定位在两个斐波那契数之间。
//定义一个函数，求出离n最近的斐波那契数
//计算出n与离它最近的斐波那契数之间的距离，返回

#include<iostream>
using namespace std;

int min(int ToLeft, int ToRight)
{
	if (ToLeft <= ToRight)
		return ToLeft;
	else
		return ToRight;
}

int ToBeFibSteps(int n)
{
	//f(0)=0;
	//f(1)=1;
	//f(n)=f(n-1)+f(n-2);
	int fib = 0, fib0 = 0, fib1 = 1;
	int ToLeft = 0, ToRight = 0;
	while (1)
	{
		fib = fib0 + fib1;
		fib0 = fib1;
		fib1 = fib;

		if (n>fib)
		{
			ToLeft = n - fib;
			//这里不跳出是为了再循环一次计算出n右边的fib数
		}
		if (n<fib)
		{
			ToRight = fib - n;
			break;
		}
	}
	return min(ToLeft, ToRight);
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << ToBeFibSteps(n) << endl;
	}
	return 0;
}

#endif

#if 1
//题目：
//括号匹配是否合法
//输入一个string类，输入一个n表示字符个数
//若匹配则返回true
//不匹配则返回false
//只有全是括号且严格匹配才算括号匹配

#include<iostream>
using namespace std;
#include<string>
#include<stack>

//法一

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if(A.empty())
			return true;
		if(1==n%2)
		{
			return false;
		}
		for(int i=0;i<n;++i)
		{
			if(A[i]!='('&&A[i]!=')')
				return false;
		}

		stack<char> B;
		for(int i=0;i<n||!B.empty();++i)
		{
			if(B.empty())
			{
				B.push(A[i]);
				continue;
			}
			if(A[i]==')'&&B.top()=='(')
				B.pop();
			else
				B.push(A[i]);
		}
		if(B.empty())
			return true;
		return false;
	}
};
#endif

#if 0

//题目：
//括号匹配是否合法
//输入一个string类，输入一个n表示字符个数
//若匹配则返回true
//不匹配则返回false
//只有全是括号且严格匹配才算括号匹配

#include<iostream>
using namespace std;
#include<string>
#include<stack>

//法二

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// 如果输入空串，符合要求
		if (A.empty())
			return true;
		//字符数为奇数则不符合
		if (1 == n % 2)
		{
			return false;
		}
		//字符串中有其他字符，则不符合
		for (int i = 0; i<n; ++i)
		{
			if (A[i] != '('&&A[i] != ')')
				return false;
		}
		//通过栈来匹配
		stack<char> B;
		for (int i = 0; i<n; ++i)
		{
			if (B.empty() && A[i] == ')')
			{
				return false;
			}
			if (A[i] == '(')
				B.push(A[i]);
			if (A[i] == ')')
				B.pop();
		}
		if (B.empty())
			return true;
		return false;
	}
};

#endif