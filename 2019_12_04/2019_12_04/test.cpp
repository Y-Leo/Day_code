//��ӡ������k���ڵ�
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
		//����һ������һ�飬ͳ�Ƴ��ȣ������ڶ��飬����count-1
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

		//������������ָ�룬��ָ������k����Ȼ�����ָ��һ���ߣ���ָ��Ϊnull���򷵻���ָ�롣
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