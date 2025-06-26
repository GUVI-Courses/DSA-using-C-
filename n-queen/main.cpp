#include <iostream>
#include <vector>
using namespace std;

// Function to print the solution
void printSolution(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] == 1 ? "Q " : "_ ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

// Function to solve the N Queens problem using backtracking
bool solveNQueensUtil(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        // All queens are placed successfully
        printSolution(board, n);
        return true;
    }

    bool res = false;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; // Place the queen

            // Recur to place the rest of the queens
            res = solveNQueensUtil(board, row + 1, n) || res;

            board[row][col] = 0; // Backtrack
        }
    }

    return res;
}

// Function to solve the N Queens problem
void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueensUtil(board, 0, n)) {
        cout << "No solution exists for " << n << " queens." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
