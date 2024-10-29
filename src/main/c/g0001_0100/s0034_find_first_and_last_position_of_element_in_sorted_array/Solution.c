// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Binary_Search
// #Algorithm_II_Day_1_Binary_Search #Binary_Search_I_Day_5 #Big_O_Time_O(log_n)_Space_O(1)
// #2024_10_29_Time_0_ms_(100.00%)_Space_10_MB_(11.22%)

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int helper(int* nums, int numsSize, int target, int equals) {
    int l = 0;
    int r = numsSize - 1;
    int result = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            result = mid;
        }
        if (nums[mid] < target || (nums[mid] == target && equals)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return result;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;  // There are always two elements in the result
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = helper(nums, numsSize, target, 0);  // Find the first occurrence
    result[1] = helper(nums, numsSize, target, 1);  // Find the last occurrence
    return result;
}
