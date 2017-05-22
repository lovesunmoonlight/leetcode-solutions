// leetcode219.cpp : 定义控制台应用程序的入口点。
// 未AC

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	if (nums.size() == 1)
		return false;
	map<int, int> m;

	//扫描一遍，初始化为-1
	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]] = -1;
	}

	//第二遍扫描，存储每个值对应的下标，相同的值只存储一次
	for (int i = 0; i < nums.size(); i++)
	{
		if (m[nums[i]] == -1)
			m[nums[i]] == i;
	}

	//第三遍扫描，检查有没有下标不同的相同值，注意要排除自身
	for (int i = 0; i < nums.size(); i++)
	{
		if (i - m[nums[i]] <= k&&i-m[nums[i]]>=0)
			return true;
	}
	return false;
}


int main()
{
	vector<int> nums = { 1 };
	if (containsNearbyDuplicate(nums, 1))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	system("pause");
	return 0;
}

