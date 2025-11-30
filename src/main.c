#include <stdio.h>
#include <time.h>
#include "sudoku.h"

// Initial Puzzle
int puzzle[9][9] = {
    {3,0,0,0,2,0,0,7,0},
    {9,0,0,5,0,0,0,1,4},
    {0,1,6,3,7,0,0,0,8},
    {2,0,0,8,0,0,0,0,1},
    {5,0,0,0,4,1,8,0,0},
    {0,8,9,0,0,0,0,5,0},
    {0,0,5,0,1,0,2,8,0},
    {0,4,0,0,0,6,0,9,3},
    {7,3,1,0,8,2,0,0,0}
};

int fixed[9][9];

int main() {
    char name[50], college[100], sap[20];
    int row, col, val;

    // Copy fixed cells
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            fixed[i][j] = puzzle[i][j];

    printf("\nEnter your Name: ");
    scanf(" %[^\n]", name);

    printf("Enter your SAP ID: ");
    scanf(" %[^\n]", sap);

    printf("Enter your College Name: ");
    scanf(" %[^\n]", college);

    printf("\n\tWELCOME TO INTERACTIVE SUDOKU GAME!");
    printf("\nFill all empty cells correctly.\n");

    time_t start, end;
    time(&start);

    while (1) {
        print_puzzle(puzzle);

        if (is_completed(puzzle) && is_correct(puzzle)) {
            time(&end);
            double time_taken = difftime(end, start);

            printf("\n🎉 Congratulations %s! You completed the Sudoku!\n", name);
            printf("-----------------------------------------------------------\n");
            printf("           🎓 SUDOKU COMPLETION CERTIFICATE 🎓\n");
            printf("-----------------------------------------------------------\n");
            printf("Player Name    : %s\n", name);
            printf("SAP ID         : %s\n", sap);
            printf("College        : %s\n", college);
            printf("Time Taken     : %.2f seconds\n", time_taken);
            printf("Status         : Successfully Completed!\n");
            printf("-----------------------------------------------------------\n");
            break;
        }

        printf("\nEnter your move (row col value) [1-9] or -1 to exit: ");
        scanf("%d", &row);

        if (row == -1) {
            printf("\nGame exited.\n");
            break;
        }

        scanf("%d %d", &col, &val);

        // Convert to 0–8 indexing
        row--;
        col--;

        if (row < 0 || row > 8 || col < 0 || col > 8 || val < 1 || val > 9) {
            printf("\n❌ Invalid input! Try again.\n");
            continue;
        }

        if (fixed[row][col] != 0) {
            printf("\n❌ That cell is fixed and cannot be changed.\n");
            continue;
        }

        if (valid_move(puzzle, row, col, val)) {
            puzzle[row][col] = val;
            printf("\n✔ Move accepted!\n");
        } else {
            printf("\n❌ Wrong move! That value is not allowed there.\n");
        }
    }

    return 0;
}
