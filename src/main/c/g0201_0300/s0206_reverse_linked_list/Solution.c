// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Linked_List #Recursion
// #Data_Structure_I_Day_8_Linked_List #Algorithm_I_Day_10_Recursion_Backtracking
// #Level_1_Day_3_Linked_List #Udemy_Linked_List #Big_O_Time_O(N)_Space_O(1)
// #2024_11_05_Time_0_ms_(100.00%)_Space_10.6_MB_(53.47%)

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;   // Pointer to the previous node
    struct ListNode* curr = head;    // Pointer to the current node
    
    while (curr != NULL) {
        struct ListNode* next = curr->next; // Store the next node
        curr->next = prev;                  // Reverse the current node's pointer
        prev = curr;                        // Move prev to the current node
        curr = next;                        // Move to the next node
    }
    
    return prev; // New head of the reversed list
}
