// leetcode82.cpp : 定义控制台应用程序的入口点。
// WA

#include "stdafx.h"
#include <iostream>
#include <vector>

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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode* p = head;
		vector<int> s;
		while (p)
		{
			if (p->next&&p->val == p->next->val)
			{
				ListNode* q = p->next;
				while (q&&q->val == p->val)
				{
					q = q->next;
				}
				p->next = q;
				s.push_back(p->val);
			}
			p = p->next;
		}
		
		return head;

	}
};


int main()
{
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(1);
	head->next->next->next->next = new ListNode(1);
	head->next->next->next->next->next = new ListNode(1);
	head->next->next->next->next->next->next = new ListNode(1);
	Solution S;
	head=S.deleteDuplicates(head);
	ListNode* p = head;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	system("pause");
	return 0;
}

