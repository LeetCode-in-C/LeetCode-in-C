// #Medium #Top_100_Liked_Questions #String #Dynamic_Programming
// #Algorithm_II_Day_18_Dynamic_Programming #Dynamic_Programming_I_Day_19
// #Udemy_Dynamic_Programming #Big_O_Time_O(n^2)_Space_O(n2)
// #2024_11_01_Time_0_ms_(100.00%)_Space_8.4_MB_(97.63%)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minDistance(char* w1, char* w2) {
    int n1 = strlen(w1);
    int n2 = strlen(w2);
    
    // Ensure w1 is the longer string
    if (n2 > n1) {
        return minDistance(w2, w1);
    }
    
    // Create a DP array to store the distances
    int* dp = (int*)malloc((n2 + 1) * sizeof(int));
    
    // Initialize the DP array
    for (int j = 0; j <= n2; j++) {
        dp[j] = j;
    }

    // Fill the DP table
    for (int i = 1; i <= n1; i++) {
        int pre = dp[0];
        dp[0] = i; // First column represents distance to w1
        for (int j = 1; j <= n2; j++) {
            int tmp = dp[j];
            dp[j] = (w1[i - 1] != w2[j - 1]) 
                ? 1 + (pre < dp[j] ? (pre < dp[j - 1] ? pre : dp[j - 1]) : (dp[j] < dp[j - 1] ? dp[j] : dp[j - 1]))
                : pre;
            pre = tmp; // Store the previous value
        }
    }

    int result = dp[n2];

    // Free allocated memory
    free(dp);

    return result;
}
