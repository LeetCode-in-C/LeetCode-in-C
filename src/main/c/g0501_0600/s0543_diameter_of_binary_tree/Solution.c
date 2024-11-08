// #Easy #Top_100_Liked_Questions #Depth_First_Search #Tree #Binary_Tree #Level_2_Day_7_Tree
// #Udemy_Tree_Stack_Queue #Big_O_Time_O(n)_Space_O(n)
// #2024_11_08_Time_0_ms_(100.00%)_Space_13.5_MB_(94.02%)

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Global variable to store the maximum diameter
int diameter;

// Helper function to calculate the diameter of the binary tree
int diameterOfBinaryTreeUtil(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    // Calculate left and right path lengths
    int leftLength = root->left ? 1 + diameterOfBinaryTreeUtil(root->left) : 0;
    int rightLength = root->right ? 1 + diameterOfBinaryTreeUtil(root->right) : 0;
    
    // Update the diameter if the path through this node is larger
    if (leftLength + rightLength > diameter) {
        diameter = leftLength + rightLength;
    }
    
    // Return the maximum path length from this node
    return leftLength > rightLength ? leftLength : rightLength;
}

// Main function to find the diameter of the binary tree
int diameterOfBinaryTree(struct TreeNode* root) {
    diameter = 0; // Initialize diameter to 0
    diameterOfBinaryTreeUtil(root); // Calculate diameter using the utility function
    return diameter;
}
