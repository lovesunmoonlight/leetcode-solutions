// leetcode717.cpp : �������̨Ӧ�ó������ڵ㡣
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
				flag = false; //��һ������λ����
			}
			else if (bits[i] == 0)
			{
				i++;
				flag = true; //��һ����һλ����
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

