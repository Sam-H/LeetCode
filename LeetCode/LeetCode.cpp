// LeetCode.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Copy_List_with_Random_Pointer.h"

int main()
{
	
	Solution tester;

	RandomListNode initialList(-1);
	RandomListNode node(-1);

	initialList.next = &node;
	RandomListNode* copy = tester.copyRandomList(&initialList);

    return 0;
}
