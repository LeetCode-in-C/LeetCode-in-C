// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #Array #Stack #Monotonic_Stack
// #Big_O_Time_O(n_log_n)_Space_O(log_n) #2024_11_02_Time_7_ms_(86.96%)_Space_14.4_MB_(94.96%)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxOfThreeNums(int a, int b, int c) {
    return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}

int findMinInArray(int* a, int start, int limit) {
    int min = __INT_MAX__;
    int minIndex = -1;
    for (int index = start; index < limit; index++) {
        if (a[index] < min) {
            min = a[index];
            minIndex = index;
        }
    }
    return minIndex;
}

bool checkIfSorted(int* a, int start, int limit) {
    for (int i = start + 1; i < limit; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

int largestArea(int* a, int start, int limit) {
    if (a == NULL || limit == 0) {
        return 0;
    }
    if (start == limit) {
        return 0;
    }
    if (limit - start == 1) {
        return a[start];
    }
    if (limit - start == 2) {
        int maxOfTwoBars = (a[start] > a[start + 1]) ? a[start] : a[start + 1];
        int areaFromTwo = (a[start] < a[start + 1] ? a[start] : a[start + 1]) * 2;
        return (maxOfTwoBars > areaFromTwo) ? maxOfTwoBars : areaFromTwo;
    }
    if (checkIfSorted(a, start, limit)) {
        int maxWhenSorted = 0;
        for (int i = start; i < limit; i++) {
            int area = a[i] * (limit - i);
            if (area > maxWhenSorted) {
                maxWhenSorted = area;
            }
        }
        return maxWhenSorted;
    } else {
        int minInd = findMinInArray(a, start, limit);
        return maxOfThreeNums(
            largestArea(a, start, minInd),
            a[minInd] * (limit - start),
            largestArea(a, minInd + 1, limit)
        );
    }
}

int largestRectangleArea(int* heights, int length) {
    return largestArea(heights, 0, length);
}
