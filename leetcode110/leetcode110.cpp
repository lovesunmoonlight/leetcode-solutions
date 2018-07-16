// leetcode110.cpp : �������̨Ӧ�ó������ڵ㡣
// AC
// Ҫ�����������ÿ�����Ϊ����������ƽ�������
// �ݹ����
// Ҳ����BFS��DFS

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>

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
	bool isBalanced(TreeNode* root) {
		if (!root) //�߽�����
			return true;

		bool flag=(abs(height(root->left) - height(root->right)) <= 1);
		bool flag2 = isBalanced(root->left);
		bool flag3 = isBalanced(root->right);

		return flag&&flag2&&flag3;
	}

	int height(TreeNode *p)
	{
		if (!p)
			return 0;
		return max(height(p->left), height(p->right)) + 1;
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
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
	cout << S.isBalanced(p) << endl;

	system("pause");
    return 0;
}

