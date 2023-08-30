#include "TwoSumII_SortedArray.h"

TwoSumII_SortedArray::TwoSumII_SortedArray()
{
	vector<int> input = { 2,3,4 };
	vector<int> output = twoSum(input, 6);
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << " ";
	}
}

vector<int> TwoSumII_SortedArray::twoSum(vector<int>& numbers, int target)
{
	int p1 = 0;
	int p2 = numbers.size() - 1;
	int total;

	while (p1 < p2)
	{
		total = numbers[p1] + numbers[p2];
		if (total == target)
		{
			vector<int> r = { p1+1, p2+1 };
			return r;
		}


		if (total < target)
			++p1;
		else if (total > target)
			--p2;
	} 

	return vector<int>();
}
