// LeetCode.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Spiral_Matrix.h"

int main()
{
	
	Solution tester;

	Solution::Matrix mat = { {1,2,3}, {4,5,6}, {7,8,9}};
	Solution::Vector vec = tester.spiralOrder(mat);

    return 0;
}
