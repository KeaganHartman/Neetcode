#include "Generate_Parenthesis.h"

Generate_Parenthesis::Generate_Parenthesis()
{
    vector<string> output = generateParenthesis(3);
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << endl;
	}
}

vector<string> Generate_Parenthesis::generateParenthesis(int n)
{
	struct structure {
		string result;
		int openCount;
		int closeCount;
	};

	vector<structure> rList;
	rList.push_back({ "(", 1, 0 });

	while (rList[0].result.size() < n * 2)
	{
		int iterations = rList.size();

		for (size_t i = 0; i < iterations; i++)
		{
			bool canOpen = false;
			bool canClose = false;

			if (rList[i].closeCount < rList[i].openCount)
				canClose = true;
			if (rList[i].openCount < n)
				canOpen = true;

			if (canOpen && canClose)
			{
				string temp = rList[i].result;
				temp.append(")");
				rList.push_back({ temp, rList[i].openCount, rList[i].closeCount + 1 });

				rList[i].result.append("(");
				++rList[i].openCount;
			}
			else if (canOpen)
			{
				rList[i].result.append("(");
				rList[i].openCount++;
			}

			else if (canClose)
			{
				rList[i].result.append(")");
				rList[i].closeCount++;
			}
		}
	}

	vector<string> rVec;

	// Loop through and Return List of results
	for (size_t i = 0; i < rList.size(); i++)
	{
		rVec.push_back(rList[i].result);
	}

	return rVec;
}
