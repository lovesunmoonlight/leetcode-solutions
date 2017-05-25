// leetcode226.cpp : 定义控制台应用程序的入口点。
// 翻转二叉树
// 层次搜索左右子树并交换
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

/**
* Definition for a binary tree node.
* 
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return nullptr;
		TreeNode* temp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(temp);
		return root;
	}
};

int main()
{
	system("pause");
	return 0;
}

