// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Binary_Search
// #Algorithm_II_Day_1_Binary_Search #Binary_Search_I_Day_11 #Level_2_Day_8_Binary_Search
// #Udemy_Binary_Search #Big_O_Time_O(log_n)_Space_O(1)
// #2024_10_29_Time_0_ms_(100.00%)_Space_8.4_MB_(20.29%)

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int lo = 0;
    int hi = numsSize - 1;
    int mid;

    while (lo <= hi) {
        mid = ((hi - lo) >> 1) + lo;

        if (nums[mid] == target) {
            return mid;
        }

        // Check if the left half is sorted
        if (nums[lo] <= nums[mid]) {
            // Target is in the left half
            if (nums[lo] <= target && target <= nums[mid]) {
                hi = mid - 1;
            } else { // Target is in the right half
                lo = mid + 1;
            }
        }
        // Otherwise, the right half is sorted
        else {
            // Target is in the right half
            if (nums[mid] <= target && target <= nums[hi]) {
                lo = mid + 1;
            } else { // Target is in the left half
                hi = mid - 1;
            }
        }
    }

    return -1;
}
