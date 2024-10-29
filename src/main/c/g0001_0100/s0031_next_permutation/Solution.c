// #Medium #Top_100_Liked_Questions #Array #Two_Pointers #Big_O_Time_O(n)_Space_O(1)
// #2024_10_29_Time_0_ms_(100.00%)_Space_10.6_MB_(91.02%)

#include <stdio.h>

// Function to swap two elements in the array
void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// Function to reverse elements in the array from index i to j
void reverse(int* nums, int i, int j) {
    while (i < j) {
        swap(nums, i++, j--);
    }
}

// Function to find the next permutation
void nextPermutation(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 1) {
        return;
    }

    int i = numsSize - 2;
    // Find the first decreasing element from the end
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = numsSize - 1;
        // Find the element just larger than nums[i]
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }

    // Reverse the elements after the found index to get the next smallest lexicographic order
    reverse(nums, i + 1, numsSize - 1);
}
