// #Medium #Top_100_Liked_Questions #Linked_List #Recursion #Data_Structure_II_Day_12_Linked_List
// #Udemy_Linked_List #Big_O_Time_O(n)_Space_O(1)
// #2024_10_29_Time_0_ms_(100.00%)_Space_8.9_MB_(27.56%)

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

// Function to calculate the length of the linked list
int getLength(struct ListNode* curr) {
    int cnt = 0;
    while (curr != NULL) {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

// Recursive function to reverse nodes in pairs
struct ListNode* reverse(struct ListNode* head, int len) {
    // Base case: if there are less than 2 nodes, return the head
    if (len < 2) {
        return head;
    }

    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* next;

    // Reverse the first 2 nodes
    for (int i = 0; i < 2; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Set the next pointer of the last node in the reversed pair to the result of the next reverse call
    head->next = reverse(curr, len - 2);

    return prev;
}

// Main function to swap nodes in pairs
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    int len = getLength(head);
    return reverse(head, len);
}
