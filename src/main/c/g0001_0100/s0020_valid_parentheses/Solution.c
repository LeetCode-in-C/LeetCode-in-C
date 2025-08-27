// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #String #Stack
// #Data_Structure_I_Day_9_Stack_Queue #Udemy_Strings #Top_Interview_150_Stack
// #Big_O_Time_O(n)_Space_O(n) #2024_10_28_Time_0_ms_(100.00%)_Space_7.8_MB_(78.50%)

#include <stdbool.h>
#include <string.h>
#include <string.h>

bool isValid(char *s) {
    int n = strlen(s);
    if (n % 2 != 0) return false; // Check for odd length

    int i = 0;
    while (i < n - 1) {
        if ((s[i] == '(' && s[i + 1] == ')') ||
            (s[i] == '{' && s[i + 1] == '}') ||
            (s[i] == '[' && s[i + 1] == ']')) {
            // Remove matched parentheses
            memmove(&s[i], &s[i + 2], n - i - 1);
            n -= 2;
            s[n] = '\0';
            if (i >= 1) i--;
        } else {
            i++;
        }
    }

    return n == 0;
}
