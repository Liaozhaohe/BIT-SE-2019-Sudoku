#include "SudokuSolver.h"
#include "Sudoku.h"

void SudokuSolver::ValidateInput(const std::string* parameters)
{
	fopen_s(&this->inputFile, parameters[0].c_str(), "r");
	if (this->inputFile == NULL) 
		throw std::invalid_argument("Error: Please check the input file name");
	fopen_s(&this->outputFile, parameters[1].c_str(), "w");
	if (this->inputFile == NULL) 
		throw std::invalid_argument("Error: Please check the output file name");
}

SudokuSolver::SudokuSolver(const std::string& inputFile, const std::string& outputFile)
{
	std::string params[2] = { inputFile, outputFile };
	this->inputFile = NULL;
	this->outputFile = NULL;
	try
	{
		this->ValidateInput(params);
	}
	catch (std::exception e)
	{
		std::cout << "Error in constructor of SudokuGenerator: " << e.what() << std::endl;
		exit(-1);
	}
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
			const size_t res = fread_s(cdata[i], (size_t)20, sizeof(char), (size_t)18, this->inputFile);
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

inline int SudokuSolver::nextVal(int x, int y, int start)
{
	int block = blockId(x, y);
	if (start <= 0 && !constraint[0][x][0]&&!constraint[1][y][0]&&!constraint[2][block][0])
		return 0;
	if (start <= 1 && !constraint[0][x][1]&&!constraint[1][y][1]&&!constraint[2][block][1])
		return 1;
	if (start <= 2 && !constraint[0][x][2]&&!constraint[1][y][2]&&!constraint[2][block][2])
		return 2;
	if (start <= 3 && !constraint[0][x][3]&&!constraint[1][y][3]&&!constraint[2][block][3])
		return 3;
	if (start <= 4 && !constraint[0][x][4]&&!constraint[1][y][4]&&!constraint[2][block][4])
		return 4;
	if (start <= 5 && !constraint[0][x][5]&&!constraint[1][y][5]&&!constraint[2][block][5])
		return 5;
	if (start <= 6 && !constraint[0][x][6]&&!constraint[1][y][6]&&!constraint[2][block][6])
		return 6;
	if (start <= 7 && !constraint[0][x][7]&&!constraint[1][y][7]&&!constraint[2][block][7])
		return 7;
	if (start <= 8 && !constraint[0][x][8]&&!constraint[1][y][8]&&!constraint[2][block][8])
		return 8;
	return -1;
}

inline void SudokuSolver::updateConstraint(int x, int y, bool startTracing)
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


