// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Hash_Table #Backtracking
// #LeetCode_75_Backtracking #Algorithm_II_Day_11_Recursion_Backtracking
// #Udemy_Backtracking/Recursion #Top_Interview_150_Backtracking #Big_O_Time_O(4^n)_Space_O(n)
// #2024_10_28_Time_0_ms_(100.00%)_Space_8.3_MB_(50.21%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMBINATIONS 1000

void findCombinations(int start, const char *digits, const char **letters, char *curr, int depth, char ***ans, int *returnSize) {
    if (depth == strlen(digits)) {
        (*ans)[*returnSize] = strdup(curr);
        (*returnSize)++;
        return;
    }

    for (int i = start; i < strlen(digits); i++) {
        int n = digits[i] - '0';
        for (int j = 0; letters[n][j] != '\0'; j++) {
            curr[depth] = letters[n][j];
            findCombinations(i + 1, digits, letters, curr, depth + 1, ans, returnSize);
        }
    }
}

char **letterCombinations(const char *digits, int *returnSize) {
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }

    const char *letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **ans = (char **)malloc(MAX_COMBINATIONS * sizeof(char *));
    char *curr = (char *)malloc((strlen(digits) + 1) * sizeof(char));
    curr[strlen(digits)] = '\0';
    int returnCount = 0;

    findCombinations(0, digits, letters, curr, 0, &ans, &returnCount);

    free(curr);
    *returnSize = returnCount;
    return ans;
}
