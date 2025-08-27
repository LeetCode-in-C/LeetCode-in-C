// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Stack #Design
// #Data_Structure_II_Day_14_Stack_Queue #Programming_Skills_II_Day_18 #Level_2_Day_16_Design
// #Udemy_Design #Top_Interview_150_Stack #Big_O_Time_O(1)_Space_O(N)
// #2024_11_05_Time_0_ms_(100.00%)_Space_18.9_MB_(17.82%)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a node in the stack
typedef struct Node {
    int min;
    int data;
    struct Node* nextNode;
    struct Node* previousNode;
} Node;

// Define the structure for MinStack
typedef struct {
    Node* currentNode;
} MinStack;

// Function to create a new node
Node* createNode(int min, int data, Node* previousNode, Node* nextNode) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->min = min;
    node->data = data;
    node->previousNode = previousNode;
    node->nextNode = nextNode;
    return node;
}

// Initialize MinStack
MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->currentNode = NULL;
    return stack;
}

// Push a value onto the MinStack
void minStackPush(MinStack* obj, int val) {
    if (obj->currentNode == NULL) {
        obj->currentNode = createNode(val, val, NULL, NULL);
    } else {
        obj->currentNode->nextNode = createNode(
            (val < obj->currentNode->min) ? val : obj->currentNode->min, 
            val, 
            obj->currentNode, 
            NULL
        );
        obj->currentNode = obj->currentNode->nextNode;
    }
}

// Pop the top element from the MinStack
void minStackPop(MinStack* obj) {
    if (obj->currentNode != NULL) {
        Node* temp = obj->currentNode;
        obj->currentNode = obj->currentNode->previousNode;
        free(temp);
    }
}

// Get the top element of the MinStack
int minStackTop(MinStack* obj) {
    if (obj->currentNode != NULL) {
        return obj->currentNode->data;
    }
    return INT_MIN; // Or an error code if stack is empty
}

// Get the minimum element in the MinStack
int minStackGetMin(MinStack* obj) {
    if (obj->currentNode != NULL) {
        return obj->currentNode->min;
    }
    return INT_MIN; // Or an error code if stack is empty
}

// Free the MinStack
void minStackFree(MinStack* obj) {
    while (obj->currentNode != NULL) {
        minStackPop(obj);
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
