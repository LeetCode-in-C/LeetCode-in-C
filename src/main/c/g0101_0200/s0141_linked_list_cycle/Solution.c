// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Hash_Table #Two_Pointers #Linked_List
// #Data_Structure_I_Day_7_Linked_List #Udemy_Linked_List #Top_Interview_150_Linked_List
// #Big_O_Time_O(N)_Space_O(1) #2024_11_03_Time_6_ms_(92.85%)_Space_11.3_MB_(13.22%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }

    struct ListNode *f = head, *s = head;

    while (f != NULL && f->next != NULL) {
        f = (f->next)->next;
        s = s->next;

        if (f == s) {
            return true;
        }
    }

    return false;
}
