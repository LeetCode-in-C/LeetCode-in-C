// #Medium #Depth_First_Search #Tree #Binary_Tree #Level_2_Day_7_Tree #Big_O_Time_O(n)_Space_O(n)
// #2024_11_08_Time_6_ms_(96.00%)_Space_11.6_MB_(88.00%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TD;

long int psWorkHorse1(TD *root, long int targetSum) {
  long int sum = (root->val == targetSum) ? 1 : 0;
  if (root->left) {
    sum = sum + psWorkHorse1(root->left, targetSum - root->val);
  }
  if (root->right) {
    sum = sum + psWorkHorse1(root->right, targetSum - root->val);
  }

  return sum;
}
int pathSum(struct TreeNode *root, int targetSum) {
  if (!root)
    return 0;
  else {
    long int sum = psWorkHorse1(root, targetSum);
    if (root->left) {
      sum += pathSum(root->left, targetSum);
    }
    if (root->right) {
      sum += pathSum(root->right, targetSum);
    }
    return sum;
  }
}
