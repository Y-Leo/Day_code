#if 0
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	// IO型OJ可能会有多组测试用例，所以这里要持续接收输入多组测试用例。 
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> a;
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		/*
		排序，然后取下标为3n - 2，3n - 4 ，3n - 4... n+2，n位置的元素累加即可， 
		相当下标为[0,n-1]的n个数做每组的最左边的数，剩下的2个数据两个为一组， 
		大的值做最右边的数，次大的做中间值，这里就是把这个次大的值加起来
		*/
		sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
}
#endif

#if 0
//2. 标题:删除公共字符 | 时间限制 : 1秒 | 内存限制 : 32768K 
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
//输入描述 :
//每个测试输入包含2个字符串
//输出描述 : 输出删除后的字符串

#include<iostream>
#include<string>
using namespace std;

int main() {
	// 注意这里不能使用cin接收，因为cin遇到空格就结束了。 // oj中IO输入字符串最好使用getline。
	string str1, str2;
	//cin>>str1;
	//cin>>str2;
	getline(cin, str1);
	getline(cin, str2);
	// 使用哈希映射思想先str2统计字符出现的次数 
	int hashtable[256] = {0};
	for (size_t i = 0; i < str2.size(); ++i) {
		hashtable[str2[i]]++;
	}
	// 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在
	// str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erases(i) // 因为边遍历，边erase，容易出错。
	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}

			cout << ret << endl;
		return 0;
	}

#endif

#if 0
//3、计算糖果
//知道A-B B-C A+B B+C，求ABC，若有则返回A、B、C，若没有则返回NO

//思路;很暴力的解法，先用数学式子表示出ABC，解出之后再回去验证结果是否正确
#include<iostream>
using namespace std;
#include<vector>

void CountCandy(vector<int> v)
{
	v.resize(4, 0);
	int A, B, C;
	while (cin >> v[0] >> v[1] >> v[2] >> v[3])
	{
		A = (v[0] + v[2]) / 2;
		B = (v[1] + v[3]) / 2;
		C = v[3] - B;
		if ((A - B == v[0]) && (B - C == v[1]) && (A + B == v[2]) && (B + C == v[3]))
		{
			cout << A << " " << B << " " << C << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}

int main()
{
	vector<int> v;
	CountCandy(v);
	return 0;
}
#endif

#if 1
//4、进制转换
//输入一个十进制数，完成到任意进制之间的转换

//思路：
//1、十进制转其他进制：除权取余倒着读
//2、M不断处N直到M为零，取余数对应保存到s里，最后逆置s输出
//3、注意几种情况：
//                  1>负数，先转为正数，最后再补上‘-’
//                  2>余数超过9，直接创建ss，来对应保存，如10对应保存为A

#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

string Transformation(int M, int N)
{
	bool flag = false;//若M<0特殊化处理
	string s;
	string ss = "0123456789ABCDEF";  //为了保存余数超过9的情况
	if (M<0)
	{
		M = 0 - M;
		flag = true;
	}
	while (M)
	{
		s += ss[M%N];
		M /= N;
	}
	if (flag)
	{
		s += '-';
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	int M;
	int N;
	while (cin >> M >> N)
	{
		cout << Transformation(M, N) << endl;
	}
	return 0;
}


#endif