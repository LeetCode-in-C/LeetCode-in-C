// #Medium #Top_100_Liked_Questions #Depth_First_Search #Tree #Binary_Tree #Binary_Search_Tree
// #Data_Structure_II_Day_17_Tree #Level_2_Day_9_Binary_Search_Tree #Big_O_Time_O(n)_Space_O(n)
// #2024_11_06_Time_0_ms_(100.00%)_Space_13.6_MB_(59.19%)

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

// Helper struct to hold state across recursive calls
struct Solution {
    int k;
    int count;
    int val;
};

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to perform in-order traversal and find the k-th smallest element
void calculate(struct Solution* sol, struct TreeNode* node) {
    if (node == NULL || sol->count >= sol->k) {
        return;
    }

    if (node->left != NULL) {
        calculate(sol, node->left);
    }

    sol->count++;
    if (sol->count == sol->k) {
        sol->val = node->val;
        return;
    }

    if (node->right != NULL) {
        calculate(sol, node->right);
    }
}

// Function to find the k-th smallest element in the BST
int kthSmallest(struct TreeNode* root, int k) {
    struct Solution sol = {k, 0, 0};
    calculate(&sol, root);
    return sol.val;
}

// Helper function to free the tree memory
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
