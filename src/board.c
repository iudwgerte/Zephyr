#include "board.h"

void sq2str(int sq, char *str) {
    if (sq == -1)
        *str++ = '-';
    else {
        *str++ = fileOf(sq) + 'a';
        *str++ = rankOf(sq) + '1';
    }
    *str++ = '\0';
}
void str2sq(int *sq, char *str) { return str[0] == '-' ? -1 : makeSquare(str[1] - '1', str[0] - 'a'); }

void boardFromFEN(Board *board, const char *fen);
void boardToFEN(Board board, char* fen);

void printBoard(Board board);
uint64_t perft(Board board, int depth, bool isSplit);

bool boardIsDrawn(Board board) {
    return is50MoveRule(board)
        || is3FoldRepetition(board)
        || isInsufficientMaterial(board);
}
bool is50MoveRule(Board board) { return board.halfMoveClock > 99; }
bool is3FoldRepetition(Board board);
bool isInsufficientMaterial(Board board);
