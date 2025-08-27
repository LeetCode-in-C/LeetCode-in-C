// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Sorting #Two_Pointers
// #Data_Structure_II_Day_1_Array #Algorithm_II_Day_3_Two_Pointers #Udemy_Two_Pointers
// #Top_Interview_150_Two_Pointers #Big_O_Time_O(n*log(n))_Space_O(n^2)
// #2024_10_28_Time_47_ms_(87.75%)_Space_41.5_MB_(64.78%)

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int **ret_arr = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
    int row = 0;
    int col = 3;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int j = i + 1;
        int k = numsSize - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                ret_arr[row] = (int*)malloc(sizeof(int) * col);
                (*returnColumnSizes)[row] = col;
                ret_arr[row][0] = nums[i];
                ret_arr[row][1] = nums[j];
                ret_arr[row][2] = nums[k];
                row++;

                while (j < k && nums[j + 1] == nums[j]) j++;
                while (j < k && nums[k - 1] == nums[k]) k--;

                j++;
                k--;
            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }

    *returnSize = row;
    return ret_arr;
}
