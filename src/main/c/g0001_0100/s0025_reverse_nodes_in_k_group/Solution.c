// #Hard #Top_100_Liked_Questions #Linked_List #Recursion #Data_Structure_II_Day_13_Linked_List
// #Udemy_Linked_List #Top_Interview_150_Linked_List #Big_O_Time_O(n)_Space_O(k)
// #2024_10_29_Time_0_ms_(100.00%)_Space_11.6_MB_(10.40%)

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

// Function to reverse nodes in groups of k
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 1) {
        return head;
    }

    // Check if there are at least k nodes remaining
    struct ListNode* len = head;
    int j = 0;
    while (j < k) {
        if (len == NULL) {
            return head;
        }
        len = len->next;
        j++;
    }

    // Reverse the first k nodes
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    int i = 0;
    while (i < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }

    // Recursively call for the next group of k nodes
    head->next = reverseKGroup(next, k);
    return prev;
}
