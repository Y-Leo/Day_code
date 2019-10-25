//反转字符串1:全反转

#if 0
#include<iostream>
using namespace std;
#include<string>


//法一：自己写一个类，来实现反转，相当于string类的reverse底层实现
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

//直接调用string类reverse接口来实现反转
string reverseS(string s)
{
	auto it = s.begin();
	reverse(it, s.end());
	return s;
}

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