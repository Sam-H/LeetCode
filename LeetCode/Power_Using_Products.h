#pragma once

class Solution {
public:
	double myPow(double x, int n) {

		if (n == 0) return 1;

		double result = myPow(x, n / 2);
		result *= result;
		if (n % 2 == 1) result *= x;
		if (n % 2 == -1) result /= x;

		return result;
	}
};