// leetcode226.cpp : �������̨Ӧ�ó������ڵ㡣
// ��ת������
// ���������������������
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
		//travePre(root);
		return root;
	}
};

int main()
{
	system("pause");
	return 0;
}

