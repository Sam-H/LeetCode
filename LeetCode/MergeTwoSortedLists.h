#pragma once

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(0) {}
 };

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode* newListHead = new ListNode(0);
		ListNode* currentNode = newListHead;

		while (l1 && l2)
		{
			if (l1->val <= l2->val)
			{
				currentNode->next = l1;
				l1 = l1->next;
			}
			else
			{
				currentNode->next = l2;
				l2 = l2->next;
			}

			currentNode = currentNode->next;
		}

		currentNode->next = l1 ? l1 : l2;

		ListNode* resultingHead = newListHead->next;
		delete newListHead;

		return resultingHead;

	}
};