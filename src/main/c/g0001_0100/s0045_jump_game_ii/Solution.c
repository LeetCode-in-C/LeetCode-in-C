// #Medium #Top_100_Liked_Questions #Array #Dynamic_Programming #Greedy
// #Algorithm_II_Day_13_Dynamic_Programming #Dynamic_Programming_I_Day_4
// #Top_Interview_150_Array/String #Big_O_Time_O(n)_Space_O(1)
// #2024_10_30_Time_0_ms_(100.00%)_Space_8.7_MB_(93.45%)

#include <stdio.h>

int jump(int* nums, int numsSize) {
    int length = 0;
    int maxLength = 0;
    int minJump = 0;

    for (int i = 0; i < numsSize - 1; ++i) {
        length--;
        maxLength--;
        if (nums[i] > maxLength) {
            maxLength = nums[i];
        }

        if (length <= 0) {
            length = maxLength;
            minJump++;
        }

        if (length >= numsSize - i - 1) {
            return minJump;
        }
    }

    return minJump;
}
