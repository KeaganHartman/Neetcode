#pragma once
#include "includes.h"
class Two_Sum
{	
public:
	Two_Sum();
private:
	// Given an array of (nums) and an integer (target), return indices of the two numbers such that they add up to (target).
	// Assume each input has exactly one solution, and the same element will not be repeated.
	vector<int> twoSum(vector<int>& nums, int target);
};

