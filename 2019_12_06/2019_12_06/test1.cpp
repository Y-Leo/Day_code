
#if 0
//字符串通配符
#include<iostream>
using namespace std;
#include<string>

bool Cmp(const char* s, const char* s1)
{
	if (*s == '\0'&&*s1 == '\0')
		return true;
	if (*s == '\0' || *s1 == '\0')
		return false;

	if (*s == '?')
		return Cmp(s + 1, s1 + 1);
	else if (*s == '*')
		return Cmp(s + 1, s1) || Cmp(s + 1, s1 + 1) || Cmp(s, s1 + 1);
	else if (*s == *s1)
		return Cmp(s + 1, s1 + 1);
	return false;
}

int main()
{
	string s;
	string s1;
	while (cin >> s >> s1)
	{
		if (Cmp(s.c_str(), s1.c_str()))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
#endif

//连续最大和
/*
给一个数组；
例：-1 2 4 -1 6 -2
输出：2+4+（-1）+6=11
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> arr(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		int max = arr[0];
		for (int i = 1; i < n; ++i) {
			if (arr[i - 1] > 0) {
				arr[i] += arr[i - 1];
			}
			if (max < arr[i])
				max = arr[i];
		}
		cout << max << endl;
	}
	return 0;
}
