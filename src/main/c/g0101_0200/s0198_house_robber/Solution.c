// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming
// #Algorithm_I_Day_12_Dynamic_Programming #Dynamic_Programming_I_Day_3
// #Level_2_Day_12_Dynamic_Programming #Udemy_Dynamic_Programming #Big_O_Time_O(n)_Space_O(n)
// #2024_11_05_Time_0_ms_(100.00%)_Space_8.3_MB_(7.79%)

#include <stdio.h>

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate the maximum profit from robbing houses
int rob(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    if (numsSize == 2) {
        return max(nums[0], nums[1]);
    }

    // Array to store the maximum profit up to each house
    int profit[numsSize];
    profit[0] = nums[0];
    profit[1] = max(nums[1], nums[0]);

    // Fill in the profit array using dynamic programming
    for (int i = 2; i < numsSize; i++) {
        profit[i] = max(profit[i - 1], nums[i] + profit[i - 2]);
    }

    // The last element in the profit array contains the maximum profit
    return profit[numsSize - 1];
}
