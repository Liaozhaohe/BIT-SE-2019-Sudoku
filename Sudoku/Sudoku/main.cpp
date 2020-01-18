#include "SudokuSolver.h"
#include "SudokuGenerator.h"

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("Argument number error. Please check your command.\n");
		printf("Command should have 2 arguments\n");
	}
	if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "-C"))
	{
		SudokuGenerator("./Sudoku.txt", argv[2]).GenerateSudoku();
	}
	else if (!strcmp(argv[1], "-s") || !strcmp(argv[1], "-S"))
	{
		SudokuSolver(argv[2], "./Sudoku.txt").SolveSudoku();
	}
	return 0;
}
