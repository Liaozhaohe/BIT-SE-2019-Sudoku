#pragma once
#include "stdafx.h"

class Sudoku
{
	int** data;
public:
	Sudoku(const int** data);
	Sudoku(const Sudoku& sudoku);
	~Sudoku();
	void print() const;
	void PrintToFile(const std::string& fileName);
	Sudoku& operator=(const Sudoku&);
};

