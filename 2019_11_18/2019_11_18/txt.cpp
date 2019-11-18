#if 0

#include<iostream>
using namespace std;
#include<string>

char findCh(string& s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
			return 0;
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			return s[i];
	}
	return 'n';
}


int main()
{
	string s;
	while (cin >> s)
	{
		cout << findCh(s) << endl;
	}
	return 0;
}

#endif

#if 0

#include<iostream>
using namespace std;

int countNum(int n)
{
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		int tmp = i;
		bool flag = true;
		while (tmp)
		{
			if (tmp % 10 == 2)
			{
				flag = false;
				break;
			}
			tmp /= 10;
		}
		if (flag)
			count++;
	}
	return count;
}


int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << countNum(n) << endl;
	}
	return 0;
}

#endif


#if 0
#include<iostream>
using namespace std;

int countNum(int n)
{
	int count = 0;
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	for (int i = 1; i <= n; ++i)
	{
		if (i%a != 0 && i%b != 0 && i%c != 0)
		{
			count++;
		}
	}

	return count;
}


int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << countNum(n) << endl;
	}
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int a[100][100] = { -1 };
	int t, x, y;
	int n, m;
	t = a[x = 0][y = 0] = 1;
	cin >> n >> m;
	while (t < n*m)
	{
		while (y + 1 < m && !a[x][y + 1])
			a[x][++y] = ++t;
		while (x + 1 < n && !a[x + 1][y])
			a[++x][y] = ++t;
		while (y - 1 >= 0 && !a[x][y - 1])
			a[x][--y] = ++t;
		while (x - 1 >= 0 && !a[x - 1][y])
			a[--x][y] = ++t;
	}

	int r = 0, c = 0;
	cin >> r >> c;
	cout << a[r - 1][c - 1] << endl;
	return 0;
}
#endif

#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	bool flag = false;
	vector <vector<int>> v;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == 'g')
			{
				flag = true;
			}
		}
		cout << endl;
	}
	return 0;
}



#if 0
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		return n + (m << j);
	}
};
#endif



#include<iostream>
using namespace std;
#include<algorithm>

bool isPrimer(int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

void TwoPrimers(int n)
{
	if (n <= 2)
		return;
	if (n % 2 == 1)
		return;
	int Min = n;
	int ret = 0;
	int a = 0, b = 0;
	for (int i = 1; i <= n / 2; ++i)
	{
		if (isPrimer(i) && isPrimer(n - i))
		{
			ret = (n - i) - i;
			if (ret < Min)
			{
				Min = ret;
				a = i;
				b = n - a;
			}
		}
	}
	cout << a << endl;
	cout << b << endl;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		TwoPrimers(n);
	}
	return 0;
}