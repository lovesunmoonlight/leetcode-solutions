// leetcode207.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::pair;
using std::queue;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		int size = prerequisites.size();
		vector<vector<int>> pre(numCourses); //邻接链表
		vector<int> indegree(numCourses, 0); //结点入度

		//second是first的前驱结点
		for (int i = 0; i < size; ++i)
		{
			indegree[prerequisites[i].first]++;
			pre[prerequisites[i].second].push_back(prerequisites[i].first);
		}

		int count = 0;

		queue<int> Q;
		for (int i = 0; i < numCourses; ++i)
		{
			if (indegree[i] == 0)	
			{
				//Q.push(i);
				//cerr << i << endl;
				dfs(i, pre, indegree, count);
			}
		}

		while (!Q.empty()) 
		{
			int temp = Q.front();
			Q.pop();
			++count;

			for (auto st : pre[temp]) 
			{
				if (indegree[st] == 1) //再没有对先修课程的依赖
				{
					Q.push(st);
				}
				indegree[st]--;
			}
		}

		cerr << count << endl;
		return count == numCourses;
	}

	void dfs(int i, vector<vector<int>> &pre,vector<int> indegree, int &count)
	{
		for (auto st : pre[i]) //搜索邻居结点
		{
			if (indegree[st] == 1) //再没有对先修课程的依赖  
			{
				//cerr << st << endl;
				dfs(st, pre, indegree, count);
				indegree[st]--;	
			}
			
		}
		count++;
	}
};

int main()
{
	Solution S;
	vector<pair<int, int>> p = { {2, 0},{2, 1} };
	int n = 3;
	if (S.canFinish(n, p))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	system("pause");
	return 0;
}

