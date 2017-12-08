// leetcode617.cpp : �������̨Ӧ�ó������ڵ㡣
// �ݹ�ϲ�����������������

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

		//�������
		t1->val = t1->val + t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
};

//����ݹ齨����
void make_tree(TreeNode*& t, vector<int> t_data)
{
	static int pos = 0;
	if (pos == t_data.size())
		return;
	t = new TreeNode(t_data[pos++]);
	make_tree(t->left, t_data);
	make_tree(t->right, t_data);
}

//����ݹ������
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

