// LeetCode.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

#include "001_Add_Two_Numbers.h"
int main()
{
	AddTwoNumbers tester;

	ListNode l1(5);
	//ListNode l12(4);
	//ListNode l13(3);
	//l1.next = &l12;
	//l12.next = &l13;

	ListNode l2(5);
	//ListNode l22(6);
	//ListNode l23(4);
	//l2.next = &l22;
	//l22.next = &l23;

	tester.addTwoNumbers(&l1, &l2);


    return 0;
}

