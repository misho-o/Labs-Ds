#include <iostream>
#include <vector>
using namespace std;

int solutionCount = 0;

// Check if it's safe to place queen
bool isSafe(vector<string>& board, int row, int col, int n) {

    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

// Print board
void printBoard(vector<string>& board) {
    for (auto row : board) {
        cout << row << endl;
    }
    cout << "-------------------\n";
}

// Backtracking function
void solve(vector<string>& board, int row, int n) {
    if (solutionCount == 2) return;  // stop after 2 solutions

    // Base case: all queens placed
    if (row == n) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        printBoard(board);
        return;
    }

    // Try placing queen in each column
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';   // place queen

            solve(board, row + 1, n);

            board[row][col] = '.';   // backtrack
        }
    }
}

int main() {
    int n = 4;  // You can change N here

    vector<string> board(n, string(n, '.'));

    solve(board, 0, n);

    return 0;
}