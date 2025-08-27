// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table #Sorting #Counting
// #Divide_and_Conquer #Data_Structure_II_Day_1_Array #Udemy_Famous_Algorithm
// #Top_Interview_150_Array/String #Big_O_Time_O(n)_Space_O(1)
// #2024_11_05_Time_0_ms_(100.00%)_Space_10.3_MB_(31.00%)

#include <stdio.h>

// Function to find the majority element in an array
int majorityElement(int* arr, int arrSize) {
    int count = 1;
    int majority = arr[0];
    
    // First pass to find a potential majority element using Boyer-Moore Voting Algorithm
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] == majority) {
            count++;
        } else {
            if (count > 1) {
                count--;
            } else {
                majority = arr[i];
                count = 1;
            }
        }
    }

    // Second pass to confirm if the candidate is indeed the majority element
    count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == majority) {
            count++;
        }
    }

    // Check if the majority element appears more than n/2 times
    if (count >= (arrSize / 2) + 1) {
        return majority;
    } else {
        return -1;
    }
}
