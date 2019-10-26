//替换空格
#include<iostream>
using namespace std;
#include<string>

class solution
{
public:
	string ReplaceBlank(string s,int length)
	{
		if (s.empty())
		{
			return s;
		}
		int originalLength = 0;//实际长度
		int numberOfBlank = 0;//统计空格个数
		int i = 0;
		while (s[i] != '\0')
		{
			++originalLength;
			if (s[i] == ' ')
			{
				++numberOfBlank;
			}
			++i;
		}

		int newLength = originalLength + numberOfBlank * 2;
		if (newLength > length)
		{
			return s;
		}

		int indexOforiginal = originalLength;
		int indexOfNew = newLength;

		while (indexOforiginal >= 0 && indexOfNew > indexOforiginal)
		{
			if (s[indexOforiginal] == ' ')
			{
				s[indexOfNew--] = '0';
				s[indexOfNew--] = '2';
				s[indexOfNew--] = '%';
			}
			else
				s[indexOfNew--] = s[indexOforiginal];
			--indexOforiginal;
		}
		return s;
	}
};

int main()
{
	string s;
	s.reserve(30);
	getline(cin,s);
	int length = s.capacity();

	solution A;
	cout << A.ReplaceBlank(s, length) << endl;
	return 0;
}