#include "Valid_Anagram.h"
Valid_Anagram::Valid_Anagram()
{
    cout << isAnagram("rat", "car");
}
bool Valid_Anagram::isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, int> mp_s;
    unordered_map<char, int> mp_t;
    int len = s.size();
    for (size_t i = 0; i < len; i++)
    {
        ++mp_s[s[i]];
        ++mp_t[t[i]];
    }
    if (mp_s == mp_t)
        return true;
        
    return false;
}
