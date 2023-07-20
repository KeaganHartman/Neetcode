#include "Contains_Duplicate.h"

Contains_Duplicate::Contains_Duplicate()
{
    // Create Test Input and Output details testing algorithm
    vector<int> input = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
    cout << containsDuplicate(input);
}
bool Contains_Duplicate::containsDuplicate(vector<int> nums)
{
    set<int> mp;
    for (size_t i = 0; i < nums.size(); i++)
        if (mp.find(nums[i]) != mp.end())
            return true;
        else
            mp.insert(nums[i]);

    return false;
}
