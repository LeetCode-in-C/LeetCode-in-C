// #Medium #Top_100_Liked_Questions #Array #Binary_Search #Matrix #Divide_and_Conquer
// #Data_Structure_II_Day_4_Array #Binary_Search_II_Day_8 #Big_O_Time_O(n+m)_Space_O(1)
// #2024_11_07_Time_42_ms_(96.34%)_Space_11.9_MB_(56.70%)

#include <stdbool.h>
#include <stdio.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int r = 0;
    int c = matrixColSize[0] - 1; // Start from the top-right corner

    while (r < matrixSize && c >= 0) {
        if (matrix[r][c] == target) {
            return true;
        } else if (matrix[r][c] > target) {
            c--; // Move left
        } else {
            r++; // Move down
        }
    }
    return false;
}
