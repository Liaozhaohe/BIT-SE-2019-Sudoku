#include "stdafx.h"
#include "SudokuGenerator.h"

int main()
{
	SudokuGenerator generator("./Sudoku.txt", "1000000");
	generator.GenerateSudoku();
	return 0;
}
