// leetcode92.cpp : 定义控制台应用程序的入口点。
// 反转链表中的部分元素
// 注意尽量不要把原始指针保存在容器中
// Accepted

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

/**
* Definition for singly-linked list.
* */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* p = head;
		for (int i = 1; i < m; i++)
			p = p->next;
		ListNode* pos_m = p;
		p = head;
		for (int i = 1; i < n; i++)
			p = p->next;
		ListNode* pos_n = p;

		stack<int> S;
		ListNode* pp = pos_m;
		while (pp != pos_n)
		{
			S.push(pp->val);
			pp = pp->next;
		}
		S.push(pos_n->val);
		pp = pos_m;
		while (pp != pos_n)
		{
			pp->val = S.top();
			S.pop();
			pp = pp->next;
		}
		pp->val = S.top();
		S.pop();
		return head;

	}
};


int main()
{
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution S;
	head=S.reverseBetween(head, 2, 4);
	ListNode* p = head;
	while (p)
	{
		cout << p->val << endl;;
		p = p->next;
	}
	system("pause");
	return 0;
}

