
#if 0
//调整数组使奇数位于偶数前面
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		/*
		for(int i=0;i<array.size();++i)
		{
			int temp=array[0];
				for(int j=array.size();j>i;--j)
				{
					if(array[j]%2!=0)
					{
						swap(array[i],array[j]);
						break;
					}
				}
			}
		}
		*/
		if (array.empty())
			return;
		vector<int> v1;
		vector<int> v2;
		for (int i = 0; i < array.size(); ++i)
		{
			if (array[i] % 2 != 0)
				v1.push_back(array[i]);
			else
				v2.push_back(array[i]);
		}
		array.clear();
		for (int i = 0; i < v1.size(); ++i)
		{
			array.push_back(v1[i]);
		}
		for (int i = 0; i < v2.size(); ++i)
		{
			array.push_back(v2[i]);
		}
	}
};

#endif

#if 0

#include<iostream>
using namespace std;
#include<list>

//打印链表倒数k个节点

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

/*
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {	
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
			}
};
		*/

		//方法二：快慢指针，快指针先走k步；然后快慢指针一起走，快指针为null，则返回慢指针。
		class Solution {
		public:
			ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
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

#endif

