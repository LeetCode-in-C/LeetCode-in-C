// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Hash_Table
// #Dynamic_Programming #Trie #Memoization #Algorithm_II_Day_15_Dynamic_Programming
// #Dynamic_Programming_I_Day_9 #Udemy_Dynamic_Programming #Top_Interview_150_1D_DP
// #Big_O_Time_O(M+max*N)_Space_O(M+N+max) #2024_11_03_Time_0_ms_(100.00%)_Space_8.3_MB_(26.03%)

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    bool dp[strlen(s)+1];
    memset(dp,false,sizeof(dp));
    dp[strlen(s)] = true;

    for (int i = strlen(s)-1; i >= 0; i--) {
        for (int j = 0; j < wordDictSize; j++) {
            if (i+strlen(wordDict[j]) <= strlen(s)) {
                char string[20] = "\0";
                for (int k = 0; k < strlen(wordDict[j]); k++) {
                    string[k] = s[i+k];
                }
                if (strcmp(wordDict[j], string) == 0) {
                    dp[i] = dp[i+strlen(wordDict[j])];
                }
                if (dp[i] == true) {
                    break;
                }
            }
        }
    }
    return dp[0];
}
