#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE{ 3 };

void display_board(char board[SIZE][SIZE]) {
    cout << endl;
    for (int i{ 0 }; i < SIZE; i++) {
        for (int j{ 0 }; j < SIZE; j++) {
            cout << " " << board[i][j] << " ";
            if (j < SIZE - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < SIZE - 1) {
            cout << "---+---+---" << endl;
        }
    }
    cout << endl;
}

bool check_win(char board[SIZE][SIZE], char player) {
    for (int i{ 0 }; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    for (int j{ 0 }; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

bool valid_move(char board[SIZE][SIZE], int pos) {
    if (pos < 1 || pos > 9) {
        return false;
    }
    int row = (pos - 1) / SIZE;
    int col = (pos - 1) % SIZE;
    return board[row][col] != 'X' && board[row][col] != 'O';
}

void make_move(char board[SIZE][SIZE], int pos, char player) {
    int row = (pos - 1) / SIZE;
    int col = (pos - 1) % SIZE;
    board[row][col] = player;
}

int main() {

    int play{ 1 };

    while (play) {

        cout << "Welcome to the tic-tac-toe" << endl;

        char board[SIZE][SIZE] = {

            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
        };

        int moves{ 0 };
        int position{ 0 };
        bool win{ false };
        char current_player = 'X';

        while (moves < 9 && !win) {
            display_board(board);
            cout << "Player (" << current_player << ") Choose a position (1-9): ";
            cin >> position;

            if (valid_move(board, position)) {
                make_move(board, position, current_player);
                moves++;

                if (check_win(board, current_player)) {
                    win = true;
                }
                else {
                    current_player = (current_player == 'X') ? 'O' : 'X';
                }
            }
            else {
                cout << "Invalid move! Try again." << endl;
            }
        }

        display_board(board);
        if (win) {
            cout << "Player: " << current_player << " won the game." << endl;
        }
        else {
            cout << "The game ended in a tie." << endl;
        }
        cout << endl;
        cout << "Press 1 to play again or 0 to leave: ";
        cin >> play;

        while (play != 1 && play != 0) {
            cout << "This number is not valid. Try again: ";
            cin >> play;
        }
        if (!play) {
            cout << "Thanks for playing! " << endl;
        }
        else {
            system("cls");
        }

    }
    return 0;
}
