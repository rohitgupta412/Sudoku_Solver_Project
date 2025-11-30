#include <stdio.h>
#include "sudoku.h"

// Print Sudoku Grid
void print_puzzle(int puzzle[9][9]) {
    printf("\n+-------+-------+-------+");
    for (int row = 0; row < 9; row++) {
        if (row % 3 == 0 && row != 0)
            printf("\n|-------+-------+-------|");

        printf("\n");
        for (int col = 0; col < 9; col++) {
            if (col % 3 == 0) printf("| ");

            if (puzzle[row][col] != 0)
                printf("%d ", puzzle[row][col]);
            else
                printf(". ");
        }
        printf("|");
    }
    printf("\n+-------+-------+-------+\n");
}

// Check Valid Move
int valid_move(int puzzle[9][9], int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == val) return 0;
        if (puzzle[i][col] == val) return 0;
    }

    int r = row - row % 3;
    int c = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (puzzle[r+i][c+j] == val)
                return 0;

    return 1;
}

// Check If Puzzle Is Filled
int is_completed(int puzzle[9][9]) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (puzzle[i][j] == 0)
                return 0;
    return 1;
}

// Check If Final Solution Is Correct
int is_correct(int puzzle[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            int val = puzzle[row][col];
            if (val == 0) return 0;

            puzzle[row][col] = 0;
            if (!valid_move(puzzle, row, col, val)) {
                puzzle[row][col] = val;
                return 0;
            }
            puzzle[row][col] = val;
        }
    }
    return 1;
}
