// #Hard #Top_100_Liked_Questions #Array #Heap_Priority_Queue #Sliding_Window #Queue
// #Monotonic_Queue #Udemy_Arrays #Big_O_Time_O(n*k)_Space_O(n+k)
// #2024_11_06_Time_4_ms_(95.24%)_Space_94_MB_(14.29%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }

    int *queue = malloc(sizeof(int) * numsSize);
    int *res = malloc(sizeof(int) * (numsSize - k + 1));
    int rear = -1;
    int qLen = 0;
    int front = 0;
    int i = 0;
    int resCount = 0;

    for (i = 0; i < numsSize; i++) {
        // Remove elements that are out of the window
        while (qLen > 0 && i - queue[front] >= k) {
            front++;
            qLen--;
        }

        // Remove elements from the back of the queue that are less than the current element
        while (qLen > 0 && nums[i] > nums[queue[rear]]) {
            rear--;
            qLen--;
        }

        // Add the current element index to the queue
        queue[++rear] = i;
        qLen++;

        // Once we have a complete window, add the maximum element (from the front of the queue) to the result
        if (i >= k - 1) {
            res[resCount++] = nums[queue[front]];
        }
    }

    *returnSize = resCount;
    return res;
}
