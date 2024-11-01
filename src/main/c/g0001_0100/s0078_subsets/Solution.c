// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Bit_Manipulation #Backtracking
// #Algorithm_II_Day_9_Recursion_Backtracking #Udemy_Backtracking/Recursion
// #Big_O_Time_O(2^n)_Space_O(n*2^n) #2024_11_01_Time_0_ms_(100.00%)_Space_10.9_MB_(35.71%)

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int* nums, int numsSize, int** res, int* returnSize, int* returnColumnSizes, int* temp, int tempSize, int start) {
    // Add the current subset to the result
    res[*returnSize] = (int*)malloc((tempSize + 1) * sizeof(int));
    for (int i = 0; i < tempSize; i++) {
        res[*returnSize][i] = temp[i];
    }
    // Mark the end of the subset with -1 (optional)
    res[*returnSize][tempSize] = -1; 
    returnColumnSizes[*returnSize] = tempSize; // Store the size of the current subset
    (*returnSize)++;

    // Generate subsets
    for (int i = start; i < numsSize; i++) {
        temp[tempSize] = nums[i]; // Add current number to the subset
        backtrack(nums, numsSize, res, returnSize, returnColumnSizes, temp, tempSize + 1, i + 1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(1024 * sizeof(int*)); // Initial allocation for up to 1024 subsets
    *returnSize = 0; // Initialize the count of subsets
    *returnColumnSizes = (int*)malloc(1024 * sizeof(int)); // Initialize sizes array
    int* temp = (int*)malloc(numsSize * sizeof(int)); // Temporary array for current subset

    backtrack(nums, numsSize, res, returnSize, *returnColumnSizes, temp, 0, 0);

    free(temp); // Free temporary array
    return res;
}
