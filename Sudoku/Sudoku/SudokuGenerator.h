#pragma once
#include "stdafx.h"
#include "Sudoku.h"

class SudokuGenerator
{
	FILE* outputFile;					    			// Which file to save the Sudoku
	int sudokuNum;										// number of sudoku need to be generated
	Sudoku *sudoku;									    // generated Sudoku
	void ValidateInput(const std::string* parameters);	// validate if input is legal
	void GenerateBaseSudoku(int num);	
	void PrintSudoku() const;
	int firstRow[9]{};
public:
	SudokuGenerator(const std::string& outputFile, const std::string& sudokuNum);
	void GenerateSudoku();
	~SudokuGenerator();
};



