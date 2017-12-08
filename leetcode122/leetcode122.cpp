// leetcode122.cpp : �������̨Ӧ�ó������ڵ㡣
// ̰��
// Accepted
// ÿ����һ������������Ļ���
// ����ֻҪĳ��ļ۸������֮ǰһ��ļ۸񣬾���֮ǰһ������
// ���ڵڶ�������������һ��ӯ�����

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
