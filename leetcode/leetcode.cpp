// leetcode.cpp : 定义控制台应用程序的入口点。
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int missingNumber(vector<int>& nums) 
{
	vector<int> temp;
	for (int i = 0; i < nums.size() + 1; i++)
		temp.push_back(-1);
	for (int i = 0; i < nums.size(); i++)
		temp[nums[i]] = nums[i];
	for (int i = 0; i < temp.size(); i++)
		if (temp[i] == -1)
			return i;
}

int main()
{
	vector<int> nums = {0,1,3};
	cout << missingNumber(nums) << endl;
	system("pause");
	return 0;
}

