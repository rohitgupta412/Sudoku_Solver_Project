#include <stdio.h>
#include <time.h>

int puzzle[9][9] = {
    {3,0,0,0,2,0,0,7,0},
    {9,0,0,5,0,0,0,1,4},
    {0,1,6,3,7,0,0,0,8},
    {2,0,0,8,0,0,0,0,1},
    {5,0,0,0,4,1,8,0,0},
    {0,8,9,0,0,0,0,5,0},
    {0,0,5,0,1,0,2,8,0},
    {0,4,0,0,0,6,0,9,3},
    {7,3,1,0,8,2,0,0,0},
};

void print_puzzle(int puzzle[9][9]);
int valid_move(int puzzle[9][9], int row, int col, int val);
int is_completed(int puzzle[9][9]);

int main() {
    char name[50], college[100], sap[20];

    printf("\nEnter your Name: ");
    scanf(" %[^\n]", name);

    printf("Enter your SAP ID: ");
    scanf(" %[^\n]", sap);

    printf("Enter your College Name: ");
    scanf(" %[^\n]", college);

    printf("\n\tWELCOME TO INTERACTIVE SUDOKU GAME!");
    printf("\nFill all empty cells correctly.\n");

    int row, col, val;

    // START TIME
    time_t start, end;
    time(&start);

    while (1) {
        print_puzzle(puzzle);

        if (is_completed(puzzle)) {
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

        printf("\nEnter your move (row col value) or -1 to exit: ");
        scanf("%d", &row);

        if (row == -1) {
            printf("\nGame exited.\n");
            break;
        }

        scanf("%d %d", &col, &val);

        if (row < 0 || row > 8 || col < 0 || col > 8 || val < 1 || val > 9) {
            printf("\n❌ Invalid input! Try again.\n");
            continue;
        }

        if (puzzle[row][col] != 0) {
            printf("\n❌ That cell is already filled.\n");
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

int valid_move(int puzzle[9][9], int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == val) return 0;
        if (puzzle[i][col] == val) return 0;
    }

    int r = row - row % 3;
    int c = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (puzzle[r+i][c+j] == val) return 0;

    return 1;
}

int is_completed(int puzzle[9][9]) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (puzzle[i][j] == 0) return 0;
    return 1;
}

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