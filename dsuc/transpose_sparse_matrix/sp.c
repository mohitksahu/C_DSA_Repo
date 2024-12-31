#include <stdio.h>

void createSparseMatrix(int rows, int cols, int mat[rows][cols], int *size, int sparse[rows * cols][3]) {
    *size = 0;
    // Loop through the matrix to find non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[*size][0] = i;      // Row index
                sparse[*size][1] = j;      // Column index
                sparse[*size][2] = mat[i][j]; // Value
                (*size)++;
            }
        }
    }
}

void transposeSparseMatrix(int rows, int cols, int sparse[rows * cols][3], int size, int transposed[rows * cols][3]) {
    int k = 0;
    // Swap row and column indices for each non-zero element
    for (int i = 0; i < size; i++) {
        transposed[k][0] = sparse[i][1];  // Swap rows and columns
        transposed[k][1] = sparse[i][0];  // Swap rows and columns
        transposed[k][2] = sparse[i][2];  // Value remains the same
        k++;
    }
}

void displaySparseMatrix(int sparse[10][3], int size) {
    printf("Row Column Value\n");
    for (int i = 0; i < size; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int mat[3][3] = {
        {0, 0, 3},
        {0, 0, 0},
        {0, 4, 0}
    };

    int rows = 3, cols = 3;
    int sparse[rows * cols][3];  // To store non-zero elements in sparse format
    int transposed[rows * cols][3]; // To store the transposed sparse matrix
    int size = 0;

    // Create sparse matrix
    createSparseMatrix(rows, cols, mat, &size, sparse);

    printf("Original Sparse Matrix:\n");
    displaySparseMatrix(sparse, size);

    // Transpose sparse matrix
    transposeSparseMatrix(rows, cols, sparse, size, transposed);

    printf("\nTransposed Sparse Matrix:\n");
    displaySparseMatrix(transposed, size);

    return 0;
}
