// leetcode35.cpp : 定义控制台应用程序的入口点。
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int searchInsert(vector<int>& nums, int target) 
{
	int len = nums.size();
	if (target < nums[0])
		return 0;
	else if(target>nums.back())
		return len;
	else
	{ 
		for (int i=0;i<nums.size();i++)
		{
			if (nums[i] >= target)
				return i;
		}
	}
}


int main()
{
	vector<int> nums = { 1,3,5,6};
	cout << searchInsert(nums, 4) << endl;
	system("pause");
	return 0;
}

