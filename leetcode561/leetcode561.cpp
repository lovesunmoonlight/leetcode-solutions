// leetcode561.cpp : 定义控制台应用程序的入口点。
// Accepted
// 每隔一个元素取值求和

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int arrayPairSum(vector<int>& nums)
{
	int ans=0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i += 2)
		ans += nums[i];
	return ans;
}


int main()
{
	vector<int> nums = { 1,2,3,4 };
	cout << arrayPairSum(nums) << endl;
	system("pause");
	return 0;
}

