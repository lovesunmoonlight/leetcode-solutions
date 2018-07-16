// leetcode207.cpp : �������̨Ӧ�ó������ڵ㡣
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
		vector<vector<int>> pre(numCourses); //�ڽ�����
		vector<int> indegree(numCourses, 0); //������

		//second��first��ǰ�����
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
				if (indegree[st] == 1) //��û�ж����޿γ̵�����
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
		for (auto st : pre[i]) //�����ھӽ��
		{
			if (indegree[st] == 1) //��û�ж����޿γ̵�����  
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

