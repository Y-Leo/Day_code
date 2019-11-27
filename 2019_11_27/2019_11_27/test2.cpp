//汽水瓶
#include<iostream>
using namespace std;

//方法一
/*
int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << n / 2 << endl;
	}
	return 0;
}
*/

#include<iostream>
using namespace std;

//方法二：循环
int bottles1(int n)
{
	int ret = 0;
	while (n > 2)
	{
		ret += n / 3;
		n = n / 3 + n % 3;
	}
	if (n == 2)
		ret += 1;
	return ret;
}

//方法三：递归
//思路：有1个瓶盖则一瓶都换不了，有两个可以问老板借一瓶，则可以换一瓶喝。
int bottles(int n)
{
	if (n == 1)
		return 0;
	//向老板借一瓶，可以多喝一瓶
	if (n == 2)
		return 1;
	return n / 3 + bottles(n / 3 + n % 3);
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << bottles1(n) << endl;
	}
	return 0;
}




