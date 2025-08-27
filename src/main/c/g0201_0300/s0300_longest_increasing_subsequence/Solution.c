// #Medium #Top_100_Liked_Questions #Array #Dynamic_Programming #Binary_Search
// #Algorithm_II_Day_16_Dynamic_Programming #Binary_Search_II_Day_3 #Dynamic_Programming_I_Day_18
// #Udemy_Dynamic_Programming #Top_Interview_150_1D_DP #Big_O_Time_O(n*log_n)_Space_O(n)
// #2024_11_07_Time_0_ms_(100.00%)_Space_8.4_MB_(29.59%)

#include <stdio.h>
#include <limits.h>

int lengthOfLIS(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int* dp = (int*)malloc((numsSize + 1) * sizeof(int));

    // Prefill the dp array with INT_MAX
    for (int i = 1; i <= numsSize; i++) {
        dp[i] = INT_MAX;
    }

    int left = 1;
    int right = 1;

    for (int i = 0; i < numsSize; i++) {
        int curr = nums[i];
        int start = left;
        int end = right;

        // Binary search within dp to find the correct position for curr
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (dp[mid] > curr) {
                end = mid;
            } else {
                start = mid;
            }
        }

        // Update dp array based on binary search result
        if (dp[start] > curr) {
            dp[start] = curr;
        } else if (curr > dp[start] && curr < dp[end]) {
            dp[end] = curr;
        } else if (curr > dp[end]) {
            dp[++end] = curr;
            right++;
        }
    }

    int result = right;

    free(dp);  // Free the allocated memory for dp array

    return result;
}
