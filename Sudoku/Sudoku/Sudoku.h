#pragma once
#include "stdafx.h"

class Sudoku
{
	int** data;
public:
	Sudoku(const int** data = NULL);
	Sudoku(const Sudoku& sudoku);
	~Sudoku();
	void print() const;
	void PrintToFile(const std::string& fileName) const;
	void PrintExpandedSudoku(const std::string& fileName, int maxSudokuPrinted) const;
	void SetRow(const int row[9], int row_num);
	Sudoku& operator=(const Sudoku&);
};

