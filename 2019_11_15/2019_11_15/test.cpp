
#if 0
//��Ŀһ����ʹ�����������A+B

//˼·��ʹ��λ����

#include<iostream>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		while (B != 0)
		{
			int sum = A^B;
			//^ ���ţ���ͬΪ0����ͬΪ1
			//& ����ȫ1��Ϊ1
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

//��Ŀ�����дһ�����������������Ӻ�����������n x m�����̸���
//     ��nΪ����ĸ�������mΪ����ĸ����������Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ�
//      �ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�


//˼·��
//��n=1ʱ�����Ϊm+1
//��m=1ʱ�����Ϊn+1
//�����Կ����õݹ�������������
//������ó��ݹ�ʽ
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