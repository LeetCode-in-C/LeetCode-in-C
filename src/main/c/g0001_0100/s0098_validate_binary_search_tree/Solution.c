// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Depth_First_Search #Tree #Binary_Tree
// #Binary_Search_Tree #Data_Structure_I_Day_14_Tree #Level_1_Day_8_Binary_Search_Tree
// #Udemy_Tree_Stack_Queue #Top_Interview_150_Binary_Search_Tree #Big_O_Time_O(N)_Space_O(log(N))
// #2024_11_02_Time_0_ms_(100.00%)_Space_11.9_MB_(57.64%)

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Helper function to check if the tree is a valid BST
bool solve(struct TreeNode* root, long left, long right) {
    if (root == NULL) {
        return true;
    }
    if (root->val <= left || root->val >= right) {
        return false;
    }
    return solve(root->left, left, root->val) && solve(root->right, root->val, right);
}

// Main function to check if a tree is a valid BST
bool isValidBST(struct TreeNode* root) {
    return solve(root, LONG_MIN, LONG_MAX);
}
