// #Hard #Top_100_Liked_Questions #String #Dynamic_Programming #Stack #Big_O_Time_O(n)_Space_O(1)
// #2024_10_29_Time_0_ms_(100.00%)_Space_8.4_MB_(65.46%)

#include <stdio.h>
#include <string.h>

// Function to find the length of the longest valid parentheses substring
int longestValidParentheses(const char* s) {
    int max = 0;
    int left = 0;
    int right = 0;
    int n = strlen(s);

    // Left to right pass
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (right > left) {
            left = 0;
            right = 0;
        }
        
        if (left == right) {
            int currentLength = left + right;
            if (currentLength > max) {
                max = currentLength;
            }
        }
    }

    // Reset left and right for the right to left pass
    left = 0;
    right = 0;

    // Right to left pass
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left > right) {
            left = 0;
            right = 0;
        }
        
        if (left == right) {
            int currentLength = left + right;
            if (currentLength > max) {
                max = currentLength;
            }
        }
    }

    return max;
}
