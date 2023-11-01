/*
 * A generalized and simplified version of tic-tac-toe. The board may have any
 * number of rows and columns. On each turn, a player may play anywhere on the
 * board, including on top of a previous play. To win, a player must occupy
 * all squares in a row or in a column. The game ends on a win, or when all
 * squares are occupied.
 *
 * This version plays a "canned" game, where the moves are coded in the moves
 * array declared as a global constant.
 *
 * Author      : Greg Phillips
 * Version     : 19 October 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_COLS 3
#define N_ROWS 3
#define EMPTY '.'

const char players[] = { 'X', 'O' };
const int n_moves = 6;
const int moves[][2] = { { 0, 1 }, { 0, 2 }, { 1, 1 }, { 1, 2 }, { 2, 1 }, { 2, 2 } };

void empty(char board[][N_COLS]);
void show(char* label, char board[][N_COLS]);
void make_move(char board[][N_COLS], int row, int col, int move_index,
        int *turn);
bool game_is_over(char board[][N_COLS]);

/*
 * Plays a single "game" using the moves encoded in the moves array (above).
 * The first move is for player X, the next for player O, etc.
 */
int main(void) {
    int turn = 0;
    char board[N_ROWS][N_COLS];
    empty(board);
    for (int ix = 0; ix < n_moves; ix++) {
        make_move(board, moves[ix][0], moves[ix][1], ix, &turn);
        if (game_is_over(board)) {
            break;
        }
    }
    return EXIT_SUCCESS;
}

/*
 * Displays the given label, then the contents of the board.
 */
void show(char* label, char board[][N_COLS]) {
    printf("%s: \n", label);
    for (int row = 0; row < N_ROWS; row++) {
        for (int col = 0; col < N_COLS; col++) {
            printf(" %c", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * Sets all squares in the provided board to EMPTY.
 */
void empty(char board[][N_COLS]) {
    for (int row = 0; row < N_ROWS; row++) {
        for (int col = 0; col < N_COLS; col++) {
            board[row][col] = EMPTY;
        }
    }
    show("Ready to play, board empty", board);
}

/*
 * Puts the current player's token on the indicated spot on the board,
 * advances to the next player, and displays the current state of the board.
 */
void make_move(char board[][N_COLS], int row, int col, int move_index,
        int *turn) {
    char label_buffer[20];
    board[row][col] = players[*turn];
    *turn = (*turn + 1) % 2;
    sprintf(label_buffer, "After move %d", move_index + 1);
    show(label_buffer, board);
}

/*
 * Checks whether there is a winner in a column (vertically). Returns
 * EMPTY if there is no winner; otherwise returns the winner's symbol.
 */
char column_winner(char board[][N_COLS]) {
    bool all_same;
    for (int col = 0; col < N_COLS; col++) {
        all_same = true;
        for (int row = 1; row < N_ROWS; row++) {
            if (board[row][col] != board[0][col]) {
                all_same = false;
                break;
            }
        }
        if (all_same && board[0][col] != EMPTY) {
            return board[0][col];
        }
    }
    return EMPTY;
}

/*
 * Checks whether there is a winner in a row (horizontally). Returns
 * EMPTY if there is no winner, otherwise returns the winner's symbol.
 */
char row_winner(char board[][N_COLS]) {
    bool all_same;
    for (int row = 0; row < N_ROWS; row++) {
        all_same = true;
        for (int col = 1; col < N_COLS; col++) {
            if (board[row][col] != board[row][0]) {
                all_same = false;
                break;
            }
        }
        if (all_same && board[row][0] != EMPTY) {
            return board[row][0];
        }
    }
    return EMPTY;
}

/*
 * Checks whether there is a winner. Returns EMPTY if there is no winner,
 * otherwise returns the winner's symbol.
 */
char winner(char board[][N_COLS]) {
    char winner = column_winner(board);
    if (winner != EMPTY) {
        return winner;
    }
    winner = row_winner(board);
    if (winner != EMPTY) {
        return winner;
    }
    return EMPTY;
}

/*
 * Checks whether the board is full (no EMPTY squares left). If so, returns
 * true, otherwise false.
 */
bool is_full(char board[][N_COLS]) {
    for (int row = 0; row < N_ROWS; row++) {
        for (int col = 0; col < N_COLS; col++) {
            if (board[row][col] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

/*
 * Checks whether the game is over and returns true if so, false otherwise.
 * If there is a winner, indicates who won; if the board is full, says so.
 */
bool game_is_over(char board[][N_COLS]) {
    char win = winner(board);
    if (win != EMPTY) {
        printf("Winner: %c\n", win);
        return true;
    }
    if (is_full(board)) {
        printf("Board full, no winner.\n");
        return true;
    }
    return false;
}