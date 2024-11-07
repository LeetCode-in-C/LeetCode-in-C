// #Easy #Dynamic_Programming #Bit_Manipulation #Udemy_Bit_Manipulation
// #Big_O_Time_O(num)_Space_O(num) #2024_11_07_Time_0_ms_(100.00%)_Space_15_MB_(36.75%)

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    // Allocate memory for the result array and set the return size
    int* result = (int*)malloc((num + 1) * sizeof(int));
    *returnSize = num + 1;

    int borderPos = 1;
    int incrPos = 1;

    result[0] = 0; // Base case: 0 has zero 1-bits

    for (int i = 1; i <= num; i++) {
        // When we reach a power of 2, reset borderPos and incrPos
        if (incrPos == borderPos) {
            result[i] = 1;  // Powers of 2 have exactly one 1-bit
            incrPos = 1;
            borderPos = i;
        } else {
            result[i] = 1 + result[incrPos++];
        }
    }

    return result;
}
