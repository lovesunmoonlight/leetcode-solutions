// leetcode238.cpp : 定义控制台应用程序的入口点。
// 输出数组中每个元素除其本身剩余元素的乘积
// 题目要求时间O(n)，空间O(1)
// 为此可将每个元素左边所有元素的积和右边所有元素的积处理出来,相乘即可
// Accepted

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
	int size = nums.size();
	vector<int> output(size);
	output[0] = 1;
	output[size - 1] = 1;

	//left[i+1]=left[i]*nums[i]
	for (int i = 0; i < size-1; i++)
	{
		output[i + 1] = output[i] * nums[i];
	}

	//right[i]=right[i+1]*nums[i]
	int temp = 1;
	for (int i = size - 1; i >= 0;i--)
	{
		output[i] *= temp;
		temp = temp*nums[i];
	}
	
	return output;
}


int main()
{
	vector<int> nums = {1,2,3,4};
	decltype(nums) ans = productExceptSelf(nums);
	for (auto i : ans)
		cout << i << endl;
	system("pause");
	return 0;
}

