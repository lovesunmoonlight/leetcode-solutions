// leetcode404.cpp : �������̨Ӧ�ó������ڵ㡣
// �������е���Ҷ�ӽڵ�
// �ǵݹ���������

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
* Definition for a binary tree node.*/
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		TreeNode* p = root;
		stack<TreeNode*> S;
		int ans = 0;
		while (true)
		{
			visitAlongLeftBranch(p, S, ans);
			if (S.empty())
				break;
			p = S.top(); //����һ��������
			S.pop();
		}
		return ans;
	}

	void visitAlongLeftBranch(TreeNode* x, stack<TreeNode*>& S, int& ans)
	{
		//�������֧�������У�ͬʱ����������ջ����
		while (x)
		{
			if(x->left != nullptr && x->left->left==nullptr && x->left->right==nullptr)
				ans += x->left->val;
			S.push(x->right);
			x = x->left;	
		}
	}
};


int main()
{
	Solution S;
	TreeNode* t = new TreeNode(3);
	t->left = new TreeNode(9);
	t->right = new TreeNode(20);
	t->right->left = new TreeNode(15);
	t->right->right = new TreeNode(7);
	cout << S.sumOfLeftLeaves(t) << endl;
	system("pause");
	return 0;
}

