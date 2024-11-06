// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Hash_Table #Design #Trie
// #Level_2_Day_16_Design #Udemy_Trie_and_Heap
// #Big_O_Time_O(word.length())_or_O(prefix.length())_Space_O(N)
// #2024_11_06_Time_7_ms_(100.00%)_Space_43.8_MB_(15.88%)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isWord;
} TrieNode;

typedef struct Trie {
    TrieNode* root;
} Trie;

// Helper function to create a new TrieNode
TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    node->isWord = false;
    return node;
}

// Function to create a new Trie
Trie* trieCreate() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->root = createTrieNode();
    return trie;
}

// Function to insert a word into the Trie
void trieInsert(Trie* obj, char* word) {
    TrieNode* node = obj->root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = createTrieNode();
        }
        node = node->children[index];
    }
    node->isWord = true;
}

// Recursive helper function to search for a word or prefix
bool trieSearchHelper(TrieNode* node, char* word, bool checkPrefix) {
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }
    return checkPrefix || node->isWord;
}

// Function to search for a complete word in the Trie
bool trieSearch(Trie* obj, char* word) {
    return trieSearchHelper(obj->root, word, false);
}

// Function to check if any word in the Trie starts with the given prefix
bool trieStartsWith(Trie* obj, char* prefix) {
    return trieSearchHelper(obj->root, prefix, true);
}

// Recursive function to free all TrieNodes
void trieFreeNode(TrieNode* node) {
    if (node == NULL) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        trieFreeNode(node->children[i]);
    }
    free(node);
}

// Function to free the entire Trie
void trieFree(Trie* obj) {
    trieFreeNode(obj->root);
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
