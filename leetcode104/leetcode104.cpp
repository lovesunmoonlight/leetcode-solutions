// leetcode104.cpp : �������̨Ӧ�ó������ڵ㡣
// ���ض������ĸ߶�
// ��һ���߶ȵ������������߶�����߼�1
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

