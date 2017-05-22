// leetcode27.cpp : 定义控制台应用程序的入口点。
// Accepted
// 通过这一题知道leetcode不只检查了函数的返回值，还检查了传入的引用参数

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int ans = 0;
	for (int i=0;i<nums.size();i++)
		if (nums[i] != val)
			nums[ans++]=nums[i];
	return ans;
}


int main()
{
	vector<int> nums = { 3,2,2,3};
	cout << removeElement(nums, 3)<<endl;
	system("pause");
	return 0;
}

