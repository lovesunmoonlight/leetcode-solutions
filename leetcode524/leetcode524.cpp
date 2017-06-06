// leetcode524.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string findLongestWord(string s, vector<string>& d)
{
	vector<string> ans;
	for (int i = 0; i < d.size(); i++)
	{
		//���е�Ԫ�ض���s��
		if (d[i].find_first_not_of(s) == string::npos)
			ans.push_back(d[i]);
	}
	sort(ans.begin(), ans.end(), [](const string& s1, const string& s2) {return s1 < s2; });
	return *(--ans.end());
}


int main()
{
	string s = "abpcplea";
	vector<string> d = { "ale","apple","monkey","plea" };
	string ans = findLongestWord(s, d);
	cout << ans << endl;
	system("pause");
	return 0;
}

