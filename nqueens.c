#include <stdio.h>
#include <stdbool.h>

#define N 10 // Maximum value of N

// Function to print the chessboard
void printSolution(int board[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

// Function to check if a queen can be placed in the current position
bool isSafe(int board[N][N], int row, int col, int n) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Function to solve the N Queens problem recursively
bool solveNQueensUtil(int board[N][N], int col, int n) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1, n))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

// Function to solve the N Queens problem
bool solveNQueens(int n) {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0, n)) {
        printf("Solution does not exist\n");
        return false;
    }

    printf("Solution exists. Placements of queens:\n");
    printSolution(board, n);
    return true;
}

int main() {
    int n;
    printf("Enter the value of N for N Queens problem: ");
    scanf("%d", &n);

    solveNQueens(n);

    return 0;
}
