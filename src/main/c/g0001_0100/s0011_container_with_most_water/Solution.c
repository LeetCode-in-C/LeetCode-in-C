// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Greedy #Two_Pointers
// #Algorithm_II_Day_4_Two_Pointers #Big_O_Time_O(n)_Space_O(1)
// #2024_10_28_Time_0_ms_(100.00%)_Space_13.9_MB_(58.08%)

#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int maxArea = -1;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int area = (height[left] < height[right]) 
                    ? height[left] * (right - left) 
                    : height[right] * (right - left);
        
        if (area > maxArea) {
            maxArea = area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}
