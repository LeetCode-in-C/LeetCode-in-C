// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming
// #Dynamic_Programming_I_Day_6 #Level_2_Day_13_Dynamic_Programming #Udemy_Dynamic_Programming
// #Big_O_Time_O(N)_Space_O(1) #2024_11_05_Time_0_ms_(100.00%)_Space_8.8_MB_(58.72%)

#include <stdio.h>
#include <limits.h>

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the maximum product subarray
int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int currentMaxProd = nums[0];
    int currentMinProd = nums[0];
    int overAllMaxProd = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < 0) {
            // Swap currentMaxProd and currentMinProd
            int temp = currentMaxProd;
            currentMaxProd = currentMinProd;
            currentMinProd = temp;
        }

        // Update the current maximum and minimum products
        currentMaxProd = max(nums[i], nums[i] * currentMaxProd);
        currentMinProd = min(nums[i], nums[i] * currentMinProd);

        // Update the overall maximum product
        overAllMaxProd = max(overAllMaxProd, currentMaxProd);
    }

    return overAllMaxProd;
}
