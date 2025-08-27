// #Medium #Top_100_Liked_Questions #Array #Binary_Search #Matrix #Data_Structure_I_Day_5_Array
// #Algorithm_II_Day_1_Binary_Search #Binary_Search_I_Day_8 #Level_2_Day_8_Binary_Search
// #Udemy_2D_Arrays/Matrix #Top_Interview_150_Binary_Search #Big_O_Time_O(endRow+endCol)_Space_O(1)
// #2024_11_01_Time_0_ms_(100.00%)_Space_9_MB_(18.47%)

#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int endRow = matrixSize;
    int endCol = *matrixColSize;
    int targetRow = 0;
    bool result = false;

    // Step 1: Find the row that may contain the target
    for (int i = 0; i < endRow; i++) {
        if (matrix[i][endCol - 1] >= target) {
            targetRow = i;
            break;
        }
    }

    // Step 2: Search within the target row for the target value
    for (int i = 0; i < endCol; i++) {
        if (matrix[targetRow][i] == target) {
            result = true;
            break;
        }
    }

    return result;
}
