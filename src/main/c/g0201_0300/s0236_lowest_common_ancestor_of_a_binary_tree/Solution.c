// #Medium #Top_100_Liked_Questions #Depth_First_Search #Tree #Binary_Tree
// #Data_Structure_II_Day_18_Tree #Udemy_Tree_Stack_Queue #Big_O_Time_O(n)_Space_O(n)
// #2024_11_06_Time_15_ms_(90.08%)_Space_21.1_MB_(76.15%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

// Function to find the lowest common ancestor of two nodes in the binary tree
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // Base case: if the root is NULL or root matches either p or q
    if (root == NULL || root == p || root == q) {
        return root;
    }

    // Recursively find the LCA in the left and right subtrees
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both left and right are non-null, the current root is the LCA
    if (left != NULL && right != NULL) {
        return root;
    }

    // Otherwise, return the non-null child (if both are NULL, return NULL)
    return left != NULL ? left : right;
}
