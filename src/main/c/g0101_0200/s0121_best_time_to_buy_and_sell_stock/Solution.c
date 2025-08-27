// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Array #Dynamic_Programming
// #Data_Structure_I_Day_3_Array #Dynamic_Programming_I_Day_7 #Level_1_Day_5_Greedy #Udemy_Arrays
// #Top_Interview_150_Array/String #Big_O_Time_O(N)_Space_O(1)
// #2024_11_03_Time_0_ms_(100.00%)_Space_15.1_MB_(71.35%)

#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int maxProfit = 0;
    int min = prices[0];

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > min) {
            int profit = prices[i] - min;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        } else {
            min = prices[i];
        }
    }

    return maxProfit;
}
