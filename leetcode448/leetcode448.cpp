// leetcode448.cpp : 定义控制台应用程序的入口点。
// Accepted

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
	vector<int> ans;
	vector<int> temp;
	for (int i = 0; i < nums.size(); i++)
		temp.push_back(-1);
	for (int i = 0; i < nums.size(); i++)
		temp[nums[i]-1] = nums[i];
	for (int i = 0; i < temp.size(); i++)
		if (temp[i] == -1)
			ans.push_back(i + 1);
	return ans;
}


int main()
{
	vector<int> nums={4, 3, 2, 7, 8, 2, 3, 1};
	vector<int> ans = findDisappearedNumbers(nums);
	for (auto i : ans)
		cout << i << endl;
	system("pause");
	return 0;
}

