// #Medium #Top_100_Liked_Questions #String #Hash_Table #Sliding_Window
// #Algorithm_II_Day_5_Sliding_Window #Programming_Skills_II_Day_12
// #Level_1_Day_12_Sliding_Window/Two_Pointer #Big_O_Time_O(n+m)_Space_O(1)
// #2024_11_08_Time_0_ms_(100.00%)_Space_14.2_MB_(26.60%)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Helper function to create a dynamic array for storing results
int* createResultArray(int initialSize) {
    return (int*)malloc(initialSize * sizeof(int));
}

// Main function to find all starting indices of p's anagrams in s
int* findAnagrams(const char* s, const char* p, int* returnSize) {
    int map[26] = {0}; // Frequency map for characters in p
    int lenS = strlen(s);
    int lenP = strlen(p);
    int initialSize = 10; // Initial size for result array
    int* result = createResultArray(initialSize);
    *returnSize = 0; // Keeps track of the number of results

    // Populate the frequency map based on string p
    for (int i = 0; i < lenP; ++i) {
        map[p[i] - 'a']++;
    }

    int i = 0, j = 0;
    while (i < lenS) {
        int idx = s[i] - 'a';
        map[idx]--;

        // Adjust the window when it exceeds the length of p
        if (i >= lenP) {
            map[s[j++] - 'a']++;
        }

        // Check if all elements in the map are zero (indicating an anagram)
        bool finish = true;
        for (int k = 0; k < 26; k++) {
            if (map[k] != 0) {
                finish = false;
                break;
            }
        }

        // Add the start index of the anagram to the result if conditions are met
        if (i >= lenP - 1 && finish) {
            if (*returnSize >= initialSize) {
                initialSize *= 2;
                result = realloc(result, initialSize * sizeof(int));
            }
            result[(*returnSize)++] = j;
        }
        i++;
    }
    return result;
}
