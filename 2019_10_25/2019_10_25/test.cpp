//��ת�ַ���1:ȫ��ת

#if 0
#include<iostream>
using namespace std;
#include<string>


class solution
{
public:
	//��һ���Լ�дһ����������ʵ�ַ�ת���൱��string���reverse�ײ�ʵ��
	string reverseString(string s)
	{
		if (s.empty())
			return s;
		size_t start = 0;
		size_t end = s.size() - 1;

		while (start < end)
		{
			swap(s[start], s[end]);
			++start;
			--end;
		}
		return s;
	}
	//����:��ȷ�һ��˵���Լ�ʵ��swap����
	string reverseStr(string s)
	{
		if (s.empty())
			return s;
		size_t start = 0;
		size_t end = s.size() - 1;

		while (start < end)
		{
			//swap(s[start], s[end]);
			int tmp=s[start];
			s[start]=s[end];
			s[end]=tmp;

			++start;
			--end;
		}
		return s;
	}
	}

	//����:ֱ�ӵ���string��reverse�ӿ���ʵ�ַ�ת
	string reverseS(string s)
	{
		auto it = s.begin();
		reverse(it, s.end());
		return s;
	}
};



int main()
{
	string s = "hello";

	//Ҫ��ʹ�ô������,�͵��ȴ���һ�������,Ȼ��ͨ���������������Ľӿ�
	solution A;
	cout << A.reverseString(s) << endl;

	cout << reverseS(s) << endl;
	return 0;
}
#endif



//�ַ�����ת2�����䷴ת
#if 0
#include<iostream>
using namespace std;
#include<string>

class solution
{
public:
	string reverseStr(string s, int k)
	{
		if(s.empty())
		{
			return s;
		}
		auto it = s.begin();
			if (k > s.size())
			{
				reverse(it, s.end());  //ֱ�ӵ��ýӿ���ʵ�ַ�ת
				return s;
			}
			reverse(it, it + k);
			return s;	
	}
};

int main()
{
	string str;
	cin >> str;
	int k;
	cin >> k;
	solution A;
	cout << A.reverseStr(str, k) << endl;

	return 0;
}
#endif


//�ַ�����ת3����ת����˳��
#include<iostream>
using namespace std;
#include<string>

class solution
{
public:
	string ReverseSentence(string s)
	{
		if (s.empty())
			return s;
		auto it = s.begin();
		s.end() = s.end() - 2;
		//��ת��������
		reverse(it, s.end());
		//��ת�����е�ÿ������
		
		size_t start = 0;
		size_t end = 0;

		while (start!='\0')
		{
			if (start == ' ')
			{
				start++;
				end++;
			}
			else if (s[end] == ' ' || s[end] == '\0')
			{
				reverse(start, --end);
				start = ++end;
			}
			else
			{
				end++;
			}
		}
		return s;
	}
	

};
int main()
{
	string s;
	cin >> s;
	solution A;
	cout << A.ReverseSentence(s) << endl;

	return 0;
}