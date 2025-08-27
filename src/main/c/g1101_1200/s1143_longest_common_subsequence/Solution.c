// #Medium #Top_100_Liked_Questions #String #Dynamic_Programming #LeetCode_75_DP/Multidimensional
// #Algorithm_II_Day_17_Dynamic_Programming #Dynamic_Programming_I_Day_19
// #Udemy_Dynamic_Programming #Big_O_Time_O(n*m)_Space_O(n*m)
// #2024_11_08_Time_21_ms_(84.72%)_Space_12.2_MB_(58.02%)

#include <stdio.h>
#include <string.h>

int longestCommonSubsequence(char* text1, char* text2) {
    int n = strlen(text1);
    int m = strlen(text2);
    
    // Create a 2D array to store the lengths of longest common subsequences
    int dp[n + 1][m + 1];

    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;  // Initialize all values to 0
        }
    }

    // Fill the dp array using bottom-up dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    // The length of the longest common subsequence is stored in dp[n][m]
    return dp[n][m];
}
