// leetcode498.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		int row = matrix.size();

		//边界条件
		if (row == 0)
			return vector<int>();
		int col = matrix[0].size();
		if (col == 0)
			return vector<int>();



	}
};

int main()
{
	
	system("pause");
	return 0;
}

