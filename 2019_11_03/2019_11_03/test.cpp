#if 0
//只出现一次的数字（一）其余均为出现两次
//方法;异或
#include<iostream>
using namespace std;
#include<vector>

class solution
{
public:
	int singleNumber(vector<int>& v)
	{
		int value = 0;
		for (size_t i = 0; i < v.size(); ++i)
		{
			value ^= v[i];
		}
		return value;
	}
};

int main()
{
	vector<int> v{ 1, 2, 3, 3, 2, 1, 4, 5, 5 };
	solution A;
	cout << A.singleNumber(v) << endl;
	return 0;
}
#endif

#if 0
//只出现一次的数字（二）其余均为出现三次
//方法;先排序，然后双指针查找
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class solution
{
public:
	int singleNumber(vector<int>& v)
	{
		//先排序
		sort(v.begin(), v.end());
		//设置其余数出现k次，双指针寻找
		int k = 3;
		for (size_t i = 0, j =1; i < v.size(); i+=k,j+=k)
		{
			if (v[i] != v[j])
				return v[i];
		}
		return v.size()-1;//返回最后一个数字
	}
};

int main()
{
	vector<int> v{ 1,3,1, 2, 2,3,5, 3, 2, 1, 4, 5, 5 };
	solution A;
	cout << A.singleNumber(v) << endl;
	return 0;
}
#endif


#if 1
//只出现一次的数字（三）两个只出现一次，其余均出现两次
//方法;分组异或
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class solution
{
public:
vector<int> singleNumber(vector<int>& nums)
{
	int sign = 0;
	//取得数组中两个唯一数的按位异或结果
	for (int i = 0; i < nums.size(); i++)
	{
		sign ^= nums[i];
	}
	//获取区分两个唯一数的比特位所代表的值
	//也可以写成：sign &= (~sign) + 1
	sign &= -sign;
	int n1 = 0, n2 = 0;
	//通过标识，区分两个数组
	for (int i = 0; i < nums.size(); i++)
	{
		if ((nums[i] & sign) == sign)
			n1 ^= nums[i];
		else
			n2 ^= nums[i];;
	}
	return{n1,n2};
}
};

int main()
{
	vector<int> v{ 1, 3, 1, 2, 2, 4, 5, 5 };
	solution A;
	vector<int> vv = A.singleNumber(v);
	for (auto& e : vv)
	{
		cout << e <<' ';
	}
	cout << endl;
	return 0;
}
#endif