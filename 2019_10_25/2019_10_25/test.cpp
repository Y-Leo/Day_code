//��ת�ַ���1:ȫ��ת

#if 0
#include<iostream>
using namespace std;
#include<string>


//��һ���Լ�дһ���࣬��ʵ�ַ�ת���൱��string���reverse�ײ�ʵ��
class solution
{
public:
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
};

//ֱ�ӵ���string��reverse�ӿ���ʵ�ַ�ת
string reverseS(string s)
{
	auto it = s.begin();
	reverse(it, s.end());
	return s;
}

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