// leetcode628.cpp : �������̨Ӧ�ó������ڵ㡣
// �ҳ�������ǰn�����
// ������ʵ��

/******************/
// ��ʼ����Ϊ�ǿ�����������Ҫ���ѣ��������־�Ȼ�и���
// ֱ�ӽ�������������������ҪôΪ����������(ͬ��)
// ҪôΪ1��2��

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

