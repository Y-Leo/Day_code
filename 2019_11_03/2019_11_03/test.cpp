#if 0
//ֻ����һ�ε����֣�һ�������Ϊ��������
//����;���
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
//ֻ����һ�ε����֣����������Ϊ��������
//����;������Ȼ��˫ָ�����
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class solution
{
public:
	int singleNumber(vector<int>& v)
	{
		//������
		sort(v.begin(), v.end());
		//��������������k�Σ�˫ָ��Ѱ��
		int k = 3;
		for (size_t i = 0, j =1; i < v.size(); i+=k,j+=k)
		{
			if (v[i] != v[j])
				return v[i];
		}
		return v.size()-1;//�������һ������
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
//ֻ����һ�ε����֣���������ֻ����һ�Σ��������������
//����;�������
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
	//ȡ������������Ψһ���İ�λ�����
	for (int i = 0; i < nums.size(); i++)
	{
		sign ^= nums[i];
	}
	//��ȡ��������Ψһ���ı���λ�������ֵ
	//Ҳ����д�ɣ�sign &= (~sign) + 1
	sign &= -sign;
	int n1 = 0, n2 = 0;
	//ͨ����ʶ��������������
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