// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Depth_First_Search #Breadth_First_Search
// #Tree #Binary_Tree #Data_Structure_I_Day_11_Tree #Level_2_Day_15_Tree
// #Big_O_Time_O(N)_Space_O(log(N)) #2024_11_02_Time_0_ms_(100.00%)_Space_9.9_MB_(97.31%)

#include <stdio.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Helper function to check if two subtrees are mirror images
bool helper(struct TreeNode* leftNode, struct TreeNode* rightNode) {
    if (leftNode == NULL || rightNode == NULL) {
        return leftNode == NULL && rightNode == NULL;
    }
    if (leftNode->val != rightNode->val) {
        return false;
    }
    return helper(leftNode->left, rightNode->right) && helper(leftNode->right, rightNode->left);
}

// Main function to check if the tree is symmetric
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return helper(root->left, root->right);
}
