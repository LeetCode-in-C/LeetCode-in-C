// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Sorting #Heap_Priority_Queue
// #Divide_and_Conquer #Quickselect #LeetCode_75_Heap/Priority_Queue
// #Data_Structure_II_Day_20_Heap_Priority_Queue #Top_Interview_150_Heap
// #Big_O_Time_O(n*log(n))_Space_O(log(n)) #2024_11_06_Time_0_ms_(100.00%)_Space_14_MB_(67.54%)

#include <stdbool.h>
#include <stdlib.h>

int findKthLargest(int* nums, int numsSize, int k) {
    int positiveArr[10001] = {0};
    int negativeArr[10001] = {0};
    int cumulativeCount = 0;
    int result = 0;
    bool found = false;

    // Count occurrences of each element
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= 0) {
            positiveArr[nums[i]]++;
        } else {
            negativeArr[abs(nums[i])]++;
        }
    }

    // Search for the k-th largest in positive numbers
    for (int i = 10000; i >= 0; i--) {
        cumulativeCount += positiveArr[i];
        if (cumulativeCount >= k) {
            result = i;
            found = true;
            break;
        }
    }

    // If k-th largest is not found in positive numbers, search in negative numbers
    if (!found) {
        for (int i = 1; i <= 10000; i++) {
            cumulativeCount += negativeArr[i];
            if (cumulativeCount >= k) {
                result = -i;
                break;
            }
        }
    }

    return result;
}
