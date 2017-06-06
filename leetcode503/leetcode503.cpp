// leetcode503.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
	//平凡解
	if (nums.size() == 0)
		return vector<int>();
	vector<int> ans;
	int max = nums[0]; //记录最大值
	for (auto i : nums)
	{
		if (i >= max)
			max = i;
	}
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		int flag = 0;
		if (*it == max)
			ans.push_back(-1);
		else
		{
			for (auto it1 = it; it1 != nums.end(); it1++)
				if (*it1 > *it)
				{
					ans.push_back(*it1);
					flag = 1;
					break;
				}
			if (!flag)
			{
				for (auto it1 = nums.begin(); it1 != it; it1++)
					if (*it1 > *it)
					{
						ans.push_back(*it1);
						break;
					}
			}
		}
	}
	return ans;
}

int main()
{
	vector<int> nums = { 1,5,3,6,8 };
	vector<int> ans = nextGreaterElements(nums);
	for (auto i : ans)
		cout << i << endl;
	system("pause");
	return 0;
}

