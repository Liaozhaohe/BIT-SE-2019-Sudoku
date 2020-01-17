#include "Sudoku.h"

Sudoku::Sudoku(const int data[9][9])
{
	if(data != NULL)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				this->data[i][j] = data[i][j];
	}
}

Sudoku::Sudoku(const Sudoku& sudoku)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			this->data[i][j] = sudoku.data[i][j];
}

Sudoku::~Sudoku()
{
}

void Sudoku::print() const
{
	for(int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%d", this->data[i][j]);
		printf("\n");
	}
}

void Sudoku::PrintToFile(FILE* fp) const
{
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			fprintf(fp, "%d", this->data[i][j]);
		printf("\n");
	}
}


void Sudoku::PrintExpandedSudoku(FILE* fp, int maxSudokuPrinted) const
{
	char row[9][10];
	memset(row, 0, sizeof(row));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			row[i][j] += '0' + this->data[i][j];
		}
	}
	int outputOrder[9];
	memset(outputOrder, 0, sizeof(outputOrder));

	int firstBlock[2][3] = { {0,1,2},{0,2,1} };
	int secondBlock[6][3] = { {3,4,5},{3,5,4},{4,3,5},{4,5,3},{5,3,4},{5,4,3} };
	int thirdBlock[6][3] = { {6,7,8},{6,8,7},{7,6,8},{7,8,6},{8,6,7},{8,7,6} };
	for (int firstBlockOrder = 0; firstBlockOrder < 2; firstBlockOrder++)
	{
		for (int secondBlockOrder = 0; secondBlockOrder < 6; secondBlockOrder++)
		{
			for (int thirdBlockOrder = 0; thirdBlockOrder < 6; thirdBlockOrder++)
			{
				maxSudokuPrinted--;
				fprintf(fp, "%s\n", row[firstBlock[firstBlockOrder][0]]);
				fprintf(fp, "%s\n", row[firstBlock[firstBlockOrder][1]]);
				fprintf(fp, "%s\n", row[firstBlock[firstBlockOrder][2]]);
				
				fprintf(fp, "%s\n", row[secondBlock[secondBlockOrder][0]]);
				fprintf(fp, "%s\n", row[secondBlock[secondBlockOrder][1]]);
				fprintf(fp, "%s\n", row[secondBlock[secondBlockOrder][2]]);
				
				fprintf(fp, "%s\n", row[thirdBlock[thirdBlockOrder][0]]);
				fprintf(fp, "%s\n", row[thirdBlock[thirdBlockOrder][1]]);
				fprintf(fp, "%s\n", row[thirdBlock[thirdBlockOrder][2]]);

				if (maxSudokuPrinted != 0)
				{
					fprintf(fp, "\n");
				}
				else
				{
					return;
				}
			}
		}
	}
}

void Sudoku::SetRow(const int row[9], int row_num)
{
	memcpy(this->data[row_num], row, sizeof(int) * 9);
}

void Sudoku::ConstructFromFirstRow()
{
	int f[10] = { 0,3,6,1,4,7,2,5,8 };
	for(int i = 1; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			this->data[i][j] = data[0][(j - f[i] + 9) % 9];
		}
	}
}


Sudoku& Sudoku::operator=(const Sudoku& sudoku)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			this->data[i][j] = sudoku.data[i][j];
	return (*this);
}

