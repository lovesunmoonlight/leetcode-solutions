// leetcode31.cpp : �������̨Ӧ�ó������ڵ㡣
// ����һ�����У�ֱ��ʹ��STL�е�next_permutation��ʵ��
// ���Ƶ�STL�л���prev_permutation����
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

