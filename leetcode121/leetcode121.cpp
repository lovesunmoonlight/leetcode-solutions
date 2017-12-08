// leetcode121.cpp : �������̨Ӧ�ó������ڵ㡣
// �ܹ�ֻ����һ������������Ļ���


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

		vector<int> profit; //ÿһ����������
		profit.resize(size);

		int max = 0;
		int last = prices[size - 1]; 
		for (int i = size - 2; i >= 0; i--)
		{
			//last��ʾ����������߼۸�
			if (prices[i] <= last) //�������۸�ȵ�ǰ�۸�ߣ����ʱ�����������������last-prices[i]
			{
				max = max > last - prices[i] ? max : last - prices[i];
				profit[i] = last - prices[i];
			}
			else //�������۸�ȵ�ǰ�۸�ͣ����ʱ�����벻��ӯ����ͬʱ������۸����Ϊ��ǰ�۸�
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

