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
		try
		{
			SudokuGenerator("./sudoku.txt", argv[2]).GenerateSudoku();
		}
		catch (std::exception &e)
		{
			std::cout << "Main receives error in SudokuGenerator: " << e.what() << std::endl;
			exit(-1);
		}

	}
	else if (!strcmp(argv[1], "-s") || !strcmp(argv[1], "-S"))
	{
		try
		{
			SudokuSolver(argv[2], "./sudoku.txt").SolveSudoku();
		}
		catch (std::exception &e)
		{
			std::cout << "Main receives error in SudokuGenerator: " << e.what() << std::endl;
			exit(-1);
		}
	}
	
	return 0;
}
