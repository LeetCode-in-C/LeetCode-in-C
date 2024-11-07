// #Medium #Top_100_Liked_Questions #Array #Hash_Table #Sorting #Heap_Priority_Queue #Counting
// #Divide_and_Conquer #Quickselect #Bucket_Sort #Data_Structure_II_Day_20_Heap_Priority_Queue
// #Big_O_Time_O(n*log(n))_Space_O(k) #2024_11_07_Time_0_ms_(100.00%)_Space_11.2_MB_(72.84%)

#include <stdlib.h>
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int n, int k, int* returnSize) {
    if (n == 0 || k == 0) *returnSize = 0;

    int min_val = INT_MAX;
    int max_val = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] < min_val) min_val = nums[i];
        if (nums[i] > max_val) max_val = nums[i];
    }

    int range = max_val - min_val + 1;
    int offset = -min_val; 

    // creating frequency array and puttin zero inside as default 

    int* freq = (int*)malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) freq[i] = 0;

    // stroing the frequency in the freq array by ++ opertor 

    for (int i = 0; i < n; i++) freq[nums[i] + offset]++;

    //  finding the k max elemts in the freq array and storing it in result array 
    int* result_1 = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        int maxval = -1;
        int max_index = -1;

        for (int j = 0; j < range; j++) {
            if (freq[j] > maxval) {
                maxval = freq[j];
                max_index = j;
            }
        }

        result_1[i] = max_index - offset;
        freq[max_index] = -1;
    }

    *returnSize = k;
    free(freq);
    return result_1;
}
