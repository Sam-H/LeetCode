// LeetCode.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "MergeTwoSortedLists.h"
int main()
{
	Solution tester;

	ListNode l1(1);
	ListNode l12(3);
	ListNode l13(7);
	l1.next = &l12;
	l12.next = &l13;

	ListNode l2(2);
	ListNode l22(4);
	ListNode l23(6);
	l2.next = &l22;
	l22.next = &l23;

	ListNode* result = tester.mergeTwoLists(&l1,&l2);

	_CrtDumpMemoryLeaks();

    return 0;
}

