#pragma once
#include "stdafx.h"

class SudokuSolver
{
	FILE* outputFile;
	FILE* inputFile;
	void ValidateInput(const std::string* parameters);

	bool constraint[3][9][9];
	bool isEmpty[9][9];
	int sudoku[9][9];
	bool found;

	inline int blockId(int x, int y);
	int nextVal(int x, int y, int start);
	void updateConstraint(int x, int y, bool startTracing);
	void backtracing(int x, int y);
public:
	SudokuSolver(const std::string& inputFile, const std::string& outputFile);
	void SolveSudoku();
	~SudokuSolver();
};


