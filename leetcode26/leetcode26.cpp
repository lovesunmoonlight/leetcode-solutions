// leetcode26.cpp : 定义控制台应用程序的入口点。
// Accepted

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
	auto flag=unique(nums.begin(), nums.end());
	int cnt = 0;
	auto it = nums.begin();
	while (it != flag)
	{
		++cnt;
		++it;
	}
	return cnt;
}


int main()
{
	vector<int> nums = { 1,1,2 };
	cout << removeDuplicates(nums)<<endl;
	system("pause");
	return 0;
}

