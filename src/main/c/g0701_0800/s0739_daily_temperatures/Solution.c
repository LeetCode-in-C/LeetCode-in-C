// #Medium #Top_100_Liked_Questions #Array #Stack #Monotonic_Stack #Programming_Skills_II_Day_6
// #Big_O_Time_O(n)_Space_O(n) #2024_11_08_Time_3_ms_(98.31%)_Space_68.5_MB_(94.81%)

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Function to calculate the daily temperatures
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* sol = (int*)calloc(temperaturesSize, sizeof(int)); // Initialize the solution array with zeros
    sol[temperaturesSize - 1] = 0; // Last element is 0 by default
    *returnSize = temperaturesSize; // Set the size of the return array

    for (int i = temperaturesSize - 2; i >= 0; i--) {
        int j = i + 1;
        while (j < temperaturesSize) {
            if (temperatures[i] < temperatures[j]) {
                sol[i] = j - i;
                break;
            } else {
                if (sol[j] == 0) {
                    break;
                }
                j = j + sol[j];
            }
        }
    }

    return sol;
}
