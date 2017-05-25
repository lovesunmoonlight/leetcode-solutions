// leetcode141.cpp : �������̨Ӧ�ó������ڵ㡣
// TLE

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <set>

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
	bool hasCycle(ListNode *head) {
		//�ս���next��Ϊ�յĵ�������޻�
		if (!head || !(head->next))
			return false;
		decltype(head) p = head;
		decltype(head) q = head;
		set<ListNode*> S;
		/*while (p)
		{
			//ָ������
			if (p->next == p)
				return true;
			//ָ��ǰ��Ľ��
			while (q!=p)
			{
				if ((p->next == q))
					return true;
				q = q->next;
			}
			p = p->next;
			q = head;
		}*/
		int cnt = 0;
		while (p)
		{
			cnt++;
			S.insert(p);
			if (cnt-S.size()!=0);
			{
				cout << S.size() << endl;
				cout << cnt << endl;
				return true; 
			}
			p = p->next;
		}
		return false;

	}
};


int main()
{
	ListNode* head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(-4);
	//head->next->next->next->next = head;
	Solution s;
	if (s.hasCycle(head))
		cout << "There is a cycle." << endl;
	else
		cout << "There is not a cycle." << endl;
	decltype(head) p = head;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
		if (p == head)
			break;
	}
	system("pause");
	return 0;
}

