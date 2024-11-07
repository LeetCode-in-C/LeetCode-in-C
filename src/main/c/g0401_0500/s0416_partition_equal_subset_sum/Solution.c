// #Medium #Top_100_Liked_Questions #Array #Dynamic_Programming #Level_2_Day_13_Dynamic_Programming
// #Big_O_Time_O(n*sums)_Space_O(n*sums) #2024_11_07_Time_47_ms_(78.26%)_Space_8.1_MB_(76.81%)

#include <stdio.h>
#include <stdbool.h>

bool canPartition(int* nums, int numsSize) {
    int sums = 0;
    
    // Calculate the total sum of the array
    for (int i = 0; i < numsSize; i++) {
        sums += nums[i];
    }

    // If the total sum is odd, it's not possible to partition
    if (sums % 2 != 0) {
        return false;
    }

    // The target sum is half of the total sum
    sums /= 2;

    // Create a dynamic programming array to check for possible sums
    bool dp[sums + 1];
    
    // Initialize the dp array to false
    for (int i = 0; i <= sums; i++) {
        dp[i] = false;
    }
    
    dp[0] = true;  // Base case: sum of 0 is always possible

    // Iterate over each number in the array
    for (int i = 0; i < numsSize; i++) {
        // Update the dp array in reverse to avoid overwriting
        for (int sum = sums; sum >= nums[i]; sum--) {
            dp[sum] = dp[sum] || dp[sum - nums[i]];
        }
    }

    // The result is whether it's possible to make a subset with the sum equal to 'sums'
    return dp[sums];
}
