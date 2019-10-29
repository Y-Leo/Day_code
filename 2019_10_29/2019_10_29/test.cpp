
//题目：求1+2+3+....+n , 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）

#if 1

//法一：利用构造函数和静态函数成员
#include <iostream>
using namespace std;

class Temp
{
public:
	Temp()
	{
		++N;
		Sum += N;
	}

	static void Reset()
	{
		N = 0;
		Sum = 0;
	}

	static int GetSum()
	{
		return Sum;
	}
private:
	static int N;
	static int Sum;
};

int Temp::N = 0;
int Temp::Sum = 0;

int solution_Sum(int n)
{
	Temp::Reset();

	Temp *a = new Temp[n];
	delete[]a;
	a = 0;

	return Temp::GetSum();
}

int main()
{
	cout << solution_Sum(100) << endl;
	return 0;

}

#endif

#if 0

//法二：利用仿函数
#include <iostream>
using namespace std;

class A;
A* Array[2];

class A
{
public:
	virtual int Sum(int n)
	{
		return 0;
	}
};

class B :public A
{
public:
	virtual int Sum(int n)
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};

int solution2_Sum(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	int value = Array[1]->Sum(n);

	return value;
}

int main()
{
	cout << solution2_Sum(100) << endl;
	return 0;
}

#endif


#if 0

//法三：利用函数指针
#include <iostream>
using namespace std;

typedef int(*fun)(int);

int solution_f1(int i)
{
	return 0;
}

int solution_f2(int i)
{
	fun f[2] = { solution_f1, solution_f2 };
	return i + f[!!i](i - 1);
}

void main()
{
	cout << solution_f2(100) << endl;
}

#endif


#if 0

//法四：利用&&的短路特性
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add_fun(int n, int &sum)
{
	n && add_fun(n - 1, sum);
	return (sum += n);
}

int main()
{
	int sum = 0;
	int n = 100;

	printf("1+2+3+...+n=%d\n", add_fun(n, sum));

	return 0;
}

#endif


