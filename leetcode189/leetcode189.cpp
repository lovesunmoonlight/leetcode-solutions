// leetcode189.cpp : �������̨Ӧ�ó������ڵ㡣
// Accepted
// �ֻ�һ������
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

void rotate(vector<int>& nums, int k)
{
	while (k--)
	{
		int temp = nums.back();
		nums.pop_back();
		nums.insert(nums.begin(),temp);
	}
	
}


int main()
{
	vector<int> nums = { 1,2,3,4,5,6,7 };
	rotate(nums,3);
	for (auto i : nums)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}

