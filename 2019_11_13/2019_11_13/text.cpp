#if 0
//���⣺
//����һ����������쳲������������0
//�����ǣ�����������쳲�����������Ҫ���ټ���
//ÿ��ֻ��+1����-1

//������
//��ѭ����ʽ����쳲����������������n�Ƚϣ�ֱ����λ������쳲�������֮�䡣
//����һ�������������n�����쳲�������
//�����n�����������쳲�������֮��ľ��룬����

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
			//���ﲻ������Ϊ����ѭ��һ�μ����n�ұߵ�fib��
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
//��Ŀ��
//����ƥ���Ƿ�Ϸ�
//����һ��string�࣬����һ��n��ʾ�ַ�����
//��ƥ���򷵻�true
//��ƥ���򷵻�false
//ֻ��ȫ���������ϸ�ƥ���������ƥ��

#include<iostream>
using namespace std;
#include<string>
#include<stack>

//��һ

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

//��Ŀ��
//����ƥ���Ƿ�Ϸ�
//����һ��string�࣬����һ��n��ʾ�ַ�����
//��ƥ���򷵻�true
//��ƥ���򷵻�false
//ֻ��ȫ���������ϸ�ƥ���������ƥ��

#include<iostream>
using namespace std;
#include<string>
#include<stack>

//����

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// �������մ�������Ҫ��
		if (A.empty())
			return true;
		//�ַ���Ϊ�����򲻷���
		if (1 == n % 2)
		{
			return false;
		}
		//�ַ������������ַ����򲻷���
		for (int i = 0; i<n; ++i)
		{
			if (A[i] != '('&&A[i] != ')')
				return false;
		}
		//ͨ��ջ��ƥ��
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