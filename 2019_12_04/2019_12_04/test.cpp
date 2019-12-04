//打印链表倒数k个节点
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		/*
		//方法一：遍历一遍，统计长度；遍历第二遍，返回count-1
		if(pListHead==NULL||k<=0)
			return NULL;
		int count=0;
		ListNode* Node=pListHead;
		while(Node!=NULL)
		{
			count++;
			Node=Node->next;
		}
		if(k>count)
			return NULL;
		ListNode* node=pListHead;
		for(int i=1;i<=count-k;++i)
		{
			node=node->next;
		}
		return node;
		*/

		//方法二：快慢指针，快指针先走k步；然后快慢指针一起走，快指针为null，则返回慢指针。
		if (pListHead == NULL || k <= 0)
			return NULL;
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;
		int num = k - 1;
		while (num--)
		{
			if (fast->next != NULL)
				fast = fast->next;
			else
				return NULL;
		}
		while (fast->next != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};