// #Easy #Top_100_Liked_Questions #Top_Interview_Questions #Depth_First_Search #Tree #Binary_Tree
// #Stack #Data_Structure_I_Day_10_Tree #Udemy_Tree_Stack_Queue #Big_O_Time_O(n)_Space_O(n)
// #2024_11_02_Time_0_ms_(100.00%)_Space_8.5_MB_(62.85%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define INIT_STACK_CAPACITY 2
#define EMPTY_INDEX -1

typedef struct stack {
    int topIndex;
    int capacity;
    struct TreeNode** datas;
} Stack;

Stack* createStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->topIndex = EMPTY_INDEX;
    s->capacity = INIT_STACK_CAPACITY;
    s->datas = (struct TreeNode**)malloc(s->capacity * sizeof(struct TreeNode*));
    for (int i = 0; i < s->capacity; i++) {
        s->datas[i] = NULL;
    }
    return s;
}

bool isFullStack(Stack *s) {
    return(s->topIndex >= (s->capacity - 1));
}

bool isEmptyStack(Stack *s) {
    return(s->topIndex == EMPTY_INDEX);
}

void push(Stack *s, struct TreeNode* node) {
    if (isFullStack(s)) {
        s->capacity *= 2;
        s->datas = (struct TreeNode**)realloc(s->datas, s->capacity * sizeof(struct TreeNode*));
        for (int i = (s->topIndex + 1); i < s->capacity; i++) {
            s->datas[i] = NULL;
        }
    }
    s->datas[++(s->topIndex)] = node;
}

struct TreeNode* pop(Stack* s) {
    if (isEmptyStack(s)) {
        return NULL;
    }
    return s->datas[s->topIndex--];
}

struct TreeNode* top(Stack* s) {
    if (isEmptyStack(s)) {
        return NULL;
    }
    return s->datas[s->topIndex];
}

int size(Stack* s) {
    return s->topIndex + 1;
}

void freeStack(Stack* s) {
    for (int i = 0; i < s->capacity; i++) {
        free(s->datas[i]);
    }
    free(s->datas);
    free(s);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    Stack *s = createStack();
    *returnSize = 0;
    int* ans = (int*)malloc(200*sizeof(int));

    while (root || !isEmptyStack(s)) {
        if (root) {
            push(s, root);
            root = root->left;
        } else {
            root = pop(s);
            ans[(*returnSize)++] = root->val;
            root = root->right;
        }
    }
    
    freeStack(s);
    ans = (int*)realloc(ans, *returnSize * sizeof(int));
    return ans;
}
