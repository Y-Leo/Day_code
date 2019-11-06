#include<iostream>
using namespace std;

//题目：二进制中1的个数
//输入一个整数，输出该数的二进制中一的个数
#if 0

//方法一：让n每次和1按位与，若结果为0则count++；然后n右移1
//缺点：无法检测负数,负数可能导致死循环

int number(int n)
{
	int count = 0;
	while(n)    
	{
		if(n&1)
			count++;
		n = n >> 1;            //这里不可以将>>换成/2，因为乘除法比位运算效率低很多
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << number(n) << endl;
	return 0;
}

#endif

#if 0
//方法二：为了避免死循环，不让n右移，设置一个flag=1，每次与n按位与，结果为1，则count++，然后flag左移1，32位数则左移32次求得结果
//缺点：循环次数太多，造成时间效率不高

int number(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&flag)
		{
			count++;
		}
		flag = flag << 1;    //左移flag，让二进制的flag的1每次左移一位  32位数则需要左移32次
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << number(n) << endl;
	return 0;
}

#endif

#if 1
//方法三：将n-1，再与原来的n相与，这样就可以让n最右边的1变成0.有多少个1，就进行多少次该操作

int number(int n)
{
	int count = 0;

	while (n)
	{
		++count;
		n = n&(n - 1);
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << number(n) << endl;
	return 0;
}

#endif


