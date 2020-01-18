#include "SudokuGenerator.h"

void SudokuGenerator::ValidateInput(const std::string* parameters)
{
	int res;
	if ((res = fopen_s(&this->outputFile, parameters[0].c_str(), "w")) != 0)
	{
		printf("Error: %d\n", res);
		throw std::invalid_argument("Input filename error, check you spelling\n");
	}
	for (int i = 0, len = (int)parameters[1].length(); i < len; i++)
	{
		if (parameters[1][i] > '9' || parameters[1][i] < '0')
		{
			fclose(this->outputFile);
			throw std::invalid_argument(" Argument 2 should be an positive integer!\n");
		}
		if (len == 1 && parameters[1][0] == '0')
		{
			fclose(this->outputFile);
			throw std::invalid_argument(" Argument 2 should not be 0!\n");
		}
	}
}

void SudokuGenerator::GenerateBaseSudoku(int num)
{
	int n = 0;
	do
	{
		sudoku[n].SetRow(this->firstRow, 0);
		sudoku[n].ConstructFromFirstRow();
		n++;
	} while (n < num && std::next_permutation(this->firstRow + 1, this->firstRow + 9));
	
}

void SudokuGenerator::PrintSudoku() const
{
	const int basicSudokuNumber = this->sudokuNum / 72 + 1;
	const int restSudokuNumber = this->sudokuNum % 72;
	for (int i = 0; i < basicSudokuNumber - 1; i++)
	{
		this->sudoku[i].PrintExpandedSudoku(this->outputFile, -1);
	}
	this->sudoku[basicSudokuNumber-1].PrintExpandedSudoku(this->outputFile, restSudokuNumber);
}

SudokuGenerator::SudokuGenerator(const std::string &outputFile, const std::string& sudokuNum)
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
		throw std::invalid_argument(e.what());
	}
	
	this->sudokuNum = 0;
	for (auto ch = sudokuNum.begin(); ch != sudokuNum.end(); ++ch)
	{
		this->sudokuNum *= 10;
		this->sudokuNum += (*ch) - '0';
	}
	this->sudoku = new Sudoku[this->sudokuNum / 72 + 1];

	firstRow[0] = 3;
	firstRow[1] = 1;
	firstRow[2] = 2;
	for (int i = 3; i < 9; i++)
		this->firstRow[i] = i + 1;
}

void SudokuGenerator::GenerateSudoku()
{
	const int basicSudokuNumber = this->sudokuNum / 72 + 1;
	this->GenerateBaseSudoku(basicSudokuNumber);
	this->PrintSudoku();
}

SudokuGenerator::~SudokuGenerator()
{
	delete[] this->sudoku;
	fclose(this->outputFile);
}
