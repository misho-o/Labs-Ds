#include <iostream>
#include <vector>
using namespace std;

int n;

// Check if move is valid
bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && y >= 0 && x < n && y < n &&
            maze[x][y] == 1 && !visited[x][y]);
}

// Backtracking function
void solve(int x, int y,
           vector<vector<int>>& maze,
           vector<vector<bool>>& visited,
           string path) {

    // Base case: reached destination
    if (x == n - 1 && y == n - 1) {
        cout << path << endl;
        return;
    }

    visited[x][y] = true;

    // Move Down
    if (isSafe(x + 1, y, maze, visited))
        solve(x + 1, y, maze, visited, path + "D");

    // Move Right
    if (isSafe(x, y + 1, maze, visited))
        solve(x, y + 1, maze, visited, path + "R");

    // Move Up
    if (isSafe(x - 1, y, maze, visited))
        solve(x - 1, y, maze, visited, path + "U");

    // Move Left
    if (isSafe(x, y - 1, maze, visited))
        solve(x, y - 1, maze, visited, path + "L");

    // Backtrack
    visited[x][y] = false;
}

int main() {
    n = 4;

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    if (maze[0][0] == 1)
        solve(0, 0, maze, visited, "");

    return 0;
}