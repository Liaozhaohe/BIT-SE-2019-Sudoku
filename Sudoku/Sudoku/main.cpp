#include "stdafx.h"
#include "SudokuGenerator.h"
#include "SudokuSolver.h"

int main()
{
	//SudokuSolver("./Sudoku.txt", "./out.txt").SolveSudoku();
	SudokuGenerator("./Sudoku.txt", "1000000").GenerateSudoku();
	return 0;
}
