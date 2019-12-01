
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
//�����ַ�ת���֣���ʹ�ÿ⺯��
class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;
		long long ret = 0;
		//Ϊ����
		if (str[0] == '+')
		{
			for (int i = 1; i < str.size(); ++i)
			{
				if (str[i]<'0' || str[i]>'9')
					return 0;
				ret = ret * 10 + (str[i] - '0');
			}
		}
		if (str[0] >= '0'&&str[0] <= '9')
		{
			for (int i = 0; i < str.size(); ++i)
			{
				if (str[i]<'0' || str[i]>'9')
					return 0;
				ret = ret * 10 + (str[i] - '0');
			}
		}
		//Ϊ����
		if (str[0] == '-')
		{
			for (int i = 1; i < str.size(); ++i)
			{
				if (str[i]<'0' || str[i]>'9')
					return 0;
				ret = ret * 10 + (str[i] - '0');
			}
			ret = ret * (-1);
		}

		//�ж��Ƿ�Ϸ�
		if (ret<=INT_MAX&&ret>=INT_MIN)
		{
			 return (int)ret;
		}
		//str[0]�������ַ�
		return 0;
	}
};


int main()
{
	string s = "+2147483647";
	Solution A;
	cout << A.StrToInt(s) << endl;
	return 0;
}
*/

/*
//�ַ����е�һ�����ظ����ַ�

class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		v.push_back(ch);
		++hash[ch];
		// s+=ch;
		 //++hash[ch];
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (int i = 0; i < v.size(); ++i)
			if (hash[v[i]] == 1)
				return v[i];
		// for(int i=0;i<s.size();++i)
		//     if(hash[s[i]]==1)
		   //      return s[i];
		return '#';
	}
	vector<char> v;
	//string s;
	int hash[256] = { 0 };
};

*/

//��ת�ַ���
class Solution {
public:
	string ReverseSentence(string str) {
		int len = str.size();
		int start = 0;
		for (int i = 0; i < len; ++i)
		{
			if (str[i] == ' ')
			{
				reverse(str.begin() + start, str.begin() + i);
				start = i + 1;
			}
			if (i == len - 1)
			{
				reverse(str.begin() + start, str.end());
			}
		}
		reverse(str.begin(), str.end());
		return str;
	}
};