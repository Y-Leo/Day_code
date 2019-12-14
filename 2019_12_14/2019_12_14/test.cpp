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
		//���ͷ�ڵ�Ϊ�ջ���ͷ�ڵ����һ���ڵ�Ϊ���򷵻�ͷ�ڵ�
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		//����һ������ָ�룬ָ��ͷ�ڵ�
		ListNode* cur = pHead;
		//����һ������ڵ����͵�ջ
		//����������ÿ���ڵ����ջ��
		//Ȼ�����ջ���ѽڵ㴮���������ɷ�ת֮���������
		stack<ListNode*> s;
		//��ջ
		while (cur->next)
		{
			s.push(cur);
			cur = cur->next;
		}
		//ջ��Ϊ��ͷ�ڵ�
		ListNode* new_Head = cur;
		//��ջ
		while (!s.empty())
		{
			cur->next = s.top();
			cur = cur->next;
			s.pop();
		}
		//�����һ���ڵ����һ���ڵ�ָ���
		cur->next = NULL;
		//�����µ�ͷ�ڵ�
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
		//���һ���ڵ�Ϊ�գ���ֱ�ӷ�����һ������
		if (pHead1 == NULL)
			return pHead2;
		else if (pHead2 == NULL)
			return pHead1;
		//����һ���µ�ͷ�ڵ�
		ListNode* New_Head = NULL;

		//�ݹ�Ƚ�����һ��ͷ�ڵ���������ͷ�ڵ㣬ÿ�ΰ���С��ֵ�����½ڵ�
		if (pHead1->val < pHead2->val)
		{
			New_Head = pHead1;
			//�ݹ�ʱ����ͷ�ڵ��ڲ��ϱ仯
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