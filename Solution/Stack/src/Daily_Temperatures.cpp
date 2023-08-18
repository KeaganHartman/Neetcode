#include "Daily_Temperatures.h"

Daily_Temperatures::Daily_Temperatures()
{
	vector<int> input = { 73,74,75,71,69,72,76,73 };
	vector<int> output = dailyTemperatures(input);
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << " ";
	}
}

vector<int> Daily_Temperatures::dailyTemperatures(vector<int>& temperatures)
{
	stack<int> stk;
	int n = temperatures.size();
	vector<int> rVec(n, 0);

	for (size_t i = 0; i < n; i++)
	{
		// If Stack is empty, no temps to compare, add temp to stack
		if (stk.empty())
		{
			stk.push(i);
			continue;
		}

		while (!stk.empty() && temperatures[stk.top()] < temperatures[i])
		{
			rVec[stk.top()] = i - stk.top();
			stk.pop();
		}

		stk.push(i);
	}

	return rVec;
}
