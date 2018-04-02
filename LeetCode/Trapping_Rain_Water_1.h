#pragma once
#include <vector>
#include <algorithm>
#include <iterator>

class Solution {
public:
	int trap(std::vector<int>& height)
	{
		int sum = 0;

		if (height.size() > 0)
		{
		
			std::vector<int> vMaxLeft(height.size(), 0);
			std::vector<int> vMaxRight(height.size(), 0);

			for (auto nIndex = 1; nIndex < height.size(); ++nIndex)
			{
				vMaxLeft[nIndex] = std::max(vMaxLeft[nIndex - 1], height[nIndex - 1]);
				vMaxRight[height.size() - nIndex - 1] = std::max(vMaxRight[height.size() - nIndex], height[height.size() - nIndex]);
			}

			for (auto it = height.begin() + 1; it != height.end(); ++it)
			{
				int & maxLeft = vMaxLeft[it - height.begin()];
				int & maxRight = vMaxRight[it - height.begin()];

				if (maxLeft > *it && maxRight > *it ) sum += std::min(maxLeft, maxRight) - (*it);
			}

		}

		return sum;
	}
};