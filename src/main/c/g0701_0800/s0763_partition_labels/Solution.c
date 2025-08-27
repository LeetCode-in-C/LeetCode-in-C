// #Medium #Top_100_Liked_Questions #String #Hash_Table #Greedy #Two_Pointers
// #Data_Structure_II_Day_7_String #Big_O_Time_O(n)_Space_O(1)
// #2024_11_08_Time_0_ms_(100.00%)_Space_9.1_MB_(17.39%)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    int position[26] = {0}; // Last occurrence positions for each letter
    int length = strlen(s);

    // Populate the position array with the last index of each character
    for (int i = 0; i < length; i++) {
        position[s[i] - 'a'] = i;
    }

    // Initialize an array to store partition sizes
    int* result = (int*)malloc(length * sizeof(int));
    *returnSize = 0; // Set returnSize to 0 initially
    int prev = -1;
    int max = 0;

    // Iterate through the string to find partitions
    for (int i = 0; i < length; i++) {
        if (position[s[i] - 'a'] > max) {
            max = position[s[i] - 'a'];
        }
        if (i == max) {
            result[*returnSize] = i - prev;
            (*returnSize)++;
            prev = i;
        }
    }

    // Resize the result array to the exact number of partitions found
    result = (int*)realloc(result, (*returnSize) * sizeof(int));
    return result;
}
