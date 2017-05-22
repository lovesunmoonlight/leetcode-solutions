// leetcode104.cpp : 定义控制台应用程序的入口点。
// 返回二叉树的高度
// 任一结点高度等于左右子树高度最大者加1
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root)
{
	if (!root)
		return 0;
	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
	system("pause");
	return 0;
}

