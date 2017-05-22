// leetcode581.cpp : 定义控制台应用程序的入口点。
// 寻找序列中非增序的一段子序列，输出其长度
// 未AC

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int findUnsortedSubarray(vector<int>& nums)
{
	int size = nums.size();
	int start=0;
	int end = 0;
	int flag1=-1;
	int flag2=-1;
	for (int i = 0; i < size - 1; i++)
	{
		if (nums[i + 1] < nums[i])
		{
			start = i;
			break;
		}
		if (nums[i + 1] == nums[i])
		{
			flag1 = i;
		}
	}
	
	for (int i = size - 1; i > 0; i--)
	{
		if (nums[i - 1] > nums[i])
		{
			end = i;
			break;
		}
		if (nums[i - 1] == nums[i])
			flag2 = i;
	}
	if (start != end)
	{
		if (end - start == 1)
		{
			if (flag1 != -1)
				start = flag1;
			else if (flag2 != -1)
				end = flag2;
			else
				;
			return end - start + 1;
		}
		
	}
	return 0;
}


int main()
{
	vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
	cout << "ans=" << findUnsortedSubarray(nums) << endl;
	system("pause");
	return 0;
}

