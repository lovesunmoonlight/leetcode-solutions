// leetcode147.cpp : �������̨Ӧ�ó������ڵ㡣
// δ�ύ

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

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
	ListNode* insertionSortList(ListNode* head) {
		ListNode* p = head;
		if (p == nullptr || p->next == nullptr)
			return head;

		//start from the second element
		p = p->next;

		//make a new list as answer
		ListNode* ans = new ListNode(p->val);
		ListNode* sorted = ans; //already sorted portion

		while (p)
		{
			if (p->val <= sorted->val)
			{
				ListNode* temp = new ListNode(p->val);
				temp->next = ans;
				ans = temp;
			}
			else
			{
				while (sorted->val <= p->val)
				{
					sorted = sorted->next;
				}
			}
			p = p->next;
		}

	}
};


int main()
{
	system("pause");
	return 0;
}

