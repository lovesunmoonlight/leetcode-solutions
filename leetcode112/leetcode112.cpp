// leetcode112.cpp : 定义控制台应用程序的入口点。
// 递归遍历二叉树

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

/**
* Definition for a binary tree node.
* */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return false;
		if (root->val == sum && root->left==nullptr && root->right==nullptr )
			return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

int main()
{
	Solution S;
	TreeNode* t = new TreeNode(5);
	TreeNode* p = t;
	p->left = new TreeNode(4);
	p->right = new TreeNode(8);
	p->left->left = new TreeNode(11);
	p->left->left->left = new TreeNode(7);
	p->left->left->right = new TreeNode(2);
	p->right->left = new TreeNode(13);
	p->right->right = new TreeNode(4);
	p->right->right->right = new TreeNode(1);
	cout<<S.hasPathSum(t, 22)<<endl;
	system("pause");
	return 0;
}

