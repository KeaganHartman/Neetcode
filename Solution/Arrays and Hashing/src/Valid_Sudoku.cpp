#include "Valid_Sudoku.h"

Valid_Sudoku::Valid_Sudoku()
{
    vector<vector<char>> input = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '6'}
        ,   {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
        ,   {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
        ,   {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
        ,   {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
        ,   {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
        ,   {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
        ,   {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
        ,   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << isValidSudoku(input);
}

bool Valid_Sudoku::isValidSudoku(vector<vector<char>>& board)
{
    // Maps to Check (27 total maps)
    vector<map<char, int>> box_mps;
    vector<map<char, int>> row_mps;
    vector<map<char, int>> col_mps;
    box_mps.resize(9);
    col_mps.resize(9);
    row_mps.resize(9);

    // Loop Through Entire Sudoku Board to check Validity
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            char curr_square = board[y][x];
            if (curr_square == '.')
                continue;

            // row_mp
            if (row_mps[x].find(curr_square) == row_mps[x].end())
                ++row_mps[x][curr_square];
            else
                return false;
            // col_mp
            if (col_mps[y].find(curr_square) == col_mps[y].end())
                ++col_mps[y][curr_square];
            else
                return false;
            // box_mp
            int mpIndex = (x / 3) + ((y / 3) * 3);
            if (box_mps[mpIndex].find(curr_square) == box_mps[mpIndex].end())
                ++box_mps[mpIndex][curr_square];
            else
                return false;
        }
    }

    return true;
}