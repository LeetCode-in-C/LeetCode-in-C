// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Depth_First_Search
// #Breadth_First_Search #Matrix #Union_Find
// #Algorithm_II_Day_6_Breadth_First_Search_Depth_First_Search
// #Graph_Theory_I_Day_1_Matrix_Related_Problems #Level_1_Day_9_Graph/BFS/DFS #Udemy_Graph
// #Top_Interview_150_Graph_General #Big_O_Time_O(M*N)_Space_O(M*N)
// #2024_11_05_Time_14_ms_(96.18%)_Space_11.7_MB_(59.93%)

void DFS(int row, int col, int m, int n, char** grid) {
    if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0') {
        return;
    }

    grid[row][col] = '0'; // Mark the current cell as visited

    // Visit the neighboring cells
    DFS(row + 1, col, m, n, grid);
    DFS(row - 1, col, m, n, grid);
    DFS(row, col + 1, m, n, grid);
    DFS(row, col - 1, m, n, grid);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) {
        return 0;
    }

    int m = gridSize;  // ROW
    int n = *gridColSize; // COL
    int numIslands = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {  // grid[row][col]
                numIslands++;
                DFS(i, j, m, n, grid);
            }
        }
    }

    return numIslands;
}
