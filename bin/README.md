# bin folder

This folder contains release excuteable and the related packages of this project.

Sudoku.exe is the excuteable generate by sorce code in folder **Sudoku/Sudoku**. 

To generate `n` not repeating sodukus, please use:
```
sudoku.exe -c n
```


To solve the sudoku problems in `question_file`, please use:
 To generate `n` not repeating sodukus, please use:
```
sudoku.exe -s question_file
```
In `question_file`, the sudoku problem should be saved in the format described below:

* Each line of the file represents a line in the soduku problem, 
  the empty block is marked as number 0. The numbers are seperated by a space.
* There are **NO** seperate lines between sudoku problems. Each 10 lines are
  recognized as a single sudoku problem.

An example of question file that contains 2 sudoku problem is given below.
```
8 0 0 0 0 0 0 0 0
8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0
0 5 0 0 0 7 0 0 0
0 0 0 0 4 5 7 0 0
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0
0 9 0 0 0 0 4 0 0

8 0 0 0 0 0 0 0 0
8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0
0 5 0 0 0 7 0 0 0
0 0 0 0 4 5 7 0 0
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0
0 9 0 0 0 0 4 0 0
```

The result of generating and solving will be stored in a file called "sudoku.txt"
at the same floder with sudoku.exe.
The solution is saved in the format described below.

* Each line of the file represents a line in the solution soduku.
  Numbers are seperated by a space.
* There are **ONE empty line**  between sudoku solutions.


