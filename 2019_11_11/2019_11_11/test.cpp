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
