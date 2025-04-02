#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int currentPlayer = 1;
char mark;

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "-----------\n";
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void makeMove(int position) {
    char symbol = (currentPlayer == 1) ? 'X' : 'O';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == position + '0') {
                board[i][j] = symbol;
                return;
            }
        }
    }
}

bool isValidMove(int position) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == position + '0') return true;
        }
    }
    return false;
}

int main() {
    int position;
    while (true) {
        displayBoard();
        cout << "\nPlayer " << currentPlayer << " (" << ((currentPlayer == 1) ? 'X' : 'O') << "), enter position: ";
        cin >> position;
        
        if (!isValidMove(position)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        
        makeMove(position);
        
        if (checkWin()) {
            displayBoard();
            cout << "\nPlayer " << currentPlayer << " wins!\n";
            break;
        }
        
        if (isDraw()) {
            displayBoard();
            cout << "\nIt's a draw!\n";
            break;
        }
        
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    return 0;
}
