#include "Valid_Palindrome.h"

Valid_Palindrome::Valid_Palindrome()
{
	string input = "race a car";
	cout << isPalindrome(input);
}

bool Valid_Palindrome::isPalindrome(string s)
{
	int p1 = 0;
	int p2 = s.size()-1;

	while (p1 <= p2)
	{
		if (!isalnum(s[p1])) { ++p1; continue; }
		if (!isalnum(s[p2])) { --p2; continue; }
		if (tolower(s[p1]) != tolower(s[p2]))
			return false;
		else
			++p1; --p2;
	}

	return true;
}
