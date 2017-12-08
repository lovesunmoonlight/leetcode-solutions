// leetcode122.cpp : 定义控制台应用程序的入口点。
// 贪心
// Accepted
// 每天有一次买入和卖出的机会
// 所以只要某天的价格大于它之前一天的价格，就在之前一天买入
// 并在第二天卖出，这样一定盈利最大

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		int ans = 0;
		for (int i = 1; i < size; i++)
			if (prices[i] >= prices[i - 1])
				ans += prices[i] - prices[i - 1];
		return ans;
	}
};

int main()
{
	Solution s;
	cout<<s.maxProfit(vector<int>{2,1,4})<<endl;
	system("pause");
	return 0;
}

