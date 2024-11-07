// #Hard #Top_100_Liked_Questions #Sorting #Two_Pointers #Design #Heap_Priority_Queue #Data_Stream
// #Big_O_Time_O(n*log_n)_Space_O(n) #2024_11_07_Time_28_ms_(100.00%)_Space_85.9_MB_(78.95%)

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* maxHeap;
    int maxHeapSize;
    int maxHeapCapacity;

    int* minHeap;
    int minHeapSize;
    int minHeapCapacity;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));

    obj->maxHeapCapacity = 10;  // Initial capacity for maxHeap
    obj->maxHeapSize = 0;
    obj->maxHeap = (int*)malloc(obj->maxHeapCapacity * sizeof(int));

    obj->minHeapCapacity = 10;  // Initial capacity for minHeap
    obj->minHeapSize = 0;
    obj->minHeap = (int*)malloc(obj->minHeapCapacity * sizeof(int));

    return obj;
}

// Helper functions for max-heap and min-heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Max-Heap functions
void maxHeapPush(MedianFinder* obj, int value) {
    if (obj->maxHeapSize == obj->maxHeapCapacity) {
        obj->maxHeapCapacity *= 2;
        obj->maxHeap = (int*)realloc(obj->maxHeap, obj->maxHeapCapacity * sizeof(int));
    }
    obj->maxHeap[obj->maxHeapSize++] = value;

    // Sift-up
    int i = obj->maxHeapSize - 1;
    while (i > 0 && obj->maxHeap[(i - 1) / 2] < obj->maxHeap[i]) {
        swap(&obj->maxHeap[(i - 1) / 2], &obj->maxHeap[i]);
        i = (i - 1) / 2;
    }
}

int maxHeapPop(MedianFinder* obj) {
    int result = obj->maxHeap[0];
    obj->maxHeap[0] = obj->maxHeap[--obj->maxHeapSize];

    // Sift-down
    int i = 0;
    while (2 * i + 1 < obj->maxHeapSize) {
        int j = 2 * i + 1;
        if (j + 1 < obj->maxHeapSize && obj->maxHeap[j + 1] > obj->maxHeap[j]) {
            j++;
        }
        if (obj->maxHeap[i] >= obj->maxHeap[j]) break;
        swap(&obj->maxHeap[i], &obj->maxHeap[j]);
        i = j;
    }
    return result;
}

int maxHeapTop(MedianFinder* obj) {
    return obj->maxHeap[0];
}

// Min-Heap functions
void minHeapPush(MedianFinder* obj, int value) {
    if (obj->minHeapSize == obj->minHeapCapacity) {
        obj->minHeapCapacity *= 2;
        obj->minHeap = (int*)realloc(obj->minHeap, obj->minHeapCapacity * sizeof(int));
    }
    obj->minHeap[obj->minHeapSize++] = value;

    // Sift-up
    int i = obj->minHeapSize - 1;
    while (i > 0 && obj->minHeap[(i - 1) / 2] > obj->minHeap[i]) {
        swap(&obj->minHeap[(i - 1) / 2], &obj->minHeap[i]);
        i = (i - 1) / 2;
    }
}

int minHeapPop(MedianFinder* obj) {
    int result = obj->minHeap[0];
    obj->minHeap[0] = obj->minHeap[--obj->minHeapSize];

    // Sift-down
    int i = 0;
    while (2 * i + 1 < obj->minHeapSize) {
        int j = 2 * i + 1;
        if (j + 1 < obj->minHeapSize && obj->minHeap[j + 1] < obj->minHeap[j]) {
            j++;
        }
        if (obj->minHeap[i] <= obj->minHeap[j]) break;
        swap(&obj->minHeap[i], &obj->minHeap[j]);
        i = j;
    }
    return result;
}

int minHeapTop(MedianFinder* obj) {
    return obj->minHeap[0];
}

// Balancing the heaps
void balanceHeaps(MedianFinder* obj) {
    if (obj->maxHeapSize > obj->minHeapSize + 1) {
        minHeapPush(obj, maxHeapPop(obj));
    } else if (obj->minHeapSize > obj->maxHeapSize) {
        maxHeapPush(obj, minHeapPop(obj));
    }
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->maxHeapSize == 0 || num <= maxHeapTop(obj)) {
        maxHeapPush(obj, num);
    } else {
        minHeapPush(obj, num);
    }
    balanceHeaps(obj);
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxHeapSize > obj->minHeapSize) {
        return maxHeapTop(obj);
    } else {
        return (maxHeapTop(obj) + minHeapTop(obj)) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/
