#pragma once
#include <unordered_map>

using std::vector;

class TwoSum_HashTable {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		vector<int> result;
		std::unordered_map<int,int> difference_table;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (difference_table.find(nums[i]) != difference_table.end()) return vector<int>({ difference_table.find(nums[i])->second, i });
			difference_table.insert({ target - nums[i], i });
		}

		return result;

	}
};