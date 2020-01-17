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
	void PrintToFile(FILE* fp) const;
	void PrintExpandedSudoku(FILE* fp, int maxSudokuPrinted) const;
	void SetRow(const int row[9], int row_num);
	void ConstructFromFirsrRow();
	Sudoku& operator=(const Sudoku&);
};

