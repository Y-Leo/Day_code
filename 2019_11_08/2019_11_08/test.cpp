#if 0
//��Ŀ���ҳ������г��ִ�������һ�������
//���ҵ������ظ����֣���δ�ҵ�������0
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int num = numbers.size();
		int count = 0;
		for (int i = 0; i<num; i++)
		{
			if (numbers[i] == numbers[num / 2])
				count++;
		}
		if (count>(num / 2))
			return numbers[num / 2];
		else
			return 0;
	}
};

int main()
{
	Solution A;
	vector<int> num = { 1, 2, 3, 2, 5, 2, 2, 2, 2, 2, 3, 4, 5, 2, 2 };
	
	cout << A.MoreThanHalfNum_Solution(num) << endl;
	
	return 0;
}


#endif

#include<iostream>
using namespace std;
#include<string>
#include<vector>
//��Ŀ����һ���ַ�������������ַ���
//������
//1��������������string�࣬һ������ʱ������һ�������մ�
//2�������������ַ����������ʱ���У��Ƚ���ʱ�������մ����ȣ�����ʱ���������մ��򽻻����ݣ������ʱ������������
string LongestNumStr(string& s)
{
	int n = s.size();
	if (n<1 || n>256)
	{
		return s;
	}
	string ss, Max_num_str;
	for (int i = 0; i<=n; ++i)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			ss += s[i];
		}
		else
		{
			if (ss.size()>Max_num_str.size())
				Max_num_str = ss;
			else
				ss.clear();
		}
	}
	return Max_num_str;
}
int main()
{
	string s;
	while (cin >> s)
	{
		cout << LongestNumStr(s) << endl;
	}
	return 0;
}