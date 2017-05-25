// leetcode234.cpp : 定义控制台应用程序的入口点。
// 判断回文串
// 将单链表反转后依次比较各元素
// Accepted

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

/**
* Definition for singly-linked list.
**/ 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		decltype(head) p = head;
		if (!p || !(p->next))
			return true;
		stack<ListNode*> S;
		while (p)
		{
			S.push(p);
			p = p->next;
		}
		p = head;
		while (!S.empty())
		{
			ListNode* temp = S.top();
			S.pop();
			if (temp->val != p->val)
				return false;
			p = p->next;
		}
		return true;

	}
};

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(3);
	Solution S;
	if (S.isPalindrome(head))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	system("pause");
	return 0;
}

