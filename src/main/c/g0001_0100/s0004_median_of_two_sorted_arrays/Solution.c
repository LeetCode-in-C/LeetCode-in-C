// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #Array #Binary_Search #Divide_and_Conquer
// #Big_O_Time_O(log(min(N,M)))_Space_O(1) #2024_10_20_Time_0_ms_(100.00%)_Space_11.1_MB_(60.94%)

#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int n1, int* nums2, int n2) {
    if (n1 > n2) {
        return findMedianSortedArrays(nums2, n2, nums1, n1);
    }

    int low = 0, high = n1;
    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            if ((n1 + n2) % 2 == 0) {
                return (double)(fmax(l1, l2) + fmin(r1, r2)) / 2.0;
            } else {
                return (double)fmax(l1, l2);
            }
        } else if (l1 > r2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 0.0;
}
