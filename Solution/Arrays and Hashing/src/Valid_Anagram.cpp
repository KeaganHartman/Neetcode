#include "Valid_Anagram.h"
Valid_Anagram::Valid_Anagram()
{
    std::cout << isAnagram("rat", "car");
}
bool Valid_Anagram::isAnagram(std::string s, std::string t)
{
    if (s.size() != t.size())
        return false;

    std::unordered_map<char, int> mp_s;
    std::unordered_map<char, int> mp_t;
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
