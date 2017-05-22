// leetcode238.cpp : �������̨Ӧ�ó������ڵ㡣
// ���������ÿ��Ԫ�س��䱾��ʣ��Ԫ�صĳ˻�
// ��ĿҪ��ʱ��O(n)���ռ�O(1)
// Ϊ�˿ɽ�ÿ��Ԫ���������Ԫ�صĻ����ұ�����Ԫ�صĻ��������,��˼���
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

