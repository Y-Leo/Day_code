#if 0

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int _count = 0;
vector<int> v;

void One_Count(int cur_pos, int sum, int mul)
{
	for (int i = cur_pos; i < v.size(); i++)
	{
		sum += v[i];
		mul *= v[i];
		if (sum <= mul)
		{
			return;  //���������������
		}
		else
		{
			_count++;  //�������������������
		}
		One_Count(i + 1, sum, mul);  //���������ݹ�鿴��ǰ���к���������ƥ�����
		sum -= v[i];//������������غ�������
		mul /= v[i];
		while (v[i] == v[i + 1] && i < v.size())
		{
			i++;  //����
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int one_num = 0;
	int num;
	while (n--)
	{
		cin >> num;
		if (num > 1)
		{
			v.push_back(num);
		}
		else
		{
			one_num++;
		}
	}
	_count = one_num - 1;
	if (!v.empty())
	{
		sort(v.begin(), v.end());
		for (int i = 1; i <= one_num; i++)
		{
			One_Count(0, i, 1);
		}
	}

	cout << _count << endl;
	return 0;
}

#endif

#if 0
//����һ���������������Ķ��������м���1

#include<iostream>
using namespace std;

int Nums(int n)
{
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		if ((n >> i) & 1)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << Nums(n) << endl;
	}
	return 0;
}

#endif

