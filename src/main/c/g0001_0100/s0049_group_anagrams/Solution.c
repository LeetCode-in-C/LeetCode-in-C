// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #String #Hash_Table #Sorting
// #Data_Structure_II_Day_8_String #Programming_Skills_II_Day_11 #Udemy_Strings
// #Top_Interview_150_Hashmap #Big_O_Time_O(n*k_log_k)_Space_O(n)
// #2024_10_30_Time_3_ms_(100.00%)_Space_17.8_MB_(93.04%)


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
const char primes[26] = {
    2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101
};

typedef struct node {
    char** str;
    int size;
    int cap;
    double val;
    struct node* left;
    struct node* right;
    struct node* next;
} node;

void insert(node** data, const char* str, const int bucket, node** first, node** last, int* returnSize) {
    double val = 1;
    const char* c = str;
    while (*c) {
        val *= primes[*c++ - 'a'];
    }
    node** branch = &data[(int)fmod(val, bucket)];

    while (*branch) {
        if ((*branch)->val < val) {
            branch = &((*branch)->left);
        } else if (val < (*branch)->val) {
            branch = &((*branch)->right);
        } else {
            if ((*branch)->size == (*branch)->cap) {
                (*branch)->cap *= 4;
                (*branch)->str = (char**)realloc((*branch)->str, (*branch)->cap * sizeof(char*));
            }
            (*branch)->str[(*branch)->size++] = (char*)str;
            return;
        }
    }

    ++(*returnSize);
    *branch = (node*)malloc(sizeof(node));
    (*branch)->size = 1;
    (*branch)->cap = 2;
    (*branch)->val = val;
    (*branch)->left = NULL;
    (*branch)->right = NULL;
    (*branch)->str = (char**)malloc(sizeof(char*) * (*branch)->cap);

    if (*first) {
        (*last)->next = *branch;
    } else {
        *first = *branch;
    }
    *last = *branch;
    (*branch)->str[0] = (char*)str;
}

char*** groupAnagrams(const char** strs, const int strsSize, int* returnSize, int** returnColumnSizes) {
    node** data = (node**)malloc(sizeof(node*) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        data[i] = NULL;
    }

    node* ptr = NULL;
    node* last = NULL;
    *returnSize = 0;
    for (int i = 0; i < strsSize; i++) {
        insert(data, strs[i], strsSize, &ptr, &last, returnSize);
    }

    char*** result = (char***)malloc(sizeof(char**) * (*returnSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));

    for (int i = 0; i < *returnSize; i++) {
        last = ptr;
        (*returnColumnSizes)[i] = ptr->size;
        result[i] = ptr->str;
        ptr = ptr->next;
        free(last);
    }

    free(data);
    return result;
}
