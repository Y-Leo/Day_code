#if 1

#include<iostream>
using namespace std;
#include<vector>
//ţţ��������������Ϊһ��������һ��������������,��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��
//һ������Ϊn����������A,��������һ�������ǰ�����A��Ϊ���ɶ�����������,ţţ��֪�������ٿ��԰����
//�����Ϊ�������������С�

int SortNum()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> arr;
		arr.resize(n + 1);
		long long num = 0;
		for (int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}

		//arr[n] = 0;
		int i = 0;
		while (i<n)
		{
			if (arr[i]<arr[i + 1])
			{
				while (i<n&&arr[i] <= arr[i + 1])
					i++;
				num++;
				i++;
			}
			else if (arr[i] == arr[i + 1])
				i++;
			else
			{
				while (i<n&&arr[i] >= arr[i + 1])
					i++;
				num++;
				i++;
			}
		}
		return num;
	}
}

int main()
{
	cout << SortNum() << endl;
	return 0;
}

#endif

#if 0
//��Ŀ����ת�ַ�������ת�ַ����ﵥ�ʣ�
//������1���ȶ��ַ����������巴ת
//      2���ٶ�ÿ�����ʽ��з�ת������������ߣ������ո�ת����������֮����ַ�����
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

string ReverseStr(string& s)
{
	if (s.empty()||s.size()>100)
	{
		return s;
	}
	reverse(s.begin(), s.end());
	auto it = s.begin();
	auto It = s.begin();
	while (it != s.end())
	{
		if (*it == ' ')
		{
			reverse(It, it);
			It = ++it;
		}
		++it;
	}
	reverse(It, s.end());
	return s;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		ReverseStr(s);
		for (auto& e : s)
		{
			cout << e;
		}
		cout << endl;
	}

	return 0;
}
#endif
