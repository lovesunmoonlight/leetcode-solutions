// leetcode617.cpp : 定义控制台应用程序的入口点。
// 递归合并两个二叉树（先序）

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

/**
* Definition for a binary tree node.
* */
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr)
			return t2;
		if (t2 == nullptr)
			return t1;

		//先序遍历
		t1->val = t1->val + t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
};

//先序递归建立表
void make_tree(TreeNode*& t, vector<int> t_data)
{
	static int pos = 0;
	if (pos == t_data.size())
		return;
	t = new TreeNode(t_data[pos++]);
	make_tree(t->left, t_data);
	make_tree(t->right, t_data);
}

//先序递归输出表
void output_tree(TreeNode*& t)
{
	if (t == NULL)
		return;
	cout << t->val << endl;
	output_tree(t->left);
	output_tree(t->right);
}

int main()
{
	vector<int> t1_data = { 1,2,3,4,5,6,7,8 };
	TreeNode* t1;
	make_tree(t1, t1_data);
	output_tree(t1);
	system("pause");
	return 0;
}

