// leetcode832.cpp : �������̨Ӧ�ó������ڵ㡣
// ����һ�������ƾ���
// ��תÿһ�У��ٽ���������ȡ��

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;

class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
	{
		if (A.size() == 0 || A[0].size() == 0)
			return vector<vector<int>>();

		auto ans = A;
		for (auto &i : ans)
		{
			std::reverse(i.begin(), i.end());
			for (auto &j : i)
				j = !j;
		}

		return ans;
	}
};

int main()
{
	vector<vector<int>> v1 = { {1,1,0},{1,0,1},{0,0,0} };
	vector<vector<int>> v2 = { {1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0} };
	Solution S;
	auto ans = S.flipAndInvertImage(v1);
	for (auto i : ans)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	ans = S.flipAndInvertImage(v2);
	for (auto i : ans)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	system("pause");
    return 0;
}

