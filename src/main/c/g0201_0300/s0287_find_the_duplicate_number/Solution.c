// #Medium #Top_100_Liked_Questions #Array #Binary_Search #Two_Pointers #Bit_Manipulation
// #Binary_Search_II_Day_5 #Big_O_Time_O(n)_Space_O(n)
// #2024_11_07_Time_0_ms_(100.00%)_Space_14_MB_(62.83%)

#include <stdio.h>

int findDuplicate(int* nums, int numsSize) {
    // Create an array of size numsSize + 1, initialized to 0
    int arr[numsSize + 1];
    for (int i = 0; i <= numsSize; i++) {
        arr[i] = 0;
    }

    // Iterate over the nums array and update the arr counts
    for (int i = 0; i < numsSize; i++) {
        arr[nums[i]] += 1;
        if (arr[nums[i]] == 2) {
            return nums[i];  // Return the duplicate element
        }
    }

    return 0;  // In case no duplicate is found, though the problem assumes there is always a duplicate
}
