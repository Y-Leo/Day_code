#include<iostream>
using namespace std;

char Find(string& s)
{
	//统计每个字符出现的次数
	int count[26] = {0};
	auto it = s.begin();
	while (it!= s.end())
	{
		count[*it-'a']++;
		it++;
	}

	//找出第一个出现一次的字符
	for (int i = 0; i < s.size(); ++i)
	{
		if (1 == count[s[i]-'a'])
		{
			return s[i];
		}
	}
	
	return 0;//如果没有找到

}

int main()
{
	string s = "hello hello world!";

	cout << Find(s) << endl;
	return 0;
}