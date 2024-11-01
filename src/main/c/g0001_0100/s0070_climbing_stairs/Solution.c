// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Dynamic_Programming #Math #Memoization
// #Algorithm_I_Day_12_Dynamic_Programming #Dynamic_Programming_I_Day_2
// #Level_1_Day_10_Dynamic_Programming #Udemy_Dynamic_Programming #Big_O_Time_O(n)_Space_O(n)
// #2024_11_01_Time_1_ms_(100.00%)_Space_8.1_MB_(17.90%)

#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) {
    if (n < 2) {
        return n;
    }

    // Create an array to store the number of ways to climb to each step
    int* cache = (int*)malloc(n * sizeof(int));
    
    // Base cases
    cache[0] = 1; // 1 way to climb to the 1st step
    cache[1] = 2; // 2 ways to climb to the 2nd step

    // Fill the cache using dynamic programming
    for (int i = 2; i < n; i++) {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    // Store the result
    int result = cache[n - 1];

    // Free allocated memory
    free(cache);

    return result;
}
