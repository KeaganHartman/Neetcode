#include "Valid_Parentheses.h"

Valid_Parentheses::Valid_Parentheses()
{
	string input = "(){}}{";
	cout << isValid(input);
}

bool Valid_Parentheses::isValid(string s)
{
	unordered_map<char, char> mp = { {'(', ')'}, {'[', ']'}, {'{', '}'} };
	stack<char> stk;
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		// If Opening Bracket
		if (mp.find(s[i]) != mp.end())
			stk.push(mp[s[i]]);

		// If Closing Bracket
		else
		{
			if (!stk.empty() && stk.top() == s[i])
				stk.pop();
			else
				return false;
		}
	}

	if (stk.empty())
		return true;

	return false;
}
