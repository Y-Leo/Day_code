#include<iostream>
using namespace std;
#include<stack>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		//如果头节点为空或者头节点的下一个节点为空则返回头节点
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		//定义一个链表指针，指向头节点
		ListNode* cur = pHead;
		//定义一个链表节点类型的栈
		//遍历链表，把每个节点存在栈中
		//然后遍历栈，把节点串起来，则变成反转之后的新链表
		stack<ListNode*> s;
		//入栈
		while (cur->next)
		{
			s.push(cur);
			cur = cur->next;
		}
		//栈顶为新头节点
		ListNode* new_Head = cur;
		//出栈
		while (!s.empty())
		{
			cur->next = s.top();
			cur = cur->next;
			s.pop();
		}
		//让最后一个节点的下一个节点指向空
		cur->next = NULL;
		//返回新的头节点
		return new_Head;
	}
};


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		//如果一个节点为空，则直接返回另一个链表
		if (pHead1 == NULL)
			return pHead2;
		else if (pHead2 == NULL)
			return pHead1;
		//定义一个新的头节点
		ListNode* New_Head = NULL;

		//递归比较链表一的头节点和链表二的头节点，每次把最小的值赋给新节点
		if (pHead1->val < pHead2->val)
		{
			New_Head = pHead1;
			//递归时链表头节点在不断变化
			New_Head->next = Merge(pHead1->next, pHead2);
		}
		else
		{
			New_Head = pHead2;
			New_Head->next = Merge(pHead1, pHead2->next);
		}
		return New_Head;
	}
};
*/