//�滻�ո�
#include<iostream>
using namespace std;
#include<string>

class solution
{
public:
	string ReplaceBlank(string s)
	{
		if (s.empty())
		{
			return s;
		}
		auto it = s.begin();
		int count = 0;

		//��ǰ����������ҵ�������ɾ��������Ȼ���ڡ���λ�ò��롰%20��
		while (it!=s.end())
		{
			if (*it == ' ')
			{
				it=s.erase(it);    //��it���գ���ֹ������ʧЧ
				s.insert(count, "%20");
			}
			++it;
			++count;
		}
		return s;
	}
};

int main()
{
	string s;
	//gets(s);
	getline(cin,s);

	solution A;
	cout << A.ReplaceBlank(s) << endl;
	return 0;
}