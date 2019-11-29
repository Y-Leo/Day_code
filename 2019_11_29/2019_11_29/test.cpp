//最长公共子串

#include<iostream>
using namespace std;
#include<string>
#include<vector>

int CommonStrNum(string s1, string s2)
{
	if (s1.empty() || s2.empty())
		return 0;
	int max = 0;
	vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;
			if (dp[i][j] > max)
				max = dp[i][j];
		}
	}
	return max;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << CommonStrNum(s1, s2) << endl;
	}
	return 0;
}

//洗牌
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int T = 0, n = 0, k = 0;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		vector<int> v(2 * n);
		for (int i = 0; i < 2 * n; ++i)
			cin >> v[i];
		while (k--)
		{
			vector<int> vv(v);
			for (int i = 0; i < n; ++i)
			{
				v[2 * i] = vv[i];
				v[2 * i + 1] = vv[i + n];
			}
		}
		for (int i = 0; i < 2 * n - 1; ++i)
			cout << v[i] << ' ';
		cout << v[2 * n - 1] << endl;
	}
	return 0;
}

//MP3光标位置
#include <iostream>
#include <string>
using namespace std;

void Mp3(int n, string order)
{
	int num = 1, first = 1; //将n首歌曲编号1~n, num为光标当前所在歌曲的编号,first为当前屏幕显示页的第一首歌曲的编号
	if (n <= 4) //歌曲总数不超过4时，所有歌曲一页即可显示完，不需翻页，first始终不变
	{
		for (int i = 0; i < order.size(); i++)
		{
			if (num == 1 && order[i] == 'U') num = n;
			else if (num == n && order[i] == 'D') num = 1;
			else if (order[i] == 'U') num--;
			else  num++;
		}
		for (int i = 1; i <= n - 1; i++)
			cout << i << ' ';
		cout << n << endl;
		cout << num << endl;
	}
	else  //歌曲总数大于4时，显示完全所有歌曲需要翻页，屏幕总是显示4首歌曲
	{
		for (int i = 0; i < order.size(); i++)
		{
			if (first == 1 && num == 1 && order[i] == 'U') { first = n - 3; num = n; } //特殊翻页1
			else if (first == n - 3 && num == n && order[i] == 'D') { first = 1; num = 1; } //特殊翻页2
			else if (first != 1 && num == first && order[i] == 'U') { first--; num--; } //一般翻页1
			else if (first != n - 3 && num == first + 3 && order[i] == 'D') { first++; num++; } //一般翻页2
			else if (order[i] == 'U') num--; //其他情况1
			else num++; //其他情况2
		}
		for (int i = first; i < first + 3; i++)
			cout << i << ' ';
		cout << first + 3 << endl;
		cout << num << endl;
	}
}
int main() {
	int n;
	string order;
	while (cin >> n >> order)
	{
		Mp3(n, order);
	}
	return 0;
}
