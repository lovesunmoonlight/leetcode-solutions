// leetcode445.cpp : 定义控制台应用程序的入口点。
// 链表结点存储数字的各位
// 模拟加法
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
* Definition for singly-linked list.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		vector<int> s1, s2, ans;
		while (p1)
		{
			s1.push_back(p1->val);
			p1 = p1->next;
		}
		while (p2)
		{
			s2.push_back(p2->val);
			p2 = p2->next;
		}
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		int len1 = s1.size();
		int len2 = s2.size();
		int len = len1 < len2 ? len1 : len2;
		int flag = 0; //进位标志
		for (int i = 0; i < len; i++)
		{
			int sum = s1[i] + s2[i] + flag;
			if (sum >= 10)
			{
				sum -= 10;
				flag = 1;
			}
			else
				flag = 0;
			ans.push_back(sum);
		}
		for (int i = len; i < len1; i++)
		{
			int sum = s1[i] + flag;
			if (sum >= 10)
			{
				sum -= 10;
				flag = 1;
			}
			else
				flag = 0;
			ans.push_back(sum);
		}
		for (int i = len; i < len2; i++)
		{
			int sum = s2[i] + flag;
			if (sum >= 10)
			{
				sum -= 10;
				flag = 1;
			}
			else
				flag = 0;
			ans.push_back(sum);
		}
		if (flag == 1)
			ans.push_back(1);
		ListNode* result=new ListNode(ans.back());
		ListNode* p = result;
		ans.pop_back();
		while (!ans.empty())
		{
			p->next = new ListNode(ans.back());
			ans.pop_back();
			p = p->next;
		}
		return result;

	}
};

int main()
{
	ListNode* l1 = new ListNode(7);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);
	l1->next->next->next = new ListNode(3);
	ListNode* p1 = l1;
	cout << "l1:" << endl;
	while (p1)
	{
		cout << p1->val;
		p1 = p1->next;
	}
	cout << endl;

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	ListNode* p2 = l2;
	cout << "l2:" << endl;
	while (p2)
	{
		cout << p2->val;
		p2 = p2->next;
	}
	cout << endl;

	Solution S;
	ListNode* ans = S.addTwoNumbers(l1, l2);
	cout << "ans:" << endl;
	while (ans)
	{
		cout << ans->val;
		ans = ans->next;
	}
	cout << endl;
	system("pause");
	return 0;
}

