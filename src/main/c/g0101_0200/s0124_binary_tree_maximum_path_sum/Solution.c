// #Hard #Top_100_Liked_Questions #Top_Interview_Questions #Dynamic_Programming #Depth_First_Search
// #Tree #Binary_Tree #Udemy_Tree_Stack_Queue #Top_Interview_150_Binary_Tree_General
// #Big_O_Time_O(N)_Space_O(N) #2024_11_03_Time_0_ms_(100.00%)_Space_16.8_MB_(63.02%)

#include <stdio.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Initialize max to a very low value
int max = INT_MIN;

int helper(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // Recursively get the maximum path sum for left and right subtrees
    int left = helper(root->left);
    int right = helper(root->right);

    // Ensure negative values are replaced by 0
    left = (left > 0) ? left : 0;
    right = (right > 0) ? right : 0;

    // Calculate the current maximum path sum through this node
    int current = root->val + left + right;

    // Update global max if current is greater
    if (current > max) {
        max = current;
    }

    // Return the maximum path sum including this node and one of its subtrees
    return root->val + ((left > right) ? left : right);
}

int maxPathSum(struct TreeNode* root) {
    max = INT_MIN;  // Reset max for each function call
    helper(root);
    return max;
}

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
