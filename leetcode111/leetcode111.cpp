// leetcode111.cpp : �������̨Ӧ�ó������ڵ㡣
// AC
// ����������Ҷ�ӽڵ�����
// �ݹ����

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) //�߽�����
			return 0;
		if (root->left == nullptr)
			return minDepth(root->right) + 1;
		if (root->right == nullptr)
			return minDepth(root->left) + 1;

		return min(minDepth(root->left), minDepth(root->right)) + 1; //�ݹ����
	}

	int height(TreeNode *p)
	{
		if (p == nullptr)
			return 0;
		return 1 + max(height(p->left), height(p->right));
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
	}

	int min(int a, int b)
	{
		return a < b ? a : b;
	}
};

int main()
{
	Solution S;
	TreeNode *p = new TreeNode(1);
	p->left = new TreeNode(2);
	p->right = new TreeNode(3);
	p->right->left = new TreeNode(4);
	p->right->right = new TreeNode(5);
	cout << S.minDepth(p) << endl;

	system("pause");
    return 0;
}

