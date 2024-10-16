// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Math #Linked_List #Recursion
// #Data_Structure_II_Day_10_Linked_List #Programming_Skills_II_Day_15
// #Big_O_Time_O(max(N,M))_Space_O(max(N,M)) #AI_can_be_used_to_solve_the_task
// #2024_10_16_Time_12_ms_(70.50%)_Space_12.6_MB_(56.73%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Function to create a new ListNode
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummyHead;
    dummyHead.val = 0;
    dummyHead.next = NULL;
    
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    struct ListNode* curr = &dummyHead;
    int carry = 0;

    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;

        curr->next = createNode(sum % 10);
        curr = curr->next;

        if (p != NULL) {
            p = p->next;
        }
        if (q != NULL) {
            q = q->next;
        }
    }

    if (carry > 0) {
        curr->next = createNode(carry);
    }

    return dummyHead.next;
}
