#include<iostream>
using namespace std;
#include<string>

//字符串相加
string soluition1(string& s1, string& s2)
{
	//直接用string类字符串拼接接口实现
	//return s1 += s2;  //法一
      return s1.append(s2);   //法二
}

//找出字符串中第一个只出现一次的字符
char solution2(const string& s2)
{

	//统计每个字符出现的次数
	int count[256] = { 0 };
	int i = 0;
	for (i; i < s2.size(); ++i)
	{
		count[s2[i]] += 1;
	}
	//找出第一个只出现一次的字符
	for (i = 0; i < s2.size();i++)
	{
		if (1 == count[s2[i]])
		{
			return s2[i];
		}
	}
	return -1;
}

//字符串里面最后一个单词的长度
int solution3(string& s3)
{
	size_t pos = s3.rfind(' ');
	return s3.size() - pos - 1;
}
int main()
{
	string s1 = "hello";
	string s2 = "-world-!";
	string s3 = "hello world !";
	string s4;

	//这里也可以让用户循环输入，但是不能用cin,因为它遇到空格就认为输入结束了，因该使用getline(cin,s34)
	//while (getline(cin, s4))
	//{
	//	//操作
	//}

	//cout << soluition1(s1, s2) << endl;

	//char c = solution2(s2);
	//cout << c << endl;

	cout << solution3(s3) << endl;

	return 0;
}