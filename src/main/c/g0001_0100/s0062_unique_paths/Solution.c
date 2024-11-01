// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Dynamic_Programming #Math
// #Combinatorics #Algorithm_II_Day_13_Dynamic_Programming #Dynamic_Programming_I_Day_15
// #Level_1_Day_11_Dynamic_Programming #Big_O_Time_O(m*n)_Space_O(m*n)
// #2024_11_01_Time_0_ms_(100.00%)_Space_7.9_MB_(23.82%)

#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n) {
    // Step 1: Allocate a 2D array for dynamic programming
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    // Step 2: Initialize the first column
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    // Step 3: Initialize the first row
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    // Step 4: Fill the rest of the dp array
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // Step 5: Store the result
    int result = dp[m - 1][n - 1];

    // Step 6: Free allocated memory
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}
