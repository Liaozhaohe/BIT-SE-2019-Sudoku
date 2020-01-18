#include "SudokuSolver.h"
#include "SudokuGenerator.h"

int main()
{
	//SudokuSolver("./Sudoku.txt", "./out.txt").SolveSudoku();
	SudokuGenerator("./Sudoku.txt", "1000000").GenerateSudoku();
	return 0;
}
