#ifndef SUDOKU_H
#define SUDOKU_H

#include <time.h>

// Function Declarations
void print_puzzle(int puzzle[9][9]);
int valid_move(int puzzle[9][9], int row, int col, int val);
int is_completed(int puzzle[9][9]);
int is_correct(int puzzle[9][9]);

#endif
