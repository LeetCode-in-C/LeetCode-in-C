// #Easy #Top_100_Liked_Questions #Array #Two_Pointers #Algorithm_I_Day_3_Two_Pointers
// #Programming_Skills_I_Day_6_Array #Udemy_Arrays #Big_O_Time_O(n)_Space_O(1)
// #2024_11_07_Time_0_ms_(100.00%)_Space_19.5_MB_(47.88%)

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes(int* nums, int numsSize) {
    int firstZero = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            swap(&nums[firstZero], &nums[i]);
            firstZero++;
        }
    }
}
