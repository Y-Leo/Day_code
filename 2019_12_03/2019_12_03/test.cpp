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
		//分别保存各自左子树和右子树
		vector<int> pre_left, pre_right, vin_left, vin_right;
		//创建根节点，根节点肯定是前序遍历的第一个数
		TreeNode* head = new TreeNode(pre[0]);
		//找到中序遍历根节点所在位置,存放于变量gen中
		int root = 0;
		for (int i = 0; i < vin_len; i++) {
			if (vin[i] == pre[0]) {
				root = i;
				break;
			}
		}
		//对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
		// 左子树
		for (int i = 0; i < root; i++) {
			vin_left.push_back(vin[i]);
			pre_left.push_back(pre[i + 1]);//先序第一个为根节点
		}
		// 右子树
		for (int i = root + 1; i < vin_len; i++) {
			vin_right.push_back(vin[i]);
			pre_right.push_back(pre[i]);
		}
		//递归，执行上述步骤，区分子树的左、右子子树，直到叶节点
		head->left = reConstructBinaryTree(pre_left, vin_left);
		head->right = reConstructBinaryTree(pre_right, vin_right);
		return head;
	}
};

int main()
{
	return 0;
}