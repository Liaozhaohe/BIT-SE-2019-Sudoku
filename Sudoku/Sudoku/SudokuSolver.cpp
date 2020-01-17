#include "SudokuSolver.h"
#include "Sudoku.h"

void SudokuSolver::ValidateInput(const std::string* parameters)
{
	fopen_s(&this->inputFile, parameters[0].c_str(), "r");
	if (this->inputFile == NULL) 
		throw std::invalid_argument("Error: Please check the input file name");
	fopen_s(&this->outputFile, parameters[1].c_str(), "a+");
	if (this->inputFile == NULL) 
		throw std::invalid_argument("Error: Please check the output file name");
}

SudokuSolver::SudokuSolver(const std::string& inputFile, const std::string& outputFile)
{
	std::string params[2] = { inputFile, outputFile };
	this->inputFile = NULL;
	this->outputFile = NULL;
	this->ValidateInput(params);
	memset(this->isEmpty, 0,sizeof(isEmpty));
	memset(this->sudoku ,0,sizeof(this->sudoku));
	memset(this->constraint, 0, sizeof(this->constraint));
}

void SudokuSolver::SolveSudoku()
{
	bool firstSolution = true;
	bool lastSolution = false;
	while (true)
	{
		char cdata[9][20];
		memset(cdata, 0, sizeof(cdata));
		memset(this->isEmpty, 0, sizeof(isEmpty));
		memset(this->sudoku, 0, sizeof(this->sudoku));
		memset(this->constraint, 0, sizeof(this->constraint));
		for(int i = 0; i < 9; i++)
		{
			int res = fread_s(cdata[i], (size_t)20, sizeof(char), (size_t)18, this->inputFile);
			if (res == 0)
			{
				lastSolution = true;
				break;
			}
		}
		if (lastSolution)
			break;
		if (!firstSolution)
			fprintf(this->outputFile, "\n\n");
		else
			firstSolution = false;
		found = false;
		
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				sudoku[i][j] = cdata[i][j<<1] - '0' - 1;
				isEmpty[i][j] = (sudoku[i][j] == -1);
				if (!isEmpty[i][j]) updateConstraint(i, j, 1);
			}
		this->backtracing(0, 0);
		fread_s(cdata, 20, sizeof(char), 1, this->inputFile);
	}

}

SudokuSolver::~SudokuSolver()
{
	fclose(this->outputFile);
	fclose(this->inputFile);
}

inline int SudokuSolver::blockId(int x, int y)
{
	return (3 * (x / 3) + (y / 3));
}

int SudokuSolver::nextVal(int x, int y, int start)
{
	int block = blockId(x, y);
	for (int i = start; i < 9; i++)
	{
		if (constraint[0][x][i]) continue;
		if (constraint[1][y][i]) continue;
		if (constraint[2][block][i]) continue;
		return i;
	}
	return -1;
}

void SudokuSolver::updateConstraint(int x, int y, bool startTracing)
{
	const int block = blockId(x, y);
	const int value = sudoku[x][y];
	constraint[0][x][value] = startTracing;
	constraint[1][y][value] = startTracing;
	constraint[2][block][value] = startTracing;
}


void SudokuSolver::backtracing(int x, int y)
{
	if (found)
		return;
	if (y == 9)
	{
		x++;
		y = 0;
	}
	while (x <= 8 && !isEmpty[x][y])
	{
		y++;
		if (y == 9)
		{
			x++;
			y = 0;
		}
	}
	if (x > 8)
	{
		found = true;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				sudoku[i][j]++;
		Sudoku(sudoku).PrintToFile(this->outputFile);
		return;
	}
	while (~(sudoku[x][y] = nextVal(x, y, sudoku[x][y] + 1)))
	{
		updateConstraint(x, y, true);
		backtracing(x, y + 1);
		updateConstraint(x, y, false);
	}
}


