// leetcode717.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;

class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int size = bits.size();
		bool flag = true;
		for (int i = 0; i < size;)
		{
			if (bits[i] == 1)
			{
				i = i + 2;
				flag = false; //上一个是两位编码
			}
			else if (bits[i] == 0)
			{
				i++;
				flag = true; //上一个是一位编码
			}
		}
		return flag;
	}
};

int main()
{
	vector<int> bits = { 1, 1, 1, 0, 0 };
	Solution S;
	cout << S.isOneBitCharacter(bits) << endl;

	system("pause");
	return 0;
}

