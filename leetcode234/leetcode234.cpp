// leetcode234.cpp : �������̨Ӧ�ó������ڵ㡣
// �жϻ��Ĵ�
// ��������ת�����αȽϸ�Ԫ��
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

