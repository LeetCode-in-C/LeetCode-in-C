// #Medium #Top_Interview_Questions #Math #Udemy_Integers
// #2024_10_28_Time_0_ms_(100.00%)_Space_8.3_MB_(93.52%)

int reverse(int x) {
    long rev = 0;
    while (x != 0) {
        rev = (rev * 10) + (x % 10);
        x /= 10;
    }
    
    // Check for overflow
    if (rev > INT_MAX || rev < INT_MIN) {
        return 0;
    }
    
    return (int)rev;
}
