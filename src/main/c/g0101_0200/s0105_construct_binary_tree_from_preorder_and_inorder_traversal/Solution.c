// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Hash_Table #Tree #Binary_Tree
// #Divide_and_Conquer #Data_Structure_II_Day_15_Tree #Big_O_Time_O(N)_Space_O(N)
// #2024_11_02_Time_3_ms_(95.24%)_Space_14_MB_(86.50%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize == 0) return NULL;

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node -> val = *preorder;

    int index;
    for(index = 0; *(inorder + index) != node -> val; index++);

    // build left part
    preorder++;
    node -> left = buildTree(preorder, index, inorder, index);

    // move index
    preorder = preorder + index;
    inorder = inorder + index + 1;
    index = preorderSize - index - 1;

    // build right part
    node -> right = buildTree(preorder, index, inorder, index);
    return node;
}
