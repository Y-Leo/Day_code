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
	//����β�ڵ�
	if (pToBeDelete->_pNext!=nullptr)
	{
		ListNode* pNext = pToBeDelete->_pNext;
		pToBeDelete->_value = pNext->_value;
		pToBeDelete->_pNext = pNext->_pNext;

		delete pNext;
		pNext = nullptr;
	}

	//ֻ��һ���ڵ�
	else if (*pListHead == pToBeDelete)
	{
		delete pToBeDelete;
		pToBeDelete = nullptr;
		*pListHead = nullptr;
	}

	//ɾ��β�ڵ�
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
//4������ת��
//����һ��ʮ����������ɵ��������֮���ת��

//˼·��
//1��ʮ����ת�������ƣ���Ȩȡ�൹�Ŷ�
//2��M���ϴ�Nֱ��MΪ�㣬ȡ������Ӧ���浽s��������s���
//3��ע�⼸�������
//                  1>��������תΪ����������ٲ��ϡ�-��
//                  2>��������9��ֱ�Ӵ���ss������Ӧ���棬��10��Ӧ����ΪA

#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

string Transformation(int M, int N)
{
	bool flag = false;//��M<0���⻯����
	string s;
	string ss = "0123456789ABCDEF";  //Ϊ�˱�����������9�����
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
