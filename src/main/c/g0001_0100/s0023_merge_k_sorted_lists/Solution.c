// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #Heap_Priority_Queue #Linked_List
// #Divide_and_Conquer #Merge_Sort #Big_O_Time_O(k*n*log(k))_Space_O(log(k))
// #2024_10_29_Time_0_ms_(100.00%)_Space_13.8_MB_(64.94%)

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Function to create a new ListNode
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* left, struct ListNode* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct ListNode* res;
    if (left->val <= right->val) {
        res = left;
        left = left->next;
    } else {
        res = right;
        right = right->next;
    }

    struct ListNode* node = res;
    while (left != NULL || right != NULL) {
        if (left == NULL) {
            node->next = right;
            right = right->next;
        } else if (right == NULL) {
            node->next = left;
            left = left->next;
        } else {
            if (left->val <= right->val) {
                node->next = left;
                left = left->next;
            } else {
                node->next = right;
                right = right->next;
            }
        }
        node = node->next;
    }
    return res;
}

// Recursive function to merge k sorted lists
struct ListNode* mergeKListsHelper(struct ListNode** lists, int leftIndex, int rightIndex) {
    if (rightIndex > leftIndex + 1) {
        int mid = (leftIndex + rightIndex) / 2;
        struct ListNode* left = mergeKListsHelper(lists, leftIndex, mid);
        struct ListNode* right = mergeKListsHelper(lists, mid, rightIndex);
        return mergeTwoLists(left, right);
    } else {
        return lists[leftIndex];
    }
}

// Function to initiate mergeKLists with bounds
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    return mergeKListsHelper(lists, 0, listsSize);
}
