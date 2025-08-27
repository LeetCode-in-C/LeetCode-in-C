// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Breadth_First_Search #Tree
// #Binary_Tree #Data_Structure_I_Day_11_Tree #Level_1_Day_6_Tree #Udemy_Tree_Stack_Queue
// #Top_Interview_150_Binary_Tree_BFS #Big_O_Time_O(N)_Space_O(N)
// #2024_11_02_Time_0_ms_(100.00%)_Space_12.8_MB_(78.13%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
} QueueNode;

struct Queue {
    QueueNode* head;
    QueueNode* tail;
    int size;
};

QueueNode* createQueueNode(struct TreeNode* node);
void enqueue(struct Queue* Queue, struct TreeNode* node);
struct TreeNode* dequeue(struct Queue* Queue);

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** result = malloc(sizeof(int*) * 2000);
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct Queue Queue;
    Queue.head = Queue.tail = NULL;
    Queue.size = 0;
    enqueue(&Queue, root);

    int levelSize = 1, i = 0;
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    while (Queue.size > 0) {
        (*returnColumnSizes)[i] = levelSize;
        result[i] = malloc(sizeof(int) * levelSize);
        for (int j = 0; j < levelSize; j++) {
            struct TreeNode* node = dequeue(&Queue);
            result[i][j] = node->val;
            if (node->left) {
                enqueue(&Queue, node->left);
            }
            if (node->right) {
                enqueue(&Queue, node->right);
            }
        }
        levelSize = Queue.size;
        i++;
    }
    *returnSize = i;
    return result;
}

struct TreeNode* dequeue(struct Queue* Queue) {
    if (Queue->size == 0) {
        return NULL;
    }
    struct TreeNode* node = Queue->head->node;
    QueueNode* temp = Queue->head;
    Queue->head = Queue->head->next;
    Queue->size--;
    free(temp);
    return node;
}

void enqueue(struct Queue* Queue, struct TreeNode* node) {
    QueueNode* newNode = createQueueNode(node);
    if (Queue->size == 0) {
        Queue->head = newNode;
        Queue->tail = newNode;
        Queue->size++;
        return;
    } else {
        Queue->tail->next = newNode;
        Queue->tail = newNode;
        Queue->size++;
        return;
    }
}

QueueNode* createQueueNode(struct TreeNode* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    return newNode;
}
