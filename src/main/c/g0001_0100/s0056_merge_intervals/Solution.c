// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Sorting
// #Data_Structure_II_Day_2_Array #Level_2_Day_17_Interval #Udemy_2D_Arrays/Matrix
// #Big_O_Time_O(n_log_n)_Space_O(n) #2024_11_01_Time_0_ms_(100.00%)_Space_17.9_MB_(68.75%)

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    // Step 1: Sort the intervals based on the starting times
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // Step 2: Create a dynamic array to hold merged intervals
    int** merged = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    *returnSize = 0;

    // Initialize the current interval as the first one
    int* current = intervals[0];
    merged[(*returnSize)++] = (int*)malloc(2 * sizeof(int));
    merged[0][0] = current[0];
    merged[0][1] = current[1];

    // Step 3: Iterate through the intervals
    for (int i = 1; i < intervalsSize; i++) {
        int* next = intervals[i];
        // Check if there is an overlap
        if (current[1] >= next[0]) {
            current[1] = (current[1] > next[1]) ? current[1] : next[1]; // Merge
            merged[*returnSize - 1][1] = current[1]; // Update the last merged interval
        } else {
            current = next; // Move to the next interval
            merged[(*returnSize)++] = (int*)malloc(2 * sizeof(int));
            merged[*returnSize - 1][0] = current[0];
            merged[*returnSize - 1][1] = current[1];
        }
    }

    // Step 4: Allocate return column sizes
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2; // Each merged interval has size 2
    }

    return merged;
}
