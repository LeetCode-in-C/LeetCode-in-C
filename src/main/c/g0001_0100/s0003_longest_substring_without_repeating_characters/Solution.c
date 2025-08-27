// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Hash_Table #Sliding_Window
// #Algorithm_I_Day_6_Sliding_Window #Level_2_Day_14_Sliding_Window/Two_Pointer #Udemy_Strings
// #Top_Interview_150_Sliding_Window #Big_O_Time_O(n)_Space_O(1) #AI_can_be_used_to_solve_the_task
// #2024_10_20_Time_15_ms_(29.93%)_Space_9.7_MB_(47.88%)

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(const char* s) {
    int lastIndices[256];
    for (int i = 0; i < 256; i++) {
        lastIndices[i] = -1;
    }

    int maxLen = 0;
    int curLen = 0;
    int start = 0;

    for (int i = 0; i < strlen(s); i++) {
        char cur = s[i];
        if (lastIndices[(unsigned char)cur] < start) {
            lastIndices[(unsigned char)cur] = i;
            curLen++;
        } else {
            int lastIndex = lastIndices[(unsigned char)cur];
            start = lastIndex + 1;
            curLen = i - start + 1;
            lastIndices[(unsigned char)cur] = i;
        }

        if (curLen > maxLen) {
            maxLen = curLen;
        }
    }

    return maxLen;
}
