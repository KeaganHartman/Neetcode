#include "Two_Sum.h"
Two_Sum::Two_Sum()
{
	std::vector<int> input = { 2, 7, 11, 15 };
	std::vector<int> rVec = twoSum(input, 9);
	int len = rVec.size();
	for (size_t i = 0; i < len; i++)
		std::cout << rVec[i] << std::endl;
	
}

std::vector<int> Two_Sum::twoSum(std::vector<int>& nums, int target)
{
	std::vector<int> rVec;
	std::unordered_map<int, int> mp_to_index;
	int len = nums.size();
	for (size_t i = 0; i < len; i++)
	{
		int lookingFor = target - nums[i];
		if (mp_to_index.find(lookingFor) != mp_to_index.end())
		{
			rVec.push_back(i);
			rVec.push_back(mp_to_index[lookingFor]);
			return rVec;
		}
		mp_to_index[nums[i]] = i;
	}
	return rVec;
    
}
