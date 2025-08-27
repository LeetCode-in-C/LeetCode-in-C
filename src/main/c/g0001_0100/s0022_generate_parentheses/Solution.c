// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Dynamic_Programming
// #Backtracking #Algorithm_II_Day_11_Recursion_Backtracking #Udemy_Backtracking/Recursion
// #Top_Interview_150_Backtracking #Big_O_Time_O(2^n)_Space_O(n)
// #2024_10_29_Time_0_ms_(100.00%)_Space_9.2_MB_(78.89%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countPossibilities(int open, int closed, int n) {
    if (closed == n) {
        return 1;
    }

    if (open == n) {
        return countPossibilities(open, closed + 1, n);
    }

    if (open == closed) {
        return countPossibilities(open + 1, closed, n);
    }

    return countPossibilities(open + 1, closed, n) + countPossibilities(open, closed + 1, n);
}

void generateParentasis(
    int open,
    int closed,
    int n,
    char* currentString, 
    int currentIndex, 
    char** result, 
    int *resultIndex) {
        
    if (closed == n) {
        result[*resultIndex] = currentString; 
        (*resultIndex)++;
        return;
    }

    if (open == closed) {
        currentString[currentIndex] = '(';
        generateParentasis(open + 1, closed, n, currentString, currentIndex + 1, result, resultIndex);
        return;
    }

    if (open == n) {
        currentString[currentIndex] = ')';
        generateParentasis(open, closed + 1, n, currentString, currentIndex + 1, result, resultIndex);
        return;
    }

    char* duplicatedString = malloc(sizeof(char) * (n * 2 + 1));
    strcpy(duplicatedString, currentString);
    currentString[currentIndex] = '(';
    generateParentasis(open + 1, closed, n, currentString, currentIndex + 1, result, resultIndex);
    duplicatedString[currentIndex] = ')';
    generateParentasis(open, closed + 1, n, duplicatedString, currentIndex + 1, result, resultIndex);
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = countPossibilities(0, 0, n);
    char** result = malloc(sizeof(char*) * (*returnSize));
    int resultIndex = 0;
    char * currentString = malloc(sizeof(char) * (n * 2 + 1));
    currentString[n * 2] = '\0';
    generateParentasis(0, 0, n, currentString, 0, result, &resultIndex);
    return result;
}
