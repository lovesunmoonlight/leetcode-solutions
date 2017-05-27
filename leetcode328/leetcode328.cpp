// leetcode328.cpp : �������̨Ӧ�ó������ڵ㡣
// �����������λ�ý�����ż�����֮ǰ
// ����ο���Solution��������������������
// Accepted

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

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
	ListNode* oddEvenList(ListNode* head) {
		//�п�
		if (!head||!head->next)
			return head;

		//������ĿҪ��O(1)�ռ临�Ӷȣ�����λ��ͷ���ֱ��Ĭ��Ϊԭ�������ͷ���
		ListNode* odditerator = head; //����λ�ý���������ͷ��㿪ʼ
		ListNode* evenhead = head->next; //ż��λ��ͷ���
		ListNode* eveniterator = evenhead; //ż��λ�ý�������
		//�ж�ż��λ�ü��ɣ�ż��λ�úϷ�����ǰ�������λ��һ������Խ��
		while (eveniterator&&eveniterator->next)
		{
			odditerator->next = odditerator->next->next;
			eveniterator->next = eveniterator->next->next;
			odditerator = odditerator->next;
			eveniterator = eveniterator->next;
		}
		odditerator->next = evenhead;
		return head;

	}
};

int main()
{
	ListNode* head = new ListNode(1);
	int i = 2;
	ListNode* p = head;
	while (i<=7)
	{
		p->next = new ListNode(i);
		p = p->next;
		++i;
	}
	p = head;
	cout << "Before:" << endl;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	Solution S;
	head = S.oddEvenList(head);
	p = head;
	cout << "After:" << endl;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	system("pause");
	return 0;
}

