// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Linked_List #Recursion
// #Data_Structure_I_Day_7_Linked_List #Algorithm_I_Day_10_Recursion_Backtracking
// #Level_1_Day_3_Linked_List #Udemy_Linked_List #Top_Interview_150_Linked_List
// #Big_O_Time_O(m+n)_Space_O(m+n) #2024_10_29_Time_0_ms_(100.00%)_Space_10.7_MB_(26.00%)

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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy = {-1, NULL};  // Dummy head node
    struct ListNode* list = &dummy;      // Pointer to the dummy node

    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                list->next = createNode(l1->val);
                l1 = l1->next;
            } else {
                list->next = createNode(l2->val);
                l2 = l2->next;
            }
        } else if (l1 != NULL) {
            list->next = createNode(l1->val);
            l1 = l1->next;
        } else {
            list->next = createNode(l2->val);
            l2 = l2->next;
        }
        list = list->next;
    }

    return dummy.next;  // Return the merged list starting from dummy's next node
}
