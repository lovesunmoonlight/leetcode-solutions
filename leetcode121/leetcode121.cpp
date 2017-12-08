// leetcode121.cpp : 定义控制台应用程序的入口点。
// 总共只能有一次买入和卖出的机会


#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		if (size < 2)
			return 0;

		vector<int> profit; //每一天的最大利润
		profit.resize(size);

		int max = 0;
		int last = prices[size - 1]; 
		for (int i = size - 2; i >= 0; i--)
		{
			//last表示接下来的最高价格
			if (prices[i] <= last) //如果这个价格比当前价格高，这个时间点买入的最大利润是last-prices[i]
			{
				max = max > last - prices[i] ? max : last - prices[i];
				profit[i] = last - prices[i];
			}
			else //如果这个价格比当前价格低，这个时间买入不会盈利，同时将这个价格更新为当前价格
				last = prices[i];
		}

		cout << endl;
		return max;

	}
};

int main()
{
	Solution s;
	cout << s.maxProfit(vector<int>{7, 1, 5, 3, 6, 4}) << endl;
	system("pause");
	return 0;
}

