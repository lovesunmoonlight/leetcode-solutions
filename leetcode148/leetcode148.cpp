// leetcode148.cpp : �������̨Ӧ�ó������ڵ㡣
// ��������Ҫ��O(nlogn)
// ͵������STL�Ŀ��ţ��Ժ�Ҫ�Լ���ߣһ�����������Ŀ���
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

