// leetcode206.cpp : 定义控制台应用程序的入口点。
// 反转单链表
// 利用一个栈来实现
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <stack>

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
	ListNode* reverseList(ListNode* head) {
		decltype(head) p = head;
		if (!p || !(p->next))
			return head;
		stack<ListNode*> S;
		while (p)
		{
			S.push(p);
			p = p->next;
		}
		p = S.top();
		head = p;
		S.pop();
		while (!S.empty())
		{
			p->next = S.top();
			S.pop();
			p = p->next;
		}
		p->next = nullptr;
		return head;
	}
};


int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	Solution s;
	head=s.reverseList(head);
	while (head)
	{
		cout << head->val << endl;
		head = head->next;
	}
	system("pause");
	return 0;
}

