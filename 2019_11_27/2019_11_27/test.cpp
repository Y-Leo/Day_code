
#if 0
//��������ʹ����λ��ż��ǰ��
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

//��ӡ������k���ڵ�

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
			}
};
		*/

		//������������ָ�룬��ָ������k����Ȼ�����ָ��һ���ߣ���ָ��Ϊnull���򷵻���ָ�롣
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

