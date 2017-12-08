// leetcode575.cpp : �������̨Ӧ�ó������ڵ㡣
// ע�������ȥ��֮ǰ�����뱣֤��������

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

		//it���ص�һ���ظ�Ԫ�ص�λ��
		auto it=unique(candies.begin(), candies.end());

		//���ظ�Ԫ�ص�����
		int cnt = it - candies.begin();

		//�����������ǹ�������һ��
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

