#include <iostream>
#include <vector>

using namespace std;

// Function to print the chessboard
void printChessboard(const vector<vector<char>>& chessboard) {
    for (const vector<char>& row : chessboard) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a queen at (row, col)
bool isSafe(const vector<vector<char>>& chessboard, int row, int col, int N) {
    // Check the left side of the current column
    for (int i = 0; i < row; i++) {
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(vector<vector<char>>& chessboard, int row, int N) {
    if (row == N) {
        // All queens are successfully placed, print the solution
        printChessboard(chessboard);
        cout << endl;
        return true;
    }

    bool foundSolution = false;

    for (int col = 0; col < N; col++) {
        if (isSafe(chessboard, row, col, N)) {
            chessboard[row][col] = 'Q';  // Place a queen
            foundSolution = solveNQueens(chessboard, row + 1, N) || foundSolution;
            chessboard[row][col] = '.';  // Backtrack (remove the queen)
        }
    }

    return foundSolution;
}

// Function to solve the N-Queens problem for a given board size N
void solveNQueens(int N) {
    vector<vector<char>> chessboard(N, vector<char>(N, '.'));

    if (!solveNQueens(chessboard, 0, N)) {
        cout << "No solution found for N = " << N << endl;
    }
}

int main() {
    int N;
    cout << "Enter the board size N for the N-Queens problem: ";
    cin >> N;

    solveNQueens(N);

    return 0;
}
