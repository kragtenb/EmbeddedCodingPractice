/*
Question 4: Matrix Transposition
Description:

Implement a function that transposes a given N x M matrix.
Key Concepts:

2D arrays in C.
Pointer arithmetic.
Memory allocation (for dynamically sized matrices).
*/
#include <stdlib.h>
#include <stdio.h>

void transpose(int **matrix, int rows, int cols, int **result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void print(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int** matrix, int rows) {
    for (int i=0; i<rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n = 5;
    int m = 5;
    int** matrix = (int**) malloc(n*sizeof(int*));
    for (int i=0; i<n; i++) {
        matrix[i] = (int*) malloc(m*sizeof(int));
    }
    int** result = (int**) malloc(m*sizeof(int*));
    for (int i=0; i<m; i++) {
        result[i] = (int*) malloc(n*sizeof(int));
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = i*m + j;
        }
    }

    transpose(matrix, n, m, result);
    print(matrix, n, m);
    print(result, m, n);

    freeMatrix(matrix, n);
    freeMatrix(result, m);

    return 0;
}