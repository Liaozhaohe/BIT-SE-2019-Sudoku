#include "Sudoku.h"

Sudoku::Sudoku(const int** data)
{
	this->data = new int* [9];
	for (int i = 0; i < 9; i++)
	{
		this->data[i] = new int[9];
		memset(this->data[i], 0, sizeof(int) * 9);
	}
	if(data != NULL)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				this->data[i][j] = data[i][j];
	}

}

Sudoku::Sudoku(const Sudoku& sudoku)
{
	this->data = new int* [9];
	for (int i = 0; i < 9; i++)
		this->data[i] = new int [9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			this->data[i][j] = sudoku.data[i][j];
}

Sudoku::~Sudoku()
{
	for(int i = 0; i < 9; i++)
	{
		delete[] this->data[i];
	}
	delete[] this->data;
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

void Sudoku::PrintToFile(const std::string & fileName) const
{
	FILE* fp = fopen(fileName.c_str(), "w");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			fprintf(fp, "%d", this->data[i][j]);
		printf("\n");
	}
	fclose(fp);
}


void Sudoku::PrintExpandedSudoku(const std::string& fileName, int maxSudokuPrinted) const
{
	FILE* fp = fopen(fileName.c_str(), "w");
	char row[9][9];
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			row[i][j] += '0' + this->data[i][j];
		}
	}
	int outputOrder[9];
	memset(outputOrder, 0, sizeof(outputOrder));

	int firstBlock[2][3] = { {1,2,3},{1,3,2} };
	int secondBlock[6][3] = { {4,5,6},{4,6,5},{5,4,6},{5,6,4},{6,4,5},{6,5,4} };
	int thirdBlock[6][3] = { {7,8,9},{7,9,8},{8,7,9},{8,9,7},{9,7,8},{9,8,7} };
	for (int firstBlockOrder = 0; firstBlockOrder < 2; firstBlockOrder++)
	{
		for (int secondBlockOrder = 0; secondBlockOrder < 6; secondBlockOrder++)
		{
			for (int thirdBlockOrder = 0; thirdBlockOrder < 6; thirdBlockOrder++)
			{
				maxSudokuPrinted--;
				fprintf(fp, "%s\n", row[firstBlock[firstBlockOrder][1]]);
				fprintf(fp, "%s\n", row[firstBlock[firstBlockOrder][2]]);
				fprintf(fp, "%s\n", row[firstBlock[firstBlockOrder][3]]);
				
				fprintf(fp, "%s\n", row[secondBlock[secondBlockOrder][1]]);
				fprintf(fp, "%s\n", row[secondBlock[secondBlockOrder][2]]);
				fprintf(fp, "%s\n", row[secondBlock[secondBlockOrder][3]]);
				
				fprintf(fp, "%s\n", row[thirdBlock[thirdBlockOrder][1]]);
				fprintf(fp, "%s\n", row[thirdBlock[thirdBlockOrder][2]]);
				fprintf(fp, "%s\n", row[thirdBlock[thirdBlockOrder][3]]);

				if (maxSudokuPrinted == 0)
				{
					fprintf(fp, "\n");
					fclose(fp);
					return;
				}
			}
		}
	}
	fclose(fp);
	return;
}

void Sudoku::SetRow(const int row[9], int row_num)
{
	memcpy(this->data[row_num], row, sizeof(int) * 9);
}


Sudoku& Sudoku::operator=(const Sudoku& sudoku)
{
	this->data = new int* [9];
	for (int i = 0; i < 9; i++)
		this->data[i] = new int[9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			this->data[i][j] = sudoku.data[i][j];
	return (*this);
}

