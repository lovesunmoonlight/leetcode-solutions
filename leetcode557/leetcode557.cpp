// leetcode557.cpp : 定义控制台应用程序的入口点。
// 对一行以空格分割的单词中的每一个反转
// 借助istringstream

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

