// #Medium #Array #Dynamic_Programming #Backtracking #Big_O_Time_O(n*(sum+s))_Space_O(n*(sum+s))
// #2024_11_08_Time_7_ms_(70.83%)_Space_12.4_MB_(5.26%)

#include <stdio.h>
#include <stdlib.h>

int findTargetSumWays(int* nums, int numsSize, int s) {
    int sum = 0;
    s = abs(s);
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    
    // Invalid target case, return 0
    if (s > sum || (sum + s) % 2 != 0) {
        return 0;
    }
    
    int target = (sum + s) / 2;
    
    // Initialize the dp array
    int** dp = (int**)malloc((target + 1) * sizeof(int*));
    for (int i = 0; i <= target; i++) {
        dp[i] = (int*)calloc(numsSize + 1, sizeof(int));
    }
    
    dp[0][0] = 1;
    
    // Initialize the base case
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            dp[0][i + 1] = dp[0][i] * 2;
        } else {
            dp[0][i + 1] = dp[0][i];
        }
    }
    
    // Fill the dp table
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < numsSize; j++) {
            dp[i][j + 1] = dp[i][j];
            if (nums[j] <= i) {
                dp[i][j + 1] += dp[i - nums[j]][j];
            }
        }
    }
    
    int result = dp[target][numsSize];
    
    // Free the dynamically allocated memory
    for (int i = 0; i <= target; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}
