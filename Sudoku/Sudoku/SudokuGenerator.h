#pragma once
#include"stdafx.h"
class SudokuGenerator
{
	std::string outputFile;								// Which file to save the Sudoku
	int sudokuNum;										// number of sudoku need to be generated
	Sudoku* sudokus;									// generated Sudoku
	bool ValidateInput(const std::string* parameters);	// validate if input is legal
	void GenerateBaseSudoku(int num);	
	void PrintSudoku() const;
	int firstRow[9]{};
public:
	SudokuGenerator(const std::string& outputFile, int sudokuNum);
	void GenerateSudoku();
	~SudokuGenerator();
};



