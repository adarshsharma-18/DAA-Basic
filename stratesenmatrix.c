#include <stdio.h>

// Function to split a matrix into four submatrices
void splitMatrix(int A[][100], int A11[][100], int A12[][100], int A21[][100], int A22[][100], int n) {
    int i, j;
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n / 2];
            A21[i][j] = A[i + n / 2][j];
            A22[i][j] = A[i + n / 2][j + n / 2];
        }
    }
}

// Function to add two matrices
void addMatrices(int A[][100], int B[][100], int C[][100], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int A[][100], int B[][100], int C[][100], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices using Strassen's algorithm
void strassenMatrixMultiplication(int A[][100], int B[][100], int C[][100], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int A11[100][100], A12[100][100], A21[100][100], A22[100][100];
    int B11[100][100], B12[100][100], B21[100][100], B22[100][100];
    int M1[100][100], M2[100][100], M3[100][100], M4[100][100], M5[100][100], M6[100][100], M7[100][100];
    int C11[100][100], C12[100][100], C21[100][100], C22[100][100];
    int temp1[100][100], temp2[100][100];
    int i, j;

    splitMatrix(A, A11, A12, A21, A22, n);
    splitMatrix(B, B11, B12, B21, B22, n);

    // Calculate M1, M2, ..., M7
    addMatrices(A11, A22, temp1, n / 2);
    addMatrices(B11, B22, temp2, n / 2);
    strassenMatrixMultiplication(temp1, temp2, M1, n / 2);

    addMatrices(A21, A22, temp1, n / 2);
    strassenMatrixMultiplication(temp1, B11, M2, n / 2);

    subtractMatrices(B12, B22, temp1, n / 2);
    strassenMatrixMultiplication(A11, temp1, M3, n / 2);

    subtractMatrices(B21, B11, temp1, n / 2);
    strassenMatrixMultiplication(A22, temp1, M4, n / 2);

    addMatrices(A11, A12, temp1, n / 2);
    strassenMatrixMultiplication(temp1, B22, M5, n / 2);

    subtractMatrices(A21, A11, temp1, n / 2);
    addMatrices(B11, B12, temp2, n / 2);
    strassenMatrixMultiplication(temp1, temp2, M6, n / 2);

    subtractMatrices(A12, A22, temp1, n / 2);
    addMatrices(B21, B22, temp2, n / 2);
    strassenMatrixMultiplication(temp1, temp2, M7, n / 2);

    // Calculate C11, C12, C21, C22
    addMatrices(M1, M4, temp1, n / 2);
    subtractMatrices(temp1, M5, temp2, n / 2);
    addMatrices(temp2, M7, C11, n / 2);

    addMatrices(M3, M5, C12, n / 2);

    addMatrices(M2, M4, C21, n / 2);

    addMatrices(M1, M3, temp1, n / 2);
    subtractMatrices(temp1, M2, temp2, n / 2);
    addMatrices(temp2, M6, C22, n / 2);

    // Combine C11, C12, C21, C22 into result matrix C
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            C[i][j] = C11[i][j];
            C[i][j + n / 2] = C12[i][j];
            C[i + n / 2][j] = C21[i][j];
            C[i + n / 2][j + n / 2] = C22[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int A[][100], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    int A[100][100], B[100][100], C[100][100];

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassenMatrixMultiplication(A, B, C, n);

    printf("Resultant matrix C:\n");
    displayMatrix(C, n);

    return 0;
}
