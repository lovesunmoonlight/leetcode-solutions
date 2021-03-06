// leetcode107.cpp : 定义控制台应用程序的入口点。
// BFS
// 将二叉树的每一层单独输出
// BFS的过程记录结点的最短路径长度（也即结点的深度）
// 访问结点时将该结点的最短路径长度加入一个保存相同最短路径长度的向量
// 最后返回这些向量

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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (!root) //边界条件
			return vector<vector<int>>();
		
		vector<vector<int>> ans(height(root));
		map<TreeNode*, int> d; //记录最短路径距离
		
		deque<TreeNode*> Q;
		Q.push_back(root);
		d[root] = 1;

		while (!Q.empty())
		{
			TreeNode *temp = Q.front();
			Q.pop_front();
			ans[d[temp] -1].push_back(temp->val);
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
			for (int j = 0; j < return_ans[i].size(); j++)
				cerr << return_ans[i][j] << " ";
			cerr << endl;
		}

		return return_ans;
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
};


int main()
{
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	Solution S;
	S.levelOrderBottom(root);

	system("pause");
	return 0;
}

