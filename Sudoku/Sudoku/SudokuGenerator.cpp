#include "SudokuGenerator.h"

bool SudokuGenerator::ValidateInput(const std::string* parameters)
{
	FILE* fp = fopen(parameters[0].c_str(), "w");
	if (fp == NULL)
		throw std::invalid_argument("Input filename error, check you spelling\n");
	fclose(fp);
	for(int i = 0,len = parameters[1].length(); i < len; i++)
	{
		if (parameters[1][i] > '9' || parameters[1][i] < '0')
		{
			throw std::invalid_argument(" Argument 2 should be an integer!\n");
		}
	}
	fclose(fp);
}

void SudokuGenerator::GenerateBaseSudoku(int num)
{
	int n = 0;
	do
	{
		sudokus[n].SetRow(this->firstRow, 0);
	} while (n < num && std::next_permutation(this->firstRow + 1, this->firstRow + 9));
	
}

void SudokuGenerator::PrintSudoku() const
{
	const int basicSudokuNumber = this->sudokuNum / 72 + 1;
	const int restSudokuNumber = this->sudokuNum % 72;
	for (int i = 0; i < basicSudokuNumber - 1; i++)
	{
		this->sudokus[i].PrintExpandedSudoku(this->outputFile, -1);
	}
	this->sudokus[basicSudokuNumber].PrintExpandedSudoku(this->outputFile, restSudokuNumber);
}

SudokuGenerator::SudokuGenerator(const std::string &outputFile, int sudokuNum)
{
	try
	{
		std::string param[2];
		param[0] = outputFile; param[1] = sudokuNum;
		this->ValidateInput(param);
	}
	catch (std::exception &e)
	{
		std::cout << "Error in constructor of SudokuGenerator: "<<e.what() << std::endl;
	}

	this->outputFile = outputFile;
	this->sudokuNum = sudokuNum / 72 + 1;
	this->sudokus = new Sudoku[this->sudokuNum];

	for (int i = 0; i < 9; i++)
		this->firstRow[i] = i;
}

void SudokuGenerator::GenerateSudoku()
{
	const int basicSudokuNumber = this->sudokuNum / 72 + 1;
	this->GenerateBaseSudoku(basicSudokuNumber);
	this->PrintSudoku();
}

SudokuGenerator::~SudokuGenerator()
{
	delete[] this->sudokus;
}
