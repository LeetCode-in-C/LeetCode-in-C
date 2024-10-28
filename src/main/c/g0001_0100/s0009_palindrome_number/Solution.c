// #Easy #Math #Udemy_Integers #2024_10_28_Time_0_ms_(100.00%)_Space_8_MB_(63.90%)

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    int rev = 0;
    int localX = x;

    while (localX > 0) {
        // Check for potential overflow
        if (rev > (2147483647 / 10)) {
            return false; // This would overflow in 32-bit int
        }
        
        rev = rev * 10 + (localX % 10);
        localX /= 10;
    }

    return rev == x;
}
