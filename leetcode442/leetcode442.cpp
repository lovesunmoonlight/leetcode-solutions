// leetcode442.cpp : 定义控制台应用程序的入口点。
// Accepted
// 找到数组中出现两次的数，利用map进行判断是否多次出现
// map值初始化为-1
// 第一次扫描到某个值时将map值更新为下标
// 第二次扫描到这个值的时候检查map值是否为-1，不是说明是第二次出现了
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

vector<int> findDuplicates(vector<int>& nums)
{
	vector<int> ans;
	map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]] = -1;
	}
	
	for (int i = 0; i < nums.size(); i++)
	{
		if (m[nums[i]] == -1)
			m[nums[i]] = i;
		else
			ans.push_back(nums[i]);
	}
	return ans;
}


int main()
{
	vector<int> nums = { 4,3,2,7,8,2,3,1 };
	vector<int> ans = findDuplicates(nums);
	for (auto i : ans)
		cout << i << endl;
	system("pause");
	return 0;
}

