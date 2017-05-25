// leetcode237.cpp : �������̨Ӧ�ó������ڵ㡣
// ɾ���������е�ĳ�����
// Accepted

#include "stdafx.h"
#include <iostream>
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
	void deleteNode(ListNode* node) {
		*node = *node->next;

	}
};


int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	Solution s;
	s.deleteNode(head->next);
	decltype(head) p = head;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	system("pause");
	return 0;
}

