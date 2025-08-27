// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming #Two_Pointers
// #Stack #Monotonic_Stack #Dynamic_Programming_I_Day_9 #Udemy_Two_Pointers
// #Top_Interview_150_Array/String #Big_O_Time_O(n)_Space_O(1)
// #2024_10_30_Time_0_ms_(100.00%)_Space_9.6_MB_(64.92%)

#include <stdio.h>

int trap(int* height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int res = 0;
    int lowerWall = 0;

    while (l < r) {
        int lVal = height[l];
        int rVal = height[r];

        // Determine which side has the lower wall and add water accordingly
        if (lVal < rVal) {
            // Update lower wall height if lVal has increased
            lowerWall = lVal > lowerWall ? lVal : lowerWall;
            // Add the trapped water at this position
            res += lowerWall - lVal;
            // Move left pointer
            l++;
        } else {
            // Update lower wall height if rVal has increased
            lowerWall = rVal > lowerWall ? rVal : lowerWall;
            // Add the trapped water at this position
            res += lowerWall - rVal;
            // Move right pointer
            r--;
        }
    }

    return res;
}
