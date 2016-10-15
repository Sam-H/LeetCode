#pragma once
#include <vector>

struct ListNode {
	int val;
    ListNode *next;
	ListNode(int x) : val(x), next(0) {};
 };

class AddTwoNumbers {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* newHead = new ListNode(0);
		ListNode* currentNode = newHead;
		int carry = 0;

		while (carry || l1 || l2)
		{
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			if (sum < 10) {
				currentNode->next = new ListNode(sum);
				carry = 0;
			}
			else
			{
				currentNode->next = new ListNode(sum-10);
				carry = 1;
			}
			
			l1 = (l1 ? l1->next : l1);
			l2 = (l2 ? l2->next : l2);
			currentNode = currentNode->next;
		}

		return newHead->next;

	}
};