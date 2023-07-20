#include "Group_Anagrams.h"
Group_Anagrams::Group_Anagrams()
{
    vector<string> input = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> r = groupAnagrams(input);

    for (size_t i = 0; i < r.size(); i++)
    {
        cout << "List " << i + 1 << endl;
        for (size_t j = 0; j < r[i].size(); j++)
        {
            cout << r[i][j] << endl;
        }
    }
}
vector<vector<string>> Group_Anagrams::groupAnagrams(vector<string>& strs)
{
    // Create a map that holds anagram map, and list of words that belong to anagram map
    map<map<char, int>, vector<string>> master_mp; // anagram map -> strs

    int len = strs.size();
    for (size_t i = 0; i < len; i++)
    {
        map<char, int> temp_mp;
        int strLen = strs[i].size();

        for (size_t j = 0; j < strLen; j++)
            ++temp_mp[strs[i][j]];

        master_mp[temp_mp].push_back(strs[i]);
    }

    vector<vector<string>> rList;
    for (auto it : master_mp)
        rList.push_back(it.second);
    
    return rList;
}
