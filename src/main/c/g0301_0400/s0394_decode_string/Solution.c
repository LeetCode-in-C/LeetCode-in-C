// #Medium #Top_100_Liked_Questions #String #Stack #Recursion #Level_1_Day_14_Stack #Udemy_Strings
// #Big_O_Time_O(n)_Space_O(n) #2024_11_07_Time_0_ms_(100.00%)_Space_9.1_MB_(21.38%)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Helper function to repeat a string a given number of times
char* repeatString(const char* str, int count) {
    int len = strlen(str);
    char* result = (char*)malloc(len * count + 1);
    result[0] = '\0'; // Start with an empty string
    
    for (int i = 0; i < count; i++) {
        strcat(result, str);
    }
    return result;
}

// Helper function for recursive decoding
char* decodeHelper(char* s, int* pos) {
    char* result = (char*)malloc(10000); // Allocate sufficient space for result
    result[0] = '\0'; // Initialize as an empty string
    int count = 0;

    while (s[*pos] != '\0') {
        char c = s[*pos];
        (*pos)++;

        if (isalpha(c)) {
            // If it's a letter, append it to the result
            int len = strlen(result);
            result[len] = c;
            result[len + 1] = '\0';
        } else if (isdigit(c)) {
            // If it's a digit, accumulate it as part of count
            count = count * 10 + (c - '0');
        } else if (c == '[') {
            // Start of a nested encoded string
            char* decodedSubstring = decodeHelper(s, pos);
            char* repeatedSubstring = repeatString(decodedSubstring, count);
            strcat(result, repeatedSubstring);
            free(decodedSubstring);
            free(repeatedSubstring);
            count = 0; // Reset count after using it
        } else if (c == ']') {
            // End of the current encoded substring
            break;
        }
    }
    return result;
}

// Main function to decode the string
char* decodeString(char* s) {
    int pos = 0;
    return decodeHelper(s, &pos);
}
