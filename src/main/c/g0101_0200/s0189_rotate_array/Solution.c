// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Math #Two_Pointers
// #Algorithm_I_Day_2_Two_Pointers #Udemy_Arrays #Top_Interview_150_Array/String
// #Big_O_Time_O(n)_Space_O(1) #2024_11_05_Time_0_ms_(100.00%)_Space_26.6_MB_(36.20%)

#include <stdio.h>

// Helper function to reverse a subarray in place
void reverse(int* nums, int l, int r) {
    while (l < r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;
        r--;
    }
}

// Function to rotate the array to the right by k steps
void rotate(int* nums, int numsSize, int k) {
    int n = numsSize;
    k = k % n;  // Handle cases where k is greater than n
    int t = n - k;
    
    // Reverse different parts of the array in three steps
    reverse(nums, 0, t - 1);   // Reverse the first part (0 to t - 1)
    reverse(nums, t, n - 1);   // Reverse the second part (t to n - 1)
    reverse(nums, 0, n - 1);   // Reverse the whole array (0 to n - 1)
}
