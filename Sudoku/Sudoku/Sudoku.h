#pragma once
#include "stdafx.h"

class Sudoku
{
	int data[9][9];
public:
	Sudoku(const int data[9][9] = NULL);
	Sudoku(const Sudoku& sudoku);
	~Sudoku();
	void print() const;
	void PrintToFile(FILE* fp) const;
	void PrintExpandedSudoku(FILE* fp, int maxSudokuPrinted) const;
	void SetRow(const int row[9], int row_num);
	void ConstructFromFirstRow();
	Sudoku& operator=(const Sudoku&);
};

