#pragma once
#include "includes.h"
class Valid_Anagram
{
public:
	Valid_Anagram();
private:
	// Given two strings (s) and (t) return (true) if (t) is an anagram of (s), and false otherwise
	// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
	// typically using all of the original letters exactly once.
	bool isAnagram(string s, string t);
};

