// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Array #Matrix #Backtracking
// #Algorithm_II_Day_11_Recursion_Backtracking #Top_Interview_150_Backtracking
// #Big_O_Time_O(4^(m*n))_Space_O(m*n) #2024_11_02_Time_121_ms_(92.31%)_Space_7.9_MB_(54.94%)

bool dfsb(char **board, int mrow, int mcol, char *word, int crow, int ccol) {
    // This means we are done with search
    if (word[0] == '\0') {
        return true;
    }

    // Out of bound check; search ends in this path
    if (crow < 0 || ccol < 0 || crow >= mrow || ccol >= mcol) {
        return false;
    }

    // Not found; search ends
    if (board[crow][ccol] != word[0]) {
        return false;
    }

    // Mark the cell as visited
    board[crow][ccol] = '.';

    // Check adjacent cells
    if (dfsb(board, mrow, mcol, word + 1, crow, ccol + 1)) return true; // Right
    if (dfsb(board, mrow, mcol, word + 1, crow, ccol - 1)) return true; // Left
    if (dfsb(board, mrow, mcol, word + 1, crow - 1, ccol)) return true; // Up
    if (dfsb(board, mrow, mcol, word + 1, crow + 1, ccol)) return true; // Down

    // Undo marking if no match found
    board[crow][ccol] = word[0];
    return false;
}

bool exist(char **board, int num_rows, int *num_cols, char *word) {
    for (int row = 0; row < num_rows; ++row) {
        for (int col = 0; col < *num_cols; ++col) {
            if (dfsb(board, num_rows, *num_cols, word, row, col)) {
                return true;
            }
        }
    }
    return false;
}
