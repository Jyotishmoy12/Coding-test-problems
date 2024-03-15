Given a non-negative integer 2D matrix in which 0 means obstacle so no one can step on it and positive integer means the amount of gold. Find the maximum amount of gold you can collect. (You can start from any point you want.)

Integers in the input matrix does not form a cycle. For example, there is no matrix like the following:

maze = [
[1,2]
[3,4]
]
From each cell, you can either move to four directions: left, right, up or down. You CANNOT move diagonally or move outside of the boundary or step on the cell whose value is 0. In addition, you CANNOT move back to where your come from. For example, we are now at maze[0][0], we go right to maze[0][1]. Then we CANNOT go back to maze[0][0].

Example:

maze = [
[0, 1, 0, 3, 4]
[2, 2, 0, 7, 0]
[0, 4, 5, 6, 2]
[0, 0, 0, 0, 0]
[0, 2, 0, 0, 2]
]
Return 33
The path is 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 3 -> 4 by which we can get 33 golds and this is the maximum amount.

class Solution {
    int dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || visited[row][col])
        return 0;

    visited[row][col] = true;
    int gold = grid[row][col];
    int maxGold = gold;

    maxGold += max({dfs(grid, row + 1, col, visited), dfs(grid, row - 1, col, visited),
                    dfs(grid, row, col + 1, visited), dfs(grid, row, col - 1, visited)});

    visited[row][col] = false; // Backtrack

    return maxGold;
}

public:
    int getMaximumGold(vector<vector<int>>& grid) {
     int maxGold = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] != 0) {
                maxGold = max(maxGold, dfs(grid, i, j, visited));
            }
        }
    }

    return maxGold;
    }
};
