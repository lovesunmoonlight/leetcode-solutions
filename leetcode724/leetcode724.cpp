// leetcode724.cpp : 定义控制台应用程序的入口点。
// 找到序列中的一个元素，该元素左侧元素和等于右侧元素和
// 多个结果返回最左边结果
// 无解返回-1
// 边界条件为0，1，2个元素

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int len = nums.size();
		 
		if (len == 0) //边界条件
			return -1;
		
		if (len == 1) //边界条件
			return 0;

		if (len == 2) //边界条件
		{
			if (nums[1] == 0)
				return 0;
			else if (nums[0] == 0)
				return 1;
			return -1;
		}

		vector<int> sum(len, 0);
		sum[0] = nums[0];
		for (int i = 1; i < len; i++)
			sum[i] = sum[i - 1] + nums[i];

		for (int i = 0; i < len; i++)
		{
			if (i == 0) //边界条件
			{
				if (sum[len - 1] - nums[i] == 0)
					return 0;
			}
			else if (i == len - 1) //边界条件
			{
				if (sum[len - 1] - nums[i] == 0)
					return len - 1;
			}
			else if (sum[i - 1] == sum[len - 1] - sum[i])
				return i;
		}

		return -1;
	}
};

int main()
{
	vector<int> nums1 = { 1, 7, 3, 6, 5, 6 };
	vector<int> nums2 = { 1, 2, 3 };
	Solution S;
	int ans1 = S.pivotIndex(nums1);
	int ans2 = S.pivotIndex(nums2);
	cout << ans1 << endl << ans2 << endl;

	system("pause");
	return 0;
}

