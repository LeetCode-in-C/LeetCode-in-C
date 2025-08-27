// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming
// #Divide_and_Conquer #Data_Structure_I_Day_1_Array #Dynamic_Programming_I_Day_5
// #Udemy_Famous_Algorithm #Top_Interview_150_Kadane's_Algorithm #Big_O_Time_O(n)_Space_O(1)
// #2024_10_30_Time_0_ms_(100.00%)_Space_14.4_MB_(89.88%)

#include <stdio.h>
#include <limits.h>

int maxSubArray(int* nums, int numsSize) {
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        maxi = (sum > maxi) ? sum : maxi;
        
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}
