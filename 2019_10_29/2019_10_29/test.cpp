
//��Ŀ����1+2+3+....+n , Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C��

#if 1

//��һ�����ù��캯���;�̬������Ա
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

//���������÷º���
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

//���������ú���ָ��
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

//���ģ�����&&�Ķ�·����
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


