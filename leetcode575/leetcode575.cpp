// leetcode575.cpp : 定义控制台应用程序的入口点。
// 注意对数组去重之前，必须保证数组有序

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		int num = candies.size() / 2;
		sort(candies.begin(), candies.end());

		//it返回第一个重复元素的位置
		auto it=unique(candies.begin(), candies.end());

		//不重复元素的数量
		int cnt = it - candies.begin();

		//最多的种类是糖果数量的一半
		if (cnt >= num)
			return num;
		return cnt;
	}
};

int main()
{
	Solution S;
	vector<int> v = { 1,1,2,3 };
	cout<<S.distributeCandies(v)<<endl;
	system("pause");
	return 0;
}

