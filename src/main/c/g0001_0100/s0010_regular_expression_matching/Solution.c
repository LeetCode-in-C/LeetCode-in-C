// #Hard #Top_Interview_Questions #String #Dynamic_Programming #Recursion #Udemy_Dynamic_Programming
// #Big_O_Time_O(m*n)_Space_O(m*n) #2024_10_28_Time_0_ms_(100.00%)_Space_8.4_MB_(5.96%)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int** cache; // 2D array for caching results

// Helper function to initialize the cache with -1 values (indicating unvisited)
void initializeCache(int sLen, int pLen) {
    cache = (int**)malloc((sLen + 1) * sizeof(int*));
    for (int i = 0; i <= sLen; i++) {
        cache[i] = (int*)malloc((pLen + 1) * sizeof(int));
        for (int j = 0; j <= pLen; j++) {
            cache[i][j] = -1; // -1 indicates an unvisited state
        }
    }
}

// Recursive function to check for matches with caching
bool isMatchHelper(const char* s, const char* p, int i, int j) {
    int sLen = strlen(s);
    int pLen = strlen(p);

    // If pattern is exhausted, check if string is also exhausted
    if (j == pLen) {
        return i == sLen;
    }

    // Check cache to avoid recomputation
    if (cache[i][j] != -1) {
        return cache[i][j];
    }

    // Check if the current characters match
    bool firstMatch = (i < sLen && (s[i] == p[j] || p[j] == '.'));

    bool result;
    if ((j + 1) < pLen && p[j + 1] == '*') {
        // Case with '*' in pattern
        result = (firstMatch && isMatchHelper(s, p, i + 1, j)) || isMatchHelper(s, p, i, j + 2);
    } else {
        // Regular character match
        result = firstMatch && isMatchHelper(s, p, i + 1, j + 1);
    }

    cache[i][j] = result; // Store result in cache
    return result;
}

// Main function to check if `s` matches `p`
bool isMatch(const char* s, const char* p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    initializeCache(sLen, pLen);
    bool result = isMatchHelper(s, p, 0, 0);

    // Free memory allocated for cache
    for (int i = 0; i <= sLen; i++) {
        free(cache[i]);
    }
    free(cache);

    return result;
}
