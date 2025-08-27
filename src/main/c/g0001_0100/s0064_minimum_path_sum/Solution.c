// #Medium #Top_100_Liked_Questions #Array #Dynamic_Programming #Matrix
// #Dynamic_Programming_I_Day_16 #Udemy_Dynamic_Programming #Top_Interview_150_Multidimensional_DP
// #Big_O_Time_O(m*n)_Space_O(m*n) #2024_11_01_Time_0_ms_(100.00%)_Space_11.1_MB_(9.24%)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int recur(int** grid, int** dm, int r, int c, int rows, int cols) {
    if (dm[r][c] == 0 && r != rows - 1 && c != cols - 1) {
        dm[r][c] = grid[r][c] + (recur(grid, dm, r + 1, c, rows, cols) < recur(grid, dm, r, c + 1, rows, cols) 
                                 ? recur(grid, dm, r + 1, c, rows, cols) 
                                 : recur(grid, dm, r, c + 1, rows, cols));
    }
    return dm[r][c];
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    if (gridSize == 1 && gridColSize[0] == 1) {
        return grid[0][0];
    }

    int rows = gridSize;
    int cols = gridColSize[0];
    int** dm = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dm[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            dm[i][j] = 0; // Initialize to 0
        }
    }

    int s = 0;
    for (int r = rows - 1; r >= 0; r--) {
        dm[r][cols - 1] = grid[r][cols - 1] + s;
        s += grid[r][cols - 1];
    }

    s = 0;
    for (int c = cols - 1; c >= 0; c--) {
        dm[rows - 1][c] = grid[rows - 1][c] + s;
        s += grid[rows - 1][c];
    }

    int result = recur(grid, dm, 0, 0, rows, cols);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(dm[i]);
    }
    free(dm);

    return result;
}
