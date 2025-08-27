// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Backtracking
// #Algorithm_I_Day_11_Recursion_Backtracking #Level_2_Day_20_Brute_Force/Backtracking
// #Udemy_Backtracking/Recursion #Top_Interview_150_Backtracking #Big_O_Time_O(n*n!)_Space_O(n+n!)
// #2024_10_30_Time_0_ms_(100.00%)_Space_12.2_MB_(7.95%)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void addResult(int** result, int* returnSize, int* columnSizes, int* currResult, int numsSize) {
    result[*returnSize] = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        result[*returnSize][i] = currResult[i];
    }
    columnSizes[*returnSize] = numsSize;
    (*returnSize)++;
}

void permuteRecur(int* nums, int numsSize, int** result, int* returnSize, int* columnSizes, int* currResult, bool* used, int currIndex) {
    if (currIndex == numsSize) {
        addResult(result, returnSize, columnSizes, currResult, numsSize);
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) {
            continue;
        }
        currResult[currIndex] = nums[i];
        used[i] = true;
        permuteRecur(nums, numsSize, result, returnSize, columnSizes, currResult, used, currIndex + 1);
        used[i] = false;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = malloc(1000 * sizeof(int*));  // Allocate space for result
    *returnSize = 0;
    *returnColumnSizes = malloc(1000 * sizeof(int)); // Allocate space for column sizes

    bool* used = calloc(numsSize, sizeof(bool));
    int* currResult = malloc(numsSize * sizeof(int));

    permuteRecur(nums, numsSize, result, returnSize, *returnColumnSizes, currResult, used, 0);

    free(used);
    free(currResult);

    return result;
}
