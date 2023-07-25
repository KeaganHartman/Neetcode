#pragma once
#include "includes.h"
class Top_K_Frequent_Elements
{
public:
	Top_K_Frequent_Elements();
private:
	// Given an integer array (nums) and an integer (k), return the (k) most frequent elements. 
	// You may return the answer in any order.
	vector<int> topKFrequent(vector<int>& nums, int k);
};

