#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		int vin_len = vin.size();
		if (vin_len == 0)
			return NULL;
		//�ֱ𱣴������������������
		vector<int> pre_left, pre_right, vin_left, vin_right;
		//�������ڵ㣬���ڵ�϶���ǰ������ĵ�һ����
		TreeNode* head = new TreeNode(pre[0]);
		//�ҵ�����������ڵ�����λ��,����ڱ���gen��
		int root = 0;
		for (int i = 0; i < vin_len; i++) {
			if (vin[i] == pre[0]) {
				root = i;
				break;
			}
		}
		//����������������ڵ���ߵĽڵ�λ�ڶ���������ߣ����ڵ��ұߵĽڵ�λ�ڶ��������ұ�
		// ������
		for (int i = 0; i < root; i++) {
			vin_left.push_back(vin[i]);
			pre_left.push_back(pre[i + 1]);//�����һ��Ϊ���ڵ�
		}
		// ������
		for (int i = root + 1; i < vin_len; i++) {
			vin_right.push_back(vin[i]);
			pre_right.push_back(pre[i]);
		}
		//�ݹ飬ִ���������裬����������������������ֱ��Ҷ�ڵ�
		head->left = reConstructBinaryTree(pre_left, vin_left);
		head->right = reConstructBinaryTree(pre_right, vin_right);
		return head;
	}
};

int main()
{
	return 0;
}