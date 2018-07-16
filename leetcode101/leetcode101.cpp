// leetcode101.cpp : 定义控制台应用程序的入口点。
// leetcode733的姊妹题
// BFS
// 检查每一层构成的数组是否对称（回文）
// 想错了，未AC

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <deque>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::deque;
using std::map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) //边界条件
			return true;

		vector<vector<int>> ans(height(root));
		map<TreeNode*, int> d; //记录最短路径距离

		deque<TreeNode*> Q;
		Q.push_back(root);
		d[root] = 1;

		while (!Q.empty())
		{
			TreeNode *temp = Q.front();
			Q.pop_front();
			ans[d[temp] - 1].push_back(temp->val);
			if (temp->left)
			{
				Q.push_back(temp->left);
				d[temp->left] = d[temp] + 1;
			}
			if (temp->right)
			{
				Q.push_back(temp->right);
				d[temp->right] = d[temp] + 1;
			}
		}

		vector<vector<int>> return_ans(ans.rbegin(), ans.rend());
		for (int i = 0; i < return_ans.size(); i++)
		{
			if (!check_symmetrical(return_ans[i]))
				return false;	
		}

		return true;
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

	bool check_symmetrical(const vector<int> &v)
	{
		int size = v.size();
		for (int i = 0; i < size; i++)
			if (v[i] != v[size - i - 1])
				return false;
		return true;
	}

	void compare(TreeNode *p1, TreeNode *p2)
	{
		if (p1 == nullptr&&p2 == nullptr)
			return;

	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);
	Solution S;
	cout << S.isSymmetric(root) << endl;

	system("pause");
	return 0;
}

