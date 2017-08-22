// leetcode120.cpp : �������̨Ӧ�ó������ڵ㡣
// ̰��
// ÿ��ѡ��ǰ�ڵ�cur������ӻ��Ҷ����н�С��
// ��������Ϊcur���Ҷ������Ϊcur+1
// δAC

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int len = triangle.size(); //����
		int ans = 0;
		int cur = 0; //��ǰ���е�λ��
		ans += triangle[0][0];
		for (int i = 0; i < len-1; i++)
		{
			if (triangle[i + 1][cur] < triangle[i + 1][cur + 1])
			{
				ans += triangle[i + 1][cur];
			}
			else
			{
				ans += triangle[i + 1][cur + 1];
				++cur;
			}
		}
		return ans;

	}
};


int main()
{
	Solution S;
	vector<vector<int>> v = { {2},{3,4},{6,5,7},{4,1,8,3} };
	int ans = S.minimumTotal(v);
	cout << ans << endl;
	system("pause");
	return 0;
}

