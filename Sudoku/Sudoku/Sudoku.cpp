#include "Sudoku.h"

Sudoku::Sudoku(const int** data = NULL)
{
	this->data = new int* [9];
	for (int i = 0; i < 9; i++)
	{
		this->data[i] = new int[9];
		memset(this->data[i], 0, sizeof(int) * 9);
	}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			this->data[i][j] = data[i][j];
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

void Sudoku::PrintToFile(const std::string & fileName)
{
	FILE* fp = fopen(fileName.c_str(), "w");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			fprintf(fp, "%d", this->data[i][j]);
		printf("\n");
	}
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

