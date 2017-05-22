// leetcode31.cpp : 定义控制台应用程序的入口点。
// 求下一个排列，直接使用STL中的next_permutation来实现
// 类似的STL中还有prev_permutation函数
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;


void nextPermutation(vector<int>& nums)
{
	next_permutation(nums.begin(), nums.end());
}

int main()
{
	vector<int> nums = { 3,2,1 };
	nextPermutation(nums);
	for (auto i : nums)
		cout << i << endl;
	system("pause");
	return 0;
}

