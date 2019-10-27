//替换空格
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

		//从前往后遍历，找到‘’，删除‘’，然后在‘’位置插入“%20“
		while (it!=s.end())
		{
			if (*it == ' ')
			{
				it=s.erase(it);    //用it接收，防止迭代器失效
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