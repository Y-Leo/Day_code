#include<iostream>
using namespace std;

//��Ŀ����������1�ĸ���
//����һ����������������Ķ�������һ�ĸ���
#if 0

//����һ����nÿ�κ�1��λ�룬�����Ϊ0��count++��Ȼ��n����1
//ȱ�㣺�޷���⸺��,�������ܵ�����ѭ��

int number(int n)
{
	int count = 0;
	while(n)    
	{
		if(n&1)
			count++;
		n = n >> 1;            //���ﲻ���Խ�>>����/2����Ϊ�˳�����λ����Ч�ʵͺܶ�
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << number(n) << endl;
	return 0;
}

#endif

#if 0
//��������Ϊ�˱�����ѭ��������n���ƣ�����һ��flag=1��ÿ����n��λ�룬���Ϊ1����count++��Ȼ��flag����1��32λ��������32����ý��
//ȱ�㣺ѭ������̫�࣬���ʱ��Ч�ʲ���

int number(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&flag)
		{
			count++;
		}
		flag = flag << 1;    //����flag���ö����Ƶ�flag��1ÿ������һλ  32λ������Ҫ����32��
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << number(n) << endl;
	return 0;
}

#endif

#if 1
//����������n-1������ԭ����n���룬�����Ϳ�����n���ұߵ�1���0.�ж��ٸ�1���ͽ��ж��ٴθò���

int number(int n)
{
	int count = 0;

	while (n)
	{
		++count;
		n = n&(n - 1);
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << number(n) << endl;
	return 0;
}

#endif


