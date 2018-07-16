// leetcode746.cpp : �������̨Ӧ�ó������ڵ㡣
// ÿ�ο�����һ��������̨��
// ����ѡ���0�����1��̨�׿�ʼ��
// ÿ��̨���ж�Ӧ���ѣ����������˵���С����
// dp

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) 
	{
		if (cost.empty())
			return 0;
		if (cost.size() == 1)
			return cost[0];
		if (cost.size() == 2)
			return min(cost[0], cost[1]);

		int len = cost.size();
		vector<int> dp;
		dp.resize(len + 1);

		int temp1, temp2;

		//�ӵ�0��¥�ݿ�ʼ��
		dp[0] = 0;
		dp[1] = cost[0];
		for (int i = 2; i <= len; i++)
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		temp1 = dp[len];

		//�ӵ�һ��¥�ݿ�ʼ��
		dp[1] = 0;
		dp[2] = cost[1];
		for (int i = 3; i <= len; i++)
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		temp2 = dp[len];

		dp[len] = temp1 < temp2 ? temp1 : temp2; //ȡ��С��

		return dp[len];
	}

	int min(int a, int b)
	{
		return a < b ? a : b;
	}
};

int main()
{
	vector<int> v1 = { 10,15,20 };
	vector<int> v2 = { 1,100,1,1,1,100,1,1,100,1 };

	Solution S;
	cout << S.minCostClimbingStairs(v1) << endl;
	cout << S.minCostClimbingStairs(v2) << endl;

	system("pause");
    return 0;
}

