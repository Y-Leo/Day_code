#include<iostream>
using namespace std;

char Find(string& s)
{
	//ͳ��ÿ���ַ����ֵĴ���
	int count[26] = {0};
	auto it = s.begin();
	while (it!= s.end())
	{
		count[*it-'a']++;
		it++;
	}

	//�ҳ���һ������һ�ε��ַ�
	for (int i = 0; i < s.size(); ++i)
	{
		if (1 == count[s[i]-'a'])
		{
			return s[i];
		}
	}
	
	return 0;//���û���ҵ�

}

int main()
{
	string s = "hello hello world!";

	cout << Find(s) << endl;
	return 0;
}