// #Medium #Top_100_Liked_Questions #Array #Binary_Search #Algorithm_II_Day_2_Binary_Search
// #Binary_Search_I_Day_12 #Udemy_Binary_Search #Big_O_Time_O(log_N)_Space_O(log_N)
// #2024_11_05_Time_0_ms_(100.00%)_Space_8.1_MB_(92.83%)

#include <stdio.h>

// Helper function to find the minimum element in a rotated sorted array
int findMinUtil(int* nums, int l, int r) {
    if (l == r) {
        return nums[l];
    }

    int mid = (l + r) / 2;

    // If array is not rotated or only two elements left
    if (mid == l && nums[mid] < nums[r]) {
        return nums[l];
    }

    // Check if the middle element is the minimum
    if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
        return nums[mid];
    }

    // Decide which half to search
    if (nums[mid] < nums[l]) {
        return findMinUtil(nums, l, mid - 1);
    } else if (nums[mid] > nums[r]) {
        return findMinUtil(nums, mid + 1, r);
    }

    // If there’s ambiguity, search the left half
    return findMinUtil(nums, l, mid - 1);
}

// Function to initialize the search for minimum in the rotated sorted array
int findMin(int* nums, int numsSize) {
    int l = 0;
    int r = numsSize - 1;
    return findMinUtil(nums, l, r);
}
