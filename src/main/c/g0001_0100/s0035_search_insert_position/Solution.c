// #Easy #Top_100_Liked_Questions #Array #Binary_Search #Algorithm_I_Day_1_Binary_Search
// #Binary_Search_I_Day_2 #Big_O_Time_O(log_n)_Space_O(1)
// #2024_10_29_Time_0_ms_(100.00%)_Space_8.4_MB_(17.62%)

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int lo = 0;
    int hi = numsSize - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            hi = mid - 1;
        } else { // target > nums[mid]
            lo = mid + 1;
        }
    }
    return lo; // return the insertion point
}
