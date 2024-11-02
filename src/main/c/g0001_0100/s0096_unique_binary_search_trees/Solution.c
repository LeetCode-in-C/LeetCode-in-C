// #Medium #Dynamic_Programming #Math #Tree #Binary_Tree #Binary_Search_Tree
// #Dynamic_Programming_I_Day_11 #Big_O_Time_O(n)_Space_O(1)
// #2024_11_02_Time_0_ms_(100.00%)_Space_7.5_MB_(81.73%)

#include <stdio.h>

int numTrees(int n) {
    long result = 1;
    for (int i = 0; i < n; i++) {
        result *= (2L * n - i);
        result /= (i + 1);
    }
    result /= (n + 1);
    return (int) result;
}
