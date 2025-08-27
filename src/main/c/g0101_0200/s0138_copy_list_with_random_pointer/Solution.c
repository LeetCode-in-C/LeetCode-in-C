// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Hash_Table #Linked_List
// #Programming_Skills_II_Day_14 #Udemy_Linked_List #Top_Interview_150_Linked_List
// #Big_O_Time_O(N)_Space_O(N) #2024_11_03_Time_4_ms_(91.18%)_Space_14.2_MB_(54.40%)

#include <stdlib.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

// Helper function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    // First pass: Insert cloned nodes right after each original node.
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* clonedNode = createNode(curr->val);
        clonedNode->next = curr->next;
        curr->next = clonedNode;
        curr = clonedNode->next;
    }

    // Second pass: Set random pointers for cloned nodes.
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Third pass: Separate the original list and cloned list.
    curr = head;
    struct Node* newHead = head->next;
    while (curr != NULL) {
        struct Node* clonedNode = curr->next;
        curr->next = clonedNode->next;
        if (clonedNode->next != NULL) {
            clonedNode->next = clonedNode->next->next;
        }
        curr = curr->next;
    }

    return newHead;
}
