// #Medium #Top_100_Liked_Questions #Array #Backtracking #Algorithm_II_Day_10_Recursion_Backtracking
// #Level_2_Day_20_Brute_Force/Backtracking #Udemy_Backtracking/Recursion
// #Big_O_Time_O(2^n)_Space_O(n+2^n) #2024_10_30_Time_0_ms_(100.00%)_Space_21.3_MB_(5.26%)

#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compareInt(void *a, void *b) {
    return (*(int *)a) - (*(int *)b);
}

void combinationRec(int *arr, int n, int pos, int target, int **seq, int pos1, int **res, int *resP, int **cols) {
    int *seq2;

    if (target == 0) {
        res[*resP] = *seq;
        (*cols)[*resP] = pos1;
        *resP += 1;
        return;
    }

    if (pos == n || arr[pos] > target) {
        free(*seq);
        return;
    }

    seq2 = malloc(40 * sizeof(int));
    memcpy(seq2, *seq, 40 * sizeof(int));

    (*seq)[pos1++] = arr[pos];
    combinationRec(arr, n, pos, target - arr[pos], seq, pos1, res, resP, cols);

    combinationRec(arr, n, pos + 1, target, &seq2, pos1 - 1, res, resP, cols);
}

int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes) {
    int *seq = malloc(40 * sizeof(int));
    int **res = malloc(200 * sizeof(int *));
    int resP = 0;
    int *cols = malloc(200 * sizeof(int));

    qsort(candidates, candidatesSize, sizeof(int), compareInt);
    combinationRec(candidates, candidatesSize, 0, target, &seq, 0, res, &resP, &cols);

    *returnSize = resP;
    *returnColumnSizes = cols;

    return res;
}
