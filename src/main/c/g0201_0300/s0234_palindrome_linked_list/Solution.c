// #Easy #Top_100_Liked_Questions #Two_Pointers #Stack #Linked_List #Recursion
// #Level_2_Day_3_Linked_List #Udemy_Linked_List #Big_O_Time_O(n)_Space_O(1)
// #2024_11_06_Time_0_ms_(100.00%)_Space_44.8_MB_(40.09%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdbool.h>

// Function to check if the linked list is a palindrome
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // Step 1: Calculate the length of the list
    int len = 0;
    struct ListNode* right = head;
    while (right != NULL) {
        right = right->next;
        len++;
    }

    // Step 2: Find the middle of the list and reverse the right half
    len = len / 2;
    right = head;
    for (int i = 0; i < len; i++) {
        right = right->next;
    }

    // Reverse the right half of the list
    struct ListNode* prev = NULL;
    while (right != NULL) {
        struct ListNode* next = right->next;
        right->next = prev;
        prev = right;
        right = next;
    }

    // Step 3: Compare the left half and the reversed right half
    struct ListNode* left = head;
    while (prev != NULL) {
        if (left->val != prev->val) {
            return false;
        }
        left = left->next;
        prev = prev->next;
    }

    return true;
}
