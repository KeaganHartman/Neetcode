#pragma once
#include "includes.h"
class Product_of_Array_Except_Self
{
public:
	Product_of_Array_Except_Self();
private:
	/*Given an integer array (nums), return an array (answer) such that (answer[i]) is equal to the product of all
	the elements of nums except (nums[i]).
	No Division. O(n)*/
	vector<int> productExceptSelf(vector<int>& nums);
};

