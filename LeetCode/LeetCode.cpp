// LeetCode.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>
#include "Power_Using_Products.h"

int main()
{
	
	Solution tester;
	double result = tester.myPow(2, -4);
	_CrtDumpMemoryLeaks();

	std::cout << result << std::endl;

    return 0;
}

