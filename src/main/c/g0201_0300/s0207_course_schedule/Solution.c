// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Depth_First_Search
// #Breadth_First_Search #Graph #Topological_Sort #Big_O_Time_O(N)_Space_O(N)
// #2024_11_06_Time_0_ms_(100.00%)_Space_11.5_MB_(87.84%)

typedef struct node {
    int V;
    struct node* next;
} node;

bool dfs(node** adjlist, bool* visited, bool* recStack, int current);

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    node** adjlist = malloc(sizeof(node*) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        adjlist[i] = NULL;
    }
    for (int i = 0; i < prerequisitesSize; i++) {
        node* Node = malloc(sizeof(node));
        Node->V = prerequisites[i][0];
        Node->next = adjlist[prerequisites[i][1]];
        adjlist[prerequisites[i][1]] = Node;
    }

    bool* visited = calloc(sizeof(bool), numCourses);
    bool* recStack = calloc(sizeof(bool), numCourses);

    for (int V = 0; V < numCourses; V++) {
        if (dfs(adjlist, visited, recStack, V)) {
            return false;
        }
    }
    return true;
}

bool dfs(node** adjlist, bool* visited, bool* recStack, int current) {
    if (recStack[current]) {
        return true;
    }
    if (visited[current]) {
        return false;
    }
    visited[current] = true;
    recStack[current] = true;

    for (node* Node = adjlist[current]; Node; Node = Node->next) {
        if (dfs(adjlist, visited, recStack, Node->V)) {
            return true;
        }
    }

    recStack[current] = false;
    return false;
}
