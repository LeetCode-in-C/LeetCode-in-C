// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Dynamic_Programming
// #Data_Structure_II_Day_9_String #Algorithm_II_Day_14_Dynamic_Programming
// #Dynamic_Programming_I_Day_17 #Udemy_Strings #Big_O_Time_O(n)_Space_O(n)
// #2024_10_20_Time_2_ms_(97.74%)_Space_9.4_MB_(14.91%)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(const char* s) {
    int len = strlen(s);
    
    // Create new string with inserted '#' characters
    int newLen = len * 2 + 1;
    char* newStr = (char*)malloc(newLen + 1);
    newStr[0] = '#';
    for (int i = 0; i < len; i++) {
        newStr[2 * i + 1] = s[i];
        newStr[2 * i + 2] = '#';
    }
    newStr[newLen] = '\0';
    
    int* dp = (int*)malloc(newLen * sizeof(int));
    int friendCenter = 0;
    int friendRadius = 0;
    int lpsCenter = 0;
    int lpsRadius = 0;

    for (int i = 0; i < newLen; i++) {
        dp[i] = (friendCenter + friendRadius > i) ? 
                 (dp[2 * friendCenter - i] < (friendCenter + friendRadius - i) ? dp[2 * friendCenter - i] : (friendCenter + friendRadius - i)) 
                 : 1;
        
        // Expanding around center
        while (i + dp[i] < newLen && i - dp[i] >= 0 && newStr[i + dp[i]] == newStr[i - dp[i]]) {
            dp[i]++;
        }

        // Update the friendCenter and friendRadius
        if (i + dp[i] > friendCenter + friendRadius) {
            friendCenter = i;
            friendRadius = dp[i];
        }

        // Update the longest palindromic substring center and radius
        if (dp[i] > lpsRadius) {
            lpsCenter = i;
            lpsRadius = dp[i];
        }
    }

    // Extract the original longest palindrome substring from 's'
    int start = (lpsCenter - lpsRadius + 1) / 2;
    int length = lpsRadius - 1;

    char* result = (char*)malloc(length + 1);
    strncpy(result, s + start, length);
    result[length] = '\0';

    // Free allocated memory
    free(newStr);
    free(dp);

    return result;
}
