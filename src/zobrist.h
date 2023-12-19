#pragma once

#include "types.h"

extern uint64_t ZobristKeys[PIECE_NB][SQUARE_NB];
extern uint64_t ZobristEnPassantKeys[FILE_NB];
extern uint64_t ZobristCastlingKeys[CASTLING_NB];
extern uint64_t ZobristTurnKey;

uint64_t rand64();
void initZobrist();
