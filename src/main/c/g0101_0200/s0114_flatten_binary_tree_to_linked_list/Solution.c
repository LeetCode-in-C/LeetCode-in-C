// #Medium #Top_100_Liked_Questions #Depth_First_Search #Tree #Binary_Tree #Stack #Linked_List
// #Udemy_Linked_List #Big_O_Time_O(N)_Space_O(N)
// #2024_11_02_Time_0_ms_(100.00%)_Space_11.3_MB_(25.98%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* flattenAux(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    if ((root->right == NULL) && (root->left == NULL)) {
        return root;
    }

    struct TreeNode *pR = root->right;
    struct TreeNode *pll = NULL;
    struct TreeNode *plr = NULL;

    if (root->left != NULL) {
        root->right = root->left;
        pll = flattenAux(root->left);
        root->left = NULL;
    }

    if (pR != NULL) {
        plr = flattenAux(pR);
    }

    if (pll != NULL) {
        pll->right = pR;
    }

    if (plr != NULL) {
        return plr;
    }

    return pll;
}

void flatten(struct TreeNode* root) {
    flattenAux(root);
}
