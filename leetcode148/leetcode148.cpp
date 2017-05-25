// leetcode148.cpp : 定义控制台应用程序的入口点。
// 链表排序，要求O(nlogn)
// 偷懒用了STL的快排，以后要自己手撸一遍数组和链表的快排
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

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
	ListNode* sortList(ListNode* head) {
		ListNode* p = head;
		vector<int> a;
		while (p)
		{
			a.push_back(p->val);
			p = p->next;
		}
		sort(a.begin(), a.end(), [](const int& a, const int& b){return a > b; });
		p = head;
		while (p)
		{
			p->val= a.back();
			a.pop_back();
			p = p->next;
		}
		return head;
	}
};


int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(5);
	head->next->next = new ListNode(6);
	Solution S;
	head=S.sortList(head);
	ListNode* p = head;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	system("pause");
	return 0;
}

