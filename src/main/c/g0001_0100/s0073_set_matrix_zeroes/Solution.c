// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table #Matrix
// #Udemy_2D_Arrays/Matrix #Big_O_Time_O(m*n)_Space_O(1)
// #2024_11_01_Time_0_ms_(100.00%)_Space_16.5_MB_(12.48%)

#include <stdio.h>
#include <stdlib.h>

void setZeroRow(int **matrix, int cols, int row) {
    for (int j = 0; j < cols; j++) {
        matrix[row][j] = 0;
    }
}

void setZeroCol(int **matrix, int rows, int col) {
    for (int i = 0; i < rows; i++) {
        matrix[i][col] = 0;
    }
}

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int setFirstRow = 0, setFirstCol = 0;

    // Step 1: Determine which rows and columns to zero out
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;  // Mark the first column
                matrix[0][j] = 0;  // Mark the first row

                if (i == 0) setFirstRow = 1;  // Indicate first row needs to be zeroed
                if (j == 0) setFirstCol = 1;  // Indicate first column needs to be zeroed
            }
        }
    }

    // Step 2: Zero out cells based on marks in the first row and column
    for (int i = matrixSize - 1; i > 0; i--) {
        if (matrix[i][0] == 0) {
            setZeroRow(matrix, *matrixColSize, i);
        }
    }

    for (int j = *matrixColSize - 1; j > 0; j--) {
        if (matrix[0][j] == 0) {
            setZeroCol(matrix, matrixSize, j);
        }
    }

    // Step 3: Zero out the first row and column if needed
    if (setFirstRow) {
        setZeroRow(matrix, *matrixColSize, 0);
    }
    if (setFirstCol) {
        setZeroCol(matrix, matrixSize, 0);
    }
}
