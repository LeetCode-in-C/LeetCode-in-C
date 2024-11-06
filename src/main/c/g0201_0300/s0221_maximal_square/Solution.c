// #Medium #Array #Dynamic_Programming #Matrix #Dynamic_Programming_I_Day_16
// #Big_O_Time_O(m*n)_Space_O(m*n) #2024_11_06_Time_0_ms_(100.00%)_Space_16.6_MB_(8.16%)

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int min3(int a, int b, int c) {
    return min(a, min(b, c));
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }
    
    int m = matrixSize;
    int n = matrixColSize[0];
    
    // Create a dynamic programming (dp) array initialized to 0
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)calloc(n + 1, sizeof(int));
    }
    
    int max = 0;
    
    // Fill the dp array based on the matrix values
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
                if (dp[i][j] > max) {
                    max = dp[i][j];
                }
            }
        }
    }
    
    // Free allocated memory for dp array
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return max * max;
}
