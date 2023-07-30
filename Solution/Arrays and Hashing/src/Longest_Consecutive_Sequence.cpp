#include "Longest_Consecutive_Sequence.h"

Longest_Consecutive_Sequence::Longest_Consecutive_Sequence()
{
    vector<int> input = { 4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3 };
    cout << longestConsecutive(input);
}

int Longest_Consecutive_Sequence::longestConsecutive(vector<int>& nums)
{
    int len = nums.size();
    if (len == 0)
        return 0;

    int rInt = 1;
    unordered_map<int, int> mp;

    for (int i = 0; i < len; i++)
    {
        int curr = nums[i];
        int tcount = 1;
        int left = curr - 1;
        int right = curr + 1;
        int lCount = 0;
        int rCount = 0;


        if (mp.find(curr) != mp.end())
            continue;


        // If No Neighbors Exist
        if (mp.find(left) == mp.end() && mp.find(right) == mp.end())
        {
            mp[curr] = tcount;
            continue;
        }

        // If Left or Right Exist, total numbers
        if (mp.find(left) != mp.end())
        {
            lCount = mp[left];
            tcount += mp[left];
        }
        if (mp.find(right) != mp.end())
        {
            rCount = mp[right];
            tcount += mp[right];
        }
        
        int leftMost = curr - lCount;
        int rightMost = curr + rCount;

        mp[leftMost] = tcount;
        mp[rightMost] = tcount;
           
        if (tcount > rInt)
            rInt = tcount;
    }

    return rInt;
}
 