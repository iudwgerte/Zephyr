#pragma once

#include "types.h"

struct Board {
    int squares[SQUARE_NB];
    uint64_t pieces[PIECE_TYPE_NB], colors[COLOR_NB];
    uint64_t hash, kingAttackers;
    int turn, castlingRights, epSquare, halfMoveClock, fullMoveClock;
    uint64_t history[512];
};

struct Undo {
    uint64_t hash, kingAttackers;
    int castlingRights, epSquare, halfMoveClock, capturedPiece;
};

void sq2str(int sq, char *str);
void str2sq(int *sq, char *str);

void boardFromFEN(Board *board, const char *fen);
void boardToFEN(Board board, char* fen);

void printBoard(Board board);
uint64_t perft(Board board, int depth, bool isSplit);

bool boardIsDrawn(Board board);
bool is50MoveRule(Board board);
bool is3FoldRepetition(Board board);
bool isInsufficientMaterial(Board board);
