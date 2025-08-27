// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Math #Matrix
// #Data_Structure_II_Day_3_Array #Programming_Skills_II_Day_7 #Udemy_2D_Arrays/Matrix
// #Top_Interview_150_Matrix #Big_O_Time_O(n^2)_Space_O(1)
// #2024_10_30_Time_0_ms_(100.00%)_Space_10.2_MB_(38.96%)

#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;

    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            // Defining the four positions to be rotated in a cycle
            int pos[4][2] = {
                {i, j},
                {j, n - 1 - i},
                {n - 1 - i, n - 1 - j},
                {n - 1 - j, i}
            };

            // Starting the cycle rotation
            int t = matrix[pos[0][0]][pos[0][1]];
            for (int k = 1; k < 4; k++) {
                int temp = matrix[pos[k][0]][pos[k][1]];
                matrix[pos[k][0]][pos[k][1]] = t;
                t = temp;
            }
            matrix[pos[0][0]][pos[0][1]] = t;
        }
    }
}
