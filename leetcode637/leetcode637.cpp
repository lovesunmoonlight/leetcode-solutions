// leetcode637.cpp : 定义控制台应用程序的入口点。
// BFS层次遍历

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

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
	vector<double> averageOfLevels(TreeNode* root) {
		queue<TreeNode*> q; //当前层的所有节点
		q.push(root);
		vector<double> res;
		while (!q.empty())
		{
			long long sum=0; //当前层的总和
			int count=0; //当前层的节点个数
			
			//temp队列保存当层中所有节点的孩子
			queue<TreeNode*> temp;

			while (!q.empty()) 
			{
				TreeNode* n = q.front();
				sum += n->val;
				q.pop();
				count++;
				
				//把当前层的所有孩子放到一个队列中
				if (n->left != nullptr)
					temp.push(n->left);
				if (n->right != nullptr)
					temp.push(n->right);
			}
			q = temp;
			res.push_back(sum * 1.0 / count);
		}
		return res;
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
	auto ans=S.averageOfLevels(t);
	for (auto i : ans)
		cout << i << endl;
	system("pause");
	return 0;
}

