//��ˮƿ
#include<iostream>
using namespace std;

//����һ
/*
int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << n / 2 << endl;
	}
	return 0;
}
*/

#include<iostream>
using namespace std;

//��������ѭ��
int bottles1(int n)
{
	int ret = 0;
	while (n > 2)
	{
		ret += n / 3;
		n = n / 3 + n % 3;
	}
	if (n == 2)
		ret += 1;
	return ret;
}

//���������ݹ�
//˼·����1��ƿ����һƿ�������ˣ��������������ϰ��һƿ������Ի�һƿ�ȡ�
int bottles(int n)
{
	if (n == 1)
		return 0;
	//���ϰ��һƿ�����Զ��һƿ
	if (n == 2)
		return 1;
	return n / 3 + bottles(n / 3 + n % 3);
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << bottles1(n) << endl;
	}
	return 0;
}




