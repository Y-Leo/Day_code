#include<iostream>
using namespace std;
#include<string>

//�ַ������
string soluition1(string& s1, string& s2)
{
	//ֱ����string���ַ���ƴ�ӽӿ�ʵ��
	//return s1 += s2;  //��һ
      return s1.append(s2);   //����
}

//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
char solution2(const string& s2)
{

	//ͳ��ÿ���ַ����ֵĴ���
	int count[256] = { 0 };
	int i = 0;
	for (i; i < s2.size(); ++i)
	{
		count[s2[i]] += 1;
	}
	//�ҳ���һ��ֻ����һ�ε��ַ�
	for (i = 0; i < s2.size();i++)
	{
		if (1 == count[s2[i]])
		{
			return s2[i];
		}
	}
	return -1;
}

//�ַ����������һ�����ʵĳ���
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

	//����Ҳ�������û�ѭ�����룬���ǲ�����cin,��Ϊ�������ո����Ϊ��������ˣ����ʹ��getline(cin,s34)
	//while (getline(cin, s4))
	//{
	//	//����
	//}

	//cout << soluition1(s1, s2) << endl;

	//char c = solution2(s2);
	//cout << c << endl;

	cout << solution3(s3) << endl;

	return 0;
}