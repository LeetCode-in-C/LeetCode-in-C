// #Medium #Top_100_Liked_Questions #Array #Dynamic_Programming #Breadth_First_Search
// #Algorithm_II_Day_18_Dynamic_Programming #Dynamic_Programming_I_Day_20
// #Level_2_Day_12_Dynamic_Programming #Top_Interview_150_1D_DP #Big_O_Time_O(m*n)_Space_O(amount)
// #2024_11_07_Time_22_ms_(87.50%)_Space_12.3_MB_(23.00%)

#include <stdio.h>
#include <limits.h>

int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc((amount + 1) * sizeof(int));

    // Initialize dp array, where dp[i] represents the minimum number of coins to make amount i.
    // Set dp[0] to 1 as the base case (1 represents that 0 coins are needed to make amount 0).
    dp[0] = 1;
    for (int i = 1; i <= amount; i++) {
        dp[i] = 0;
    }

    for (int c = 0; c < coinsSize; c++) {
        int coin = coins[c];
        for (int i = coin; i <= amount; i++) {
            int prev = dp[i - coin];
            if (prev > 0) {  // If it's possible to make amount (i - coin)
                if (dp[i] == 0) {
                    dp[i] = prev + 1;
                } else {
                    dp[i] = (dp[i] < prev + 1) ? dp[i] : prev + 1;
                }
            }
        }
    }

    int result = (dp[amount] > 0) ? dp[amount] - 1 : -1; // Subtract 1 to account for the base case offset

    free(dp); // Free allocated memory
    return result;
}
