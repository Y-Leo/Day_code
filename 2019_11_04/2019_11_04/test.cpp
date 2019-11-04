//�������

#include<iostream>
using namespace std;
#include<list>
#include<stack>

#if 0
//һ���������β����һ���ڵ�

struct ListNode        //����һ���ڵ�
{
	int  _value;
	ListNode* _Next;
};

void AddToTail(ListNode* *pHead,int value)
{
	ListNode* pNew = new ListNode();
	pNew->_value = value;
	pNew->_Next = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;

		while (pNode->_Next != nullptr)
		{
			pNode = pNode->_Next;
		}
		pNode->_Next = pNew;
	}
}

int main()
{

	return 0;
}

#endif

#if 0
//�������������ҵ���һ������ĳֵ�Ľڵ㲢ɾ���ýڵ�

struct ListNode
{
	int _value;
	ListNode* _Next;
};

void RemoveNode(ListNode* *pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)    //�жϽڵ��Ƿ����
		return;

	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->_value == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->_Next;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->_Next != nullptr  &&  pNode->_Next->_value != value)
		{
			pNode = pNode->_Next;

			if (pNode->_Next != nullptr &&  pNode->_Next->_value == value)
			{
				pToBeDeleted = pNode->_Next;
				pNode->_Next = pNode->_Next->_Next;
			}
		}
	}
	if (pToBeDeleted == nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

int main()
{

	return 0;
}

#endif

#if 1
//������β��ͷ��ӡ����

struct ListNode
{
	int _value;
	ListNode* _Next;
};

//��1����ջ��ʵ��
void PrintListReversing(ListNode* pHead)
{
	stack<ListNode*> nodes;     //����һ��ջ���������ڵ�

	ListNode* pNode = pHead;   //��ջ
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->_Next;
	}

	while (!nodes.empty())     //��ջ����ӡ
	{
		pNode = nodes.top();
		cout << pNode->_value << endl;
		nodes.pop();
	}
}

//��2���ݹ���ʵ�֣����ݹ��ڱ����Ͼ���һ��ջ�ṹ��

void printListReversing(ListNode* pHead)
{
	if (pHead != nullptr)                  //���ͷ�ڵ��ͷ�ڵ����һ���ڵ����Ϊ�գ���ݹ�������
	{
		if (pHead->_Next != nullptr)
		{
			printListReversing(pHead->_Next);
		}
		cout << pHead->_value << endl;
	}
}


int main()
{
	return 0;
}

#endif 