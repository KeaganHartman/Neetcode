#include "Largest_Rectangle_In_Histogram.h"

Largest_Rectangle_In_Histogram::Largest_Rectangle_In_Histogram()
{
    vector<int> input = { 2, 1, 5, 6, 2, 3 };
    cout << largestRectangleArea(input);
}

int Largest_Rectangle_In_Histogram::largestRectangleArea(vector<int>& heights)
{
    // pair: [index, height]
    stack<pair<int, int>> stk;
    int result = 0;
    int n = heights.size();

    for (int i = 0; i < n; i++) {
        int start = i;

        while (!stk.empty() && stk.top().second > heights[i]) {
            int index = stk.top().first;
            int width = i - index;
            int height = stk.top().second;
            stk.pop();

            result = max(result, height * width);
            start = index;
        }

        stk.push({ start, heights[i] });
    }

    while (!stk.empty()) {
        int width = heights.size() - stk.top().first;
        int height = stk.top().second;
        stk.pop();

        result = max(result, height * width);
    }

    return result;
}
