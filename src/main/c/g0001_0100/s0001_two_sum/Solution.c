// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table
// #Data_Structure_I_Day_2_Array #Level_1_Day_13_Hashmap #Udemy_Arrays #Big_O_Time_O(n)_Space_O(n)
// #AI_can_be_used_to_solve_the_task #2024_10_16_Time_2_ms_(99.56%)_Space_8.6_MB_(40.96%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    returnSize[0] = 2;
    int* output = (int*)malloc(sizeof(int) * 2);

    for (int offset = 1; offset < numsSize; offset++) {
        int i = 0;
        while (i + offset < numsSize) {
            if (nums[i] + nums[i + offset] == target) {
                output[0] = i;
                output[1] = i + offset;
                return output;
            }
            i++;
        }
    }
    return (void*)0;
}
