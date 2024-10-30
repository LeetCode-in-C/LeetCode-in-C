// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table #Udemy_Arrays
// #Big_O_Time_O(n)_Space_O(n) #2024_10_30_Time_0_ms_(100.00%)_Space_13.7_MB_(55.20%)

#include <stdio.h>

void dfs(int* nums, int numsSize, int val) {
    if (val <= 0 || val > numsSize || val == nums[val - 1]) {
        return;
    }
    int temp = nums[val - 1];
    nums[val - 1] = val;
    dfs(nums, numsSize, temp);
}

int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 0 || nums[i] > numsSize || nums[i] == i + 1) {
            continue;
        }
        dfs(nums, numsSize, nums[i]);
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return numsSize + 1;
}
