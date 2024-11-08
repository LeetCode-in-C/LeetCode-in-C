// #Medium #Top_100_Liked_Questions #Array #Hash_Table #Prefix_Sum #Data_Structure_II_Day_5_Array
// #Big_O_Time_O(n)_Space_O(n) #2024_11_08_Time_20_ms_(100.00%)_Space_15.7_MB_(93.15%)

typedef struct Node {
    int val;
    int count;
    struct Node *next;
} Node;

int hash(int val) {
    return (val + 1000001) % 10007;
}

void insert(Node **ht, int val) {
    Node *n;
    int bucket = hash(val);
    if (ht[bucket] != NULL) {
        n = ht[bucket];
        while (n != NULL) {
            if (n->val == val) {
                ++n->count;
                return;
            } else {
                n = n->next;
            }
        }
    }
    n = malloc(sizeof(Node));
    n->val = val;
    n->count = 1;
    n->next = ht[bucket];
    ht[bucket] = n;
}

int occurrences(Node **ht, int val) {
    int bucket = hash(val);
    Node *n = ht[bucket];
    while(n != NULL) {
        if (n->val == val) {
            return n->count;
        }
        n = n->next;
    }
    return 0;
}

int subarraySum(int* nums, int numsSize, int k){
    int i, count, currentCount;
    Node *hashTable[10007] = {NULL};
    count = nums[0] == k;
    insert(hashTable, nums[0]);
    for (i = 1; i < numsSize; ++i) {
        nums[i] += nums[i-1];
        if (nums[i] == k) {
            ++count;
        }
        count += occurrences(hashTable, nums[i]-k);
        insert(hashTable, nums[i]);
    }
    return count;
}
