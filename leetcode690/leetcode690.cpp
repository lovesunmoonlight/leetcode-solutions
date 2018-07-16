// leetcode690.cpp : 定义控制台应用程序的入口点。
// BFS
// 遍历一颗树，求结点个数

#include "stdafx.h"
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::deque;
 
// Employee info
class Employee {
public:
// It's the unique ID of each node.
// unique id of this employee
int id;
// the importance value of this employee
int importance;
// the id of direct subordinates
vector<int> subordinates;
};

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		
		int size = employees.size();

		int index[2001]; //散列，保存id到员工向量下标的映射
		for (int i = 0; i < size; i++)
			index[employees[i]->id] = i;
		
		bool visit[2001];
		for (int i = 0; i < size; i++)
			visit[employees[i]->id] = false;

		int sum = 0;

		deque<int> Q;
		Q.push_back(id);
		visit[id] = true;

		//搜索下属员工
		while (!Q.empty())
		{
			int temp = Q.front();
			Q.pop_front();

			int cur_index = index[temp];
			sum += employees[cur_index]->importance;
			
			for (int i = 0; i < employees[cur_index]->subordinates.size(); i++)
			{
				int cur_child_index = employees[cur_index]->subordinates[i];
				if (!visit[cur_child_index])
				{
					Q.push_back(cur_child_index);
					visit[cur_child_index] = true;
				}
			}
		}

		return sum;

	}
};

int main()
{
	Employee e1 = { 1, 5, {2, 3} };
	Employee e2 = { 2, 3, {} };
	Employee e3 = { 3, 3, {} };
	vector<Employee*> v = { &e1,&e2,&e3 };
	Solution S;
	cout << S.getImportance(v, 1) << endl;
	
	system("pause");
	return 0;
}

