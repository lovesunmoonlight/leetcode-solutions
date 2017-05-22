// leetcode414.cpp : 定义控制台应用程序的入口点。
// 求向量中第三大的数（重复元素只算一次）
// 如果不存在第三大则返回最大值
// 题目要求O(n)复杂度，利用一个大顶堆实现，可以到O(logn)
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int thirdMax(vector<int>& nums)
{
	priority_queue<int> ans;
	for (auto i : nums)
		ans.push(i);
	int max3,max2,max1;
	int max = ans.top();
	max1 = ans.top();
	while (!ans.empty()&&max1 == ans.top())
		ans.pop();

	if (!ans.empty())
	{
		max2 = ans.top();
		while (!ans.empty()&&max2 == ans.top())
			ans.pop();
	}
	
	if(!ans.empty())
		return max3 = ans.top();
	else
		return max;
}


int main()
{
	vector<int> nums = { 1,2 };
	cout<<thirdMax(nums);
	cout<< endl;
	system("pause");
	return 0;
}

