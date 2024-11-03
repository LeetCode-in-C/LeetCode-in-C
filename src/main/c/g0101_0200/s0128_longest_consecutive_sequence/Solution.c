// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table #Union_Find
// #Big_O_Time_O(N_log_N)_Space_O(1) #2024_11_03_Time_19_ms_(89.29%)_Space_15.8_MB_(58.07%)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    int max = INT_MIN;
    int thsMax = 1;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i + 1] == nums[i] + 1) {
            thsMax += 1;
        } else if (nums[i + 1] != nums[i]) {
            // Update max if current sequence is longer
            if (thsMax > max) {
                max = thsMax;
            }
            thsMax = 1; // Reset thsMax for a new sequence
        }
    }
    
    // Check the last sequence length
    if (thsMax > max) {
        max = thsMax;
    }

    return max;
}
