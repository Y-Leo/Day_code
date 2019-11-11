#if 0
#include<iostream>
using namespace std;

struct ListNode
{
	int _value;
	ListNode* _pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDelete)
{
	if (!pListHead || !pToBeDelete)
		return;
	//不是尾节点
	if (pToBeDelete->_pNext!=nullptr)
	{
		ListNode* pNext = pToBeDelete->_pNext;
		pToBeDelete->_value = pNext->_value;
		pToBeDelete->_pNext = pNext->_pNext;

		delete pNext;
		pNext = nullptr;
	}

	//只有一个节点
	else if (*pListHead == pToBeDelete)
	{
		delete pToBeDelete;
		pToBeDelete = nullptr;
		*pListHead = nullptr;
	}

	//删除尾节点
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->_pNext != pToBeDelete)
		{
			pNode = pNode->_pNext;
		}
	    
		pNode->_pNext = nullptr;
		delete pToBeDelete;
		pToBeDelete = nullptr;
	}
}

int main()
{
	ListNode Node;

	return 0;
}
#endif
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
