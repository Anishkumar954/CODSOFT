#include <iostream>

using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "Current Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "-----------\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] == ' ') {  // Ensures empty slots only
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

bool checkWin() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return true;

    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return true;

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';  // Start with empty spaces
}

void playGame() {
    resetBoard();
    currentPlayer = 1;
    currentMarker = 'X';
    bool gameOn = true;

    while (gameOn) {
        drawBoard();
        int slot;
        cout << "Player " << currentPlayer << " (" << currentMarker << ") - Enter your move (1-9): ";
        cin >> slot;

        while (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move. Try again: ";
            cin >> slot;
        }

        if (checkWin()) {
            drawBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOn = false;
        } else if (checkDraw()) {
            drawBoard();
            cout << "It's a draw!\n";
            gameOn = false;
        } else {
            switchPlayer();
        }
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        playGame();
    } else {
        cout << "Thanks for playing!\n";
    }
}

int main() {
    playGame();
    return 0;
}