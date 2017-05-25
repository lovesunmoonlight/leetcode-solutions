// leetcode83.cpp : �������̨Ӧ�ó������ڵ㡣
// ɾ���������е��ظ�Ԫ��
// ͨ��������������Ķ������������
// Accepted

#include "stdafx.h"
#include <iostream>
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
	ListNode* deleteDuplicates(ListNode* head) {
		decltype(head) p = head;
		//ֻ��0��1�����ֱ�ӷ���
		if (!p||!(p->next))
			return p;

		while (p)
		{
			//ע����p���¸�����Ƿ�Խ��
			if ((p->next)&& (p->val == p->next->val))
			{
				ListNode* q = p->next;
				//�ҵ���һ������ȵĽ��
				while (q&&(q->val == p->val))
					q = q->next;
				//������Щ��ȵĽ��
				p->next = q;
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
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(3);
	decltype(head) p = head;
	cout << "Before:" << endl;
	while (p)
	{
		cout << p->val<<endl;
		p = p->next;
	}
	Solution s;
	p=s.deleteDuplicates(head);
	cout << "After:" << endl;
	while (p)
	{
		cout << p->val<<endl;
		p = p->next;
	}

	system("pause");
	return 0;
}

