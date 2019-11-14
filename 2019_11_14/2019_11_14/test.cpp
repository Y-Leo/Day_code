#if 0
//��Ŀ��������n���ַ����ַ���, ���������ַ������ȶ��ǲ�ͬ��
//����1�������ַ��ֵ�����
//	 ����
//	 car<carriage<cats<doggies
//����2�����ַ����ĳ�������
//   ����
//	 car<cars<doggies<carriage
//	 ������֪���Լ�����Щ�ַ�������˳���Ƿ�����������
//����������
//	 ��һ��Ϊ�ַ�������n(n��100)
//	 ��������n��, ÿ��һ���ַ���, �ַ������Ⱦ�С��100,
//�������:
//   �����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ�������islexicalorder
//   ������ݳ������ж������ֵ����������lengths
//   ������ַ�ʽ���������"both", �������none

#include<iostream>
using namespace std;
#include<vector>
#include<string>

bool is_leng(vector<string>& v)
{
	for (int i = 0; i<v.size() - 1; ++i)
	{
		if (v[i].size()>v[i + 1].size())
			return false;
	}
	return true;
}

bool is_lexi(vector<string>& v)
{
	for (int i = 0; i<v.size() - 1; ++i)
	{
		if (v[i]>v[i + 1])
			return false;
	}
	return true;
}

void judge(int n)
{
	vector<string> v;
	v.resize(n);

	for (int i = 0; i<n; ++i)
	{
		getline(cin, v[i]);
	}

	if (is_leng(v) && is_lexi(v))
		cout << "both" << endl;
	else if (is_leng(v))
		cout << "lengths" << endl;
	else if (is_lexi(v))
		cout << "lexicographically" << endl;
	else
		cout << "none" << endl;
}


int main()
{
	int n = 0;
	while (cin >> n)
	{
		judge(n);
	}
	return 0;
}

#endif


//��Ŀ��
//    ������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������
//��������:
//    ��������������A��B��
//������� :
//    ���A��B����С��������
#include<iostream>
using namespace std;
int LCM(int a, int b)
{
	int Max = a>b ? a : b;
	int Min = a<b ? a : b;
	for (int i = Max; i <= Min*Max; ++i)
	{
		if (i%Max == 0 && i%Min == 0)
		{
			return i;
		}
	}
}

int main()
{
	int A = 0, B = 0;
	while (cin >> A >> B)
	{
		cout << LCM(A, B) << endl;
	}
	return 0;
}