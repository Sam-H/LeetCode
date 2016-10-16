#pragma once
#include "math.h"

class Solution {
public:
	double myPow(double x, int n) {

		if (x > 0)
		{
			return exp(n*log(x));
		}
		else
		{
			if (n % 2 == 0)
			{
				return exp(n*log(-x));
			}
			else
			{
				return -exp(n*log(-x));
			}
		}
	}
};