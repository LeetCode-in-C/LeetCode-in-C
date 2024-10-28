// #Medium #Top_Interview_Questions #String #2024_10_28_Time_0_ms_(100.00%)_Space_8.5_MB_(69.69%)

#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int myAtoi(const char* str) {
    if (str == NULL || *str == '\0') {
        return 0;
    }

    int i = 0;
    int num = 0;
    int negativeSign = 0;

    // Skip leading whitespace
    while (str[i] == ' ') {
        i++;
    }

    // Check for sign
    if (str[i] == '+') {
        i++;
    } else if (str[i] == '-') {
        i++;
        negativeSign = 1;
    }

    // Convert string to integer
    while (str[i] >= '0' && str[i] <= '9') {
        int digit = str[i] - '0';
        
        if (negativeSign) {
            digit = -digit;
        }

        // Handle overflow and underflow
        if (num < INT_MIN / 10 || (num == INT_MIN / 10 && digit < -8)) {
            return INT_MIN;
        }
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)) {
            return INT_MAX;
        }

        num = num * 10 + digit;
        i++;
    }

    return num;
}
