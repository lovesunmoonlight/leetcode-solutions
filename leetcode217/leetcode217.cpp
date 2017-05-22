// leetcode217.cpp : 定义控制台应用程序的入口点。
// 判断是否有重复元素
// 空向量单独处理
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


bool containsDuplicate(vector<int>& nums)
{
	if (!nums.size())
		return false;
	sort(nums.begin(),nums.end());
	for (int i = 0; i < nums.size() - 1; i++)
		if (nums[i] == nums[i + 1])
			return true;
	return false;
}


int main()
{
	vector<int> nums;
	int n;
	while (cin >> n)
		nums.push_back(n);
	if (containsDuplicate(nums))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}

