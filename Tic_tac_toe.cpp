#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    cout << "     0   1   2\n";
    cout << "   -------------\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << i << " |";
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " |";
        }
        cout << "\n   -------------\n";
    }
}

bool isWinner(const vector<vector<char>>& board, char player) {
    // Check rows, columns and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void ticTacToeGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameEnded = false;

    while (!gameEnded) {
        printBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter row and column (0, 1, or 2): ";
        cin >> row >> col;

        // Check for valid input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move, try again.\n";
            continue;
        }

        // Update board
        board[row][col] = currentPlayer;

        // Check for win or draw
        if (isWinner(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameEnded = true;
        } else if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            gameEnded = true;
        } else {
            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        ticTacToeGame();
        cout << "Play again? (y/n): ";
        cin >> playAgain;
    }
    return 0;
}