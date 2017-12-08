// leetcode628.cpp : 定义控制台应用程序的入口点。
// 找出序列中前n大的数
// 用最大堆实现

/******************/
// 开始还以为是卡数据量，需要最大堆，后来发现竟然有负数
// 直接进行排序，三个数相乘最大要么为最大的三个数(同号)
// 要么为1正2负

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int size = nums.size();
		if (size == 3)
			return nums[0] * nums[1] * nums[2];
		sort(nums.begin(), nums.end(), [](int a, int b) {return a > b; });
		return max(nums[0] * nums[1] * nums[2], nums[0] * nums[size - 1] * nums[size - 2]);
	}
};

int main()
{
	Solution s;
	cout<<s.maximumProduct(vector<int>{-4,-3,-2,-1,60}) << endl;
	system("pause");
	return 0;
}

