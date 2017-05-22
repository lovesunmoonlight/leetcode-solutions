// leetcode566.cpp : 定义控制台应用程序的入口点。
// 将给定的矩阵转化成新的尺寸
// Accepted

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
{
	int scale = nums.size()*nums[0].size();
	if (r*c != scale)
		return nums;
	vector<vector<int>> ans;
	ans.resize(r);
	int row = 0;
	for(int i=0;i<nums.size();i++)
		for (int j = 0; j <nums[0].size(); j++)
		{
			ans[row].push_back(nums[i][j]);
			if (ans[row].size() == c)
				++row;
		}
	return ans;
}


int main()
{
	vector<vector<int>> nums = { {1},{2},{3},{4} };
	decltype(nums) ans = matrixReshape(nums,2,2);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			cout << ans[i][j] << " ";
			if ((j + 1) % 2 == 0)
				cout << endl;
		}
	cout << endl;
	system("pause");
	return 0;
}

