//链表相关

#include<iostream>
using namespace std;
#include<list>
#include<stack>

#if 0
//一：往链表结尾新增一个节点

struct ListNode        //创建一个节点
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
//二：在链表中找到第一个含有某值的节点并删除该节点

struct ListNode
{
	int _value;
	ListNode* _Next;
};

void RemoveNode(ListNode* *pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)    //判断节点是否存在
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
//三：从尾到头打印链表

struct ListNode
{
	int _value;
	ListNode* _Next;
};

//法1：用栈来实现
void PrintListReversing(ListNode* pHead)
{
	stack<ListNode*> nodes;     //创建一个栈，存放链表节点

	ListNode* pNode = pHead;   //入栈
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->_Next;
	}

	while (!nodes.empty())     //出栈，打印
	{
		pNode = nodes.top();
		cout << pNode->_value << endl;
		nodes.pop();
	}
}

//法2：递归来实现，（递归在本质上就是一个栈结构）

void printListReversing(ListNode* pHead)
{
	if (pHead != nullptr)                  //如果头节点和头节点的下一个节点均不为空，则递归往下走
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