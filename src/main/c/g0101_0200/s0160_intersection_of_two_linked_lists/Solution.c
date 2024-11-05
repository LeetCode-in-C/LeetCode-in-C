// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Hash_Table #Two_Pointers #Linked_List
// #Data_Structure_II_Day_11_Linked_List #Udemy_Linked_List #Big_O_Time_O(M+N)_Space_O(1)
// #2024_11_05_Time_33_ms_(78.91%)_Space_17_MB_(92.33%)

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Function to find the intersection node of two linked lists
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* node1 = headA;
    struct ListNode* node2 = headB;
    
    // Loop until the two pointers meet at the intersection or both become NULL
    while (node1 != node2) {
        // If node1 reaches the end of list A, switch to the head of list B
        node1 = (node1 == NULL) ? headB : node1->next;
        // If node2 reaches the end of list B, switch to the head of list A
        node2 = (node2 == NULL) ? headA : node2->next;
    }
    
    // Both pointers will either meet at the intersection node or at NULL if no intersection exists
    return node1;
}
