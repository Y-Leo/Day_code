#include<iostream>
using namespace std;

#if 0

//����һ�� 쳲�������������
//��n = 0 ����  n = 1 ʱ��f(n) = n;
//��n > 1ʱ��f(n) = f(n-1) + f(n-2);


//����һ����ͳ�ĵݹ���
//���ְ취������Ҫ�ܶ��ظ����㣬ʱ�临�ӶȺܸ�
long long Fibonacci1(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}

//����������������ѭ�����
//ʱ�临�Ӷ�O(n)
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

//�������������̨������
//һֻ����һ�ο�����һ̨Ҳ��������̨����������һ��n��̨�׹��ж�����������

//������
//���ֻ��һ��̨�ף�ֻ��һ��������
//���������̨�ף��Ǿ�������������ÿ����һ����ÿ����������
//�����n��̨�ף��Ǿ�������ѡ�񣬵�һ���ǵ�һ��ֻ��һ�������� n-1 ��̨����f(n-1)���������ڶ����ǵ�һ�������������� n-2 ��̨���� f(n-2)��������

//�����ܵ�����  f(n) = f(n-1) + f(n-2); ------------>��Ҳ����쳲��������е�һ��ʹ�á�

//��һ���ݹ�

long long solution1(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];

	return solution1(n - 1) + solution1(n - 2);
}

//������ѭ��
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

//���ƵĻ�����2*1��С����ȥ����2*8�Ĵ����  �ȵ�......
//�������������ȷ���С���⣬������ƣ�����ͻ�ܼ���