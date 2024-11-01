// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Sorting #Two_Pointers
// #Data_Structure_II_Day_2_Array #Udemy_Arrays #Big_O_Time_O(n)_Space_O(1)
// #2024_11_01_Time_0_ms_(100.00%)_Space_9.6_MB_(52.60%)

#include <stdio.h>

void sortColors(int* nums, int numsSize) {
    int zeroes = 0; // Count of 0s
    int ones = 0;   // Count of 1s

    // Count the number of 0s and 1s
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            nums[zeroes++] = 0; // Place 0 at the current zeroes position
        } else if (nums[i] == 1) {
            ones++; // Count the number of 1s
        }
    }

    // Fill in 1s in the next positions
    for (int j = zeroes; j < zeroes + ones; j++) {
        nums[j] = 1;
    }

    // Fill in 2s in the remaining positions
    for (int k = zeroes + ones; k < numsSize; k++) {
        nums[k] = 2;
    }
}
