// leetcode53.cpp : 定义控制台应用程序的入口点。
// 最大子序列和（DP）

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::set;
using std::queue;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size = nums.size();

		//边界条件
		if (size == 1)
			return nums[0];
		if (size == 0)
			return 0;

		int flag = 0;
		int index = 0;
		int max_negative = nums[0];
		for (int i = 0; i < size; i++)
		{
			if (nums[i] > 0)
			{
				index = i;
				flag = 1; //表示有正数存在
				break;
			}
			if (nums[i] > max_negative)
				max_negative = nums[i];
		}

		if (!flag) //全部非正数，返回最大者
			return max_negative;

		int *sum = new int[size]; //以某个元素结尾的子序列的最大子序列和
		sum[index] = nums[index];
		int cur = sum[index];
		for (int j = index + 1; j < size; j++) 
		{
			sum[j] = max(sum[j - 1] + nums[j], nums[j]);

			if (sum[j] > cur) //保存最大值，用于返回
				cur = sum[j];
		}

		return cur;
	}
	
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	vector<int> nums = { -2, -1};
	Solution S;
	cout << S.maxSubArray(nums) << endl;

	system("pause");
	return 0;
}

