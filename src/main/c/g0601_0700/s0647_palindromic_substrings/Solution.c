// #Medium #String #Dynamic_Programming #Big_O_Time_O(n^2)_Space_O(n)
// #2024_11_08_Time_0_ms_(100.00%)_Space_8_MB_(24.56%)

int isRepeat(char*s , int idx, int len, int* counter) {
    int tmp = idx + 1;
    while(tmp < len && s[tmp] == s[idx]) tmp++;
    *counter += ((tmp-idx)*(tmp-idx-1))/2;

    return tmp;
}

int isPalindrome(char* s, int idx, int len, int* counter) {
    int end = isRepeat(s, idx, len, counter);
    int ret = end;
    int start = idx - 1;
    while(start >= 0 && end < len && s[start--] == s[end++]) (*counter)++;
    
    return ret;
}

int countSubstrings(char* s) {
    int len = strlen(s);
    int counter = len;
    int idx = 0;
    while(idx < len) idx = isPalindrome(s, idx, len, &counter);

    return counter;
}
