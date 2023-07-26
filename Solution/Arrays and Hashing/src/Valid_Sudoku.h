#pragma once
#include "includes.h"
class Valid_Sudoku
{
public:
	Valid_Sudoku();
private:
	/*Determine if a (9x9) Sudoku board is valid. Only the filled in cells need to be validated according to the
	rules of Sudoku.
	Rows 1-9
	Columns 1-9
	3x3 Boxes 1-9*/
	bool isValidSudoku(vector<vector<char>>& board);
};

