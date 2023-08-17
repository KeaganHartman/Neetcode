#include "Evaluate_Reverse_Polish.h"

Evaluate_Reverse_Polish::Evaluate_Reverse_Polish()
{
    vector<string> input = { "2", "1", "+", "3", "*" };
    std::cout << evalRPN(input);
}

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a + b; }
int divide(int a, int b) { return a / b; }
int multiply(int a, int b) { return a * b; }

int Evaluate_Reverse_Polish::evalRPN(vector<string>& tokens)
{
    map<string, int(*)(int, int)> evalMap = {
        {"+", add },
        {"/", divide },
        {"-", subtract },
        {"*", multiply },
    };

    stack<int> numbers;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (evalMap.find(tokens[i]) == evalMap.end())
            numbers.push(stoi(tokens[i]));

        else
        {
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            numbers.push(evalMap[tokens[i]](a, b));
        }
    }

    return numbers.top();
}
