// #Medium #String #2024_10_28_Time_0_ms_(100.00%)_Space_8.6_MB_(83.33%)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(const char* s, int numRows) {
    int sLen = strlen(s);
    if (numRows == 1) {
        // Return a copy of s since the function is expected to return a new string
        char* result = (char*)malloc((sLen + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    int maxDist = numRows * 2 - 2;
    char* buf = (char*)malloc((sLen + 1) * sizeof(char));
    int bufIndex = 0; // Keeps track of current position in buffer

    for (int i = 0; i < numRows; i++) {
        int index = i;
        if (i == 0 || i == numRows - 1) {
            // For the first and last rows
            while (index < sLen) {
                buf[bufIndex++] = s[index];
                index += maxDist;
            }
        } else {
            // For the middle rows
            while (index < sLen) {
                buf[bufIndex++] = s[index];
                index += maxDist - i * 2;
                if (index >= sLen) {
                    break;
                }
                buf[bufIndex++] = s[index];
                index += i * 2;
            }
        }
    }

    buf[bufIndex] = '\0';
    return buf;
}
