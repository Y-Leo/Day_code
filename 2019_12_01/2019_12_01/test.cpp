#if 0

//΢�ź��
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		sort(gifts.begin(), gifts.end());
		int ret = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			if (gifts[i] == ret)
				count++;
		}
		if (count > n / 2)
			return ret;
		return 0;
	}
};

int main()
{
	return 0;
}

#endif

//�����ַ���֮��ľ���
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

int Levenshtein(string s1, string s2)
{
	if (s1.size() == 0 && s2.size() == 0)//��Ϊ��
		return 0;
	else if (s1.size() == 0)//s1Ϊ��
		return s2.size();
	else if (s2.size() == 0)//s2Ϊ��
		return s1.size();
	else//����Ϊ��
	{
		int count = 0;
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		string max = s1.size() > s2.size() ? s1 : s2;//max���泤��
		string min = s1.size() < s2.size() ? s1 : s2;//min����̴�
		min.resize(max.size());
		int pos = 0;//��¼jλ��
		for (int i = 0; i < min.size(); ++i)
		{
			for (int j = pos; j < max.size(); ++j)
			{
				if (max[j] == min[i])
				{
					j++;
					pos = j;
					break;
				}
				count++;
			}
		}
		return count;
	}
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << Levenshtein(s1, s2) << endl;
	}
	return 0;
}

