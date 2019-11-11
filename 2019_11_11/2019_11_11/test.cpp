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
