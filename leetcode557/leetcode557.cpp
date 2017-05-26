// leetcode557.cpp : �������̨Ӧ�ó������ڵ㡣
// ��һ���Կո�ָ�ĵ����е�ÿһ����ת
// ����istringstream

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string reverseWords(string s)
{
	istringstream is(s);
	string temp;
	string ans;
	while (is >> temp)
	{
		reverse(temp.begin(), temp.end());
		ans += temp;
		ans += ' ';
	}
	ans.pop_back();
	return ans;
}


int main()
{
	string s;
	while (getline(cin, s))
	{
		cout << reverseWords(s)<<endl;
	}
	system("pause");
	return 0;
}

