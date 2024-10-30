// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming #Greedy
// #Algorithm_II_Day_12_Dynamic_Programming #Dynamic_Programming_I_Day_4 #Udemy_Arrays
// #Big_O_Time_O(n)_Space_O(1) #2024_10_30_Time_0_ms_(100.00%)_Space_10.7_MB_(25.17%)

#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int tmp = 1;
    for (int i = 0; i < numsSize; i++) {
        tmp--;
        if (tmp < 0) {
            return false;
        }
        tmp = (tmp > nums[i]) ? tmp : nums[i];
        if (i + tmp >= numsSize - 1) {
            return true;
        }
    }
    return true;
}
