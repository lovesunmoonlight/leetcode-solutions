// 728.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ans;
		for (int i = left; i <= right; i++)
			if (check(i))
				ans.push_back(i);
		
		return ans;
	}

	bool check(int a)
	{
		int temp = a;
		vector<int> digit;
		while (temp)
		{
			if (temp % 10 == 0)
				return false;
			digit.push_back(temp % 10);
			temp /= 10;
		}
		for (auto i : digit)
		{
			if (a%i != 0)
				return false;
		}
		return true;
	}
};


int main()
{
	Solution S;
	auto ans=S.selfDividingNumbers(1, 22);
	for (auto i : ans)
		cout << i << endl;
	system("pause");
	return 0;
}

