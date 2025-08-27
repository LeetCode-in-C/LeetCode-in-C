// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Hash_Table #Design #Linked_List
// #Doubly_Linked_List #Udemy_Linked_List #Top_Interview_150_Linked_List
// #Big_O_Time_O(1)_Space_O(capacity) #2024_11_03_Time_37_ms_(91.67%)_Space_114.8_MB_(43.55%)

// Define a node in the doubly linked list
typedef struct LRUNode {
    int key;           // Key of the node
    int val;           // Value of the node
    struct LRUNode* prev; // Pointer to the previous node
    struct LRUNode* next; // Pointer to the next node
} LRUNode;

// Define the LRU Cache structure
typedef struct LRUCache {
    int capacity;      // Maximum number of items the cache can hold
    int size;          // Current number of items in the cache
    LRUNode* head;     // Dummy head node of the doubly linked list
    LRUNode* tail;     // Dummy tail node of the doubly linked list
    LRUNode** hash;    // Hash map to store nodes for quick access
} LRUCache;

// Create a new node
LRUNode* createNode(int key, int value) {
    LRUNode* node = (LRUNode*)malloc(sizeof(LRUNode)); // Allocate memory for the new node
    node->key = key;            // Set the key of the node
    node->val = value;          // Set the value of the node
    node->prev = NULL;          // Initialize previous pointer to NULL
    node->next = NULL;          // Initialize next pointer to NULL
    return node;                // Return the newly created node
}

// Initialize the LRU cache
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache)); // Allocate memory for the cache
    cache->capacity = capacity;                           // Set the cache capacity
    cache->size = 0;                                     // Initialize size to 0
    cache->head = createNode(INT_MIN, INT_MIN);          // Create a dummy head node
    cache->tail = createNode(INT_MIN, INT_MIN);          // Create a dummy tail node
    cache->head->next = cache->tail;                     // Set head's next to tail
    cache->tail->prev = cache->head;                     // Set tail's prev to head
    cache->hash = (LRUNode**)calloc(10000, sizeof(LRUNode*)); // Create a hash map (size is 10000 for simplicity)

    return cache; // Return the initialized cache
}

// Remove a node from the doubly linked list
void removeNode(LRUCache* cache, LRUNode* node) {
    node->prev->next = node->next; // Bypass 'node' in the list by linking previous node to next node
    node->next->prev = node->prev; // Bypass 'node' in the list by linking next node to previous node
}

// Add a node right after the dummy head
void addNode(LRUCache* cache, LRUNode* node) {
    node->next = cache->head->next; // Set new node's next pointer to the node currently after the head
    node->prev = cache->head;       // Set new node's prev pointer to the head
    cache->head->next->prev = node; // Update the previous node's prev pointer to the new node
    cache->head->next = node;       // Update the head's next pointer to the new node
}

// Move a node to the head (most recently used)
void moveToHead(LRUCache* cache, LRUNode* node) {
    removeNode(cache, node);  // Remove node from its current position
    addNode(cache, node);    // Add node right after the head
}

// Get the value of the key if it exists
int lRUCacheGet(LRUCache* cache, int key) {
    LRUNode* node = cache->hash[key]; // Retrieve the node from the hash map using the key
    if (node == NULL) {
        return -1; // Return -1 if the key is not found
    }
    moveToHead(cache, node); // Move the accessed node to the head (most recently used)
    return node->val;        // Return the value of the node
}

// Put a key-value pair into the cache
void lRUCachePut(LRUCache* cache, int key, int value) {
    LRUNode* node = cache->hash[key]; // Retrieve the node from the hash map using the key
    if (node != NULL) {
        // If the node exists, update its value and move it to the head
        node->val = value;
        moveToHead(cache, node);
    } else {
        // If the node does not exist
        if (cache->size >= cache->capacity) {
            // If the cache is full, remove the least recently used node
            LRUNode* lru = cache->tail->prev; // The LRU node is just before the tail
            removeNode(cache, lru);           // Remove the LRU node from the list
            cache->hash[lru->key] = NULL;     // Remove the node from the hash map
            free(lru);                        // Free the memory of the removed node
            cache->size--;                    // Decrement the size of the cache
        }
        // Create a new node and add it to the cache
        LRUNode* newNode = createNode(key, value);
        addNode(cache, newNode);          // Add the new node to the head
        cache->hash[key] = newNode;       // Add the new node to the hash map
        cache->size++;                    // Increment the size of the cache
    }
}

// Free the LRU cache and all its nodes
void lRUCacheFree(LRUCache* cache) {
    LRUNode* curr = cache->head->next; // Start from the first real node
    while (curr != cache->tail) {
        LRUNode* next = curr->next; // Store the next node
        free(curr);                // Free the current node
        curr = next;               // Move to the next node
    }
    free(cache->head);   // Free the dummy head node
    free(cache->tail);   // Free the dummy tail node
    free(cache->hash);   // Free the hash map
    free(cache);         // Free the cache structure
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */
