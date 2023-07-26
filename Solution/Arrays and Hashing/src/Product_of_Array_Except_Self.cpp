#include "Product_of_Array_Except_Self.h"

Product_of_Array_Except_Self::Product_of_Array_Except_Self()
{
    vector<int> input = { 1, 2, 3, 4 };
    vector<int> output = productExceptSelf(input);
    for (size_t i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
}

vector<int> Product_of_Array_Except_Self::productExceptSelf(vector<int>& nums)
{
    // Create Prefix Products List [1, 2, 6, 24]
    vector<int> prefix_products;
    int prod = 1;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        prod *= nums[i];
        prefix_products.push_back(prod);
    }

    // Create Postfix Products List [24, 24, 12, 4]
    vector<int> postfix_products;
    postfix_products.resize(nums.size());
    prod = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        prod *= nums[i];
        postfix_products[i] = prod;
    }

    // Last Loop Calculates Return Vector
    vector<int> rVector;
    for (int i = 0; i < len; i++)
    {
        int temp = 1;
        // Check Right
        if (i + 1 < len)
            temp *= postfix_products[i + 1];
        // Check Left
        if (i - 1 >= 0)
            temp *= prefix_products[i - 1];

        rVector.push_back(temp);
    }

    return rVector;
}
