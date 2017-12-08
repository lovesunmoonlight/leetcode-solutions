// leetcode657.cpp : �������̨Ӧ�ó������ڵ㡣
// ����෴�����ߵĲ����Ƿ�һ�£�һ�¿��Իص����

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int size = moves.size();
		if (size % 2 == 1)
			return false;
		map<char, int> m;
		for (int i = 0; i < size; i++)
			m[moves[i]]++;
		if (m['U'] != m['D'])
			return false;
		if (m['L'] != m['R'])
			return false;
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.judgeCircle("LL") << endl;
	system("pause");
	return 0;
}

