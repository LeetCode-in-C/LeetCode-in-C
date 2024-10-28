// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Two_Pointers #Linked_List
// #Algorithm_I_Day_5_Two_Pointers #Level_2_Day_3_Linked_List #Big_O_Time_O(L)_Space_O(L)
// #2024_10_28_Time_0_ms_(100.00%)_Space_9.4_MB_(39.50%)

#include <stdio.h>
#include <stdlib.h>

struct Solution {
    int n;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct Solution solution;
    solution.n = n;
    
    // Create a new dummy node pointing to the head
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0; // Value is not important for dummy
    dummy->next = head;
    
    // Call the recursive function to remove the Nth node
    removeNth(dummy, &solution);
    
    // Store the new head and free the dummy node
    struct ListNode* newHead = dummy->next;
    free(dummy);
    
    return newHead;
}

void removeNth(struct ListNode* node, struct Solution* solution) {
    if (node->next == NULL) {
        return; // Base case
    }
    
    removeNth(node->next, solution);
    solution->n--;

    if (solution->n == 0) {
        struct ListNode* toDelete = node->next; // Node to be deleted
        node->next = node->next->next; // Skip the node
        free(toDelete); // Free the memory of the deleted node
    }
}

// Function to create a new ListNode
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}
