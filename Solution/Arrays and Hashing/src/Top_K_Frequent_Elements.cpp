#include "Top_K_Frequent_Elements.h"

Top_K_Frequent_Elements::Top_K_Frequent_Elements()
{
    vector<int> input = { 1,1,1,2,2,3 };
	vector<int> r = topKFrequent(input, 2);
	int len = r.size();
	for (size_t i = 0; i < len; i++)
		cout << r[i] << " ";
}
vector<int> Top_K_Frequent_Elements::topKFrequent(vector<int>& nums, int k)
{
	if (k == nums.size())
		return nums;

	// Count Number of Each Element
	unordered_map<int, int> countMp;

	for (size_t i = 0; i < nums.size(); i++)
		++countMp[nums[i]];

	// Sort numbers into a bucket according to frequency (max frequency = nums.size()
	vector<vector<int>> frequencyBucket;
	frequencyBucket.resize(nums.size());
	for (auto it : countMp)
		frequencyBucket[it.second - 1].push_back(it.first);
	
	// Loop through frequency buckets in reverse and push contents into return vector
	vector<int> returnVec;
	int iter = frequencyBucket.size() - 1;
	while (returnVec.size() != k)
	{
		for (size_t i = 0; i < frequencyBucket[iter].size(); i++)
		{
			returnVec.push_back(frequencyBucket[iter][i]);
			if (returnVec.size() == k)
				return returnVec;
		}
		--iter;
	}

	return returnVec;
}	
