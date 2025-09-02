#include <stdio.h>

char board[3][3];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    printf("  0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf(" ---+---+---\n");
    }
    printf("\n");
}

int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return 1;
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return 1;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return 1;
    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return 1;

    return 0;
}

int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int row, col;
    initializeBoard();
    currentPlayer = 'X';

    printf("TIC TAC TOE\nPlayer 1: X | Player 2: O\n");
    printBoard();

    while (1) {
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Input validation
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid position! Please enter row and column between 0 and 2.\n");
            continue;
        }
        if (board[row][col] != ' ') {
            printf("Cell already occupied! Choose another.\n");
            continue;
        }

        board[row][col] = currentPlayer;
        printBoard();

        if (checkWinner()) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (checkDraw()) {
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}