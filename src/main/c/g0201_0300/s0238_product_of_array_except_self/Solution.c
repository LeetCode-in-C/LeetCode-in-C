// #Medium #Top_100_Liked_Questions #Array #Prefix_Sum #LeetCode_75_Array/String
// #Data_Structure_II_Day_5_Array #Udemy_Arrays #Top_Interview_150_Array/String
// #Big_O_Time_O(n^2)_Space_O(n) #2024_11_06_Time_0_ms_(100.00%)_Space_30.1_MB_(83.93%)

#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int product = 1;

    // Calculate the product of all elements
    for (int i = 0; i < numsSize; i++) {
        product *= nums[i];
    }

    // Calculate the result for each element
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            ans[i] = product / nums[i];
        } else {
            int p = 1;
            for (int j = 0; j < numsSize; j++) {
                if (j != i) {
                    p *= nums[j];
                }
            }
            ans[i] = p;
        }
    }

    *returnSize = numsSize;
    return ans;
}
