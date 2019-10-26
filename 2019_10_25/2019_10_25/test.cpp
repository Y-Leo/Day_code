//反转字符串1:全反转

#if 0
#include<iostream>
using namespace std;
#include<string>


class solution
{
public:
	//法一：自己写一个函数，来实现反转，相当于string类的reverse底层实现
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
	//法二:相比法一来说，自己实现swap函数
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

	//法三:直接调用string类reverse接口来实现反转
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

	//要想使用创造的类,就得先创造一个类对象,然后通过类对象来调用类的接口
	solution A;
	cout << A.reverseString(s) << endl;

	cout << reverseS(s) << endl;
	return 0;
}
#endif



//字符串反转2：区间反转
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
				reverse(it, s.end());  //直接调用接口来实现反转
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


//字符串反转3：反转单词顺序
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
		//反转整个句子
		reverse(it, s.end());
		//反转句子中的每个单词
		
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