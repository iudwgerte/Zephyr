#include "zobrist.h"

uint64_t ZobristKeys[PIECE_NB][SQUARE_NB];
uint64_t ZobristEnPassantKeys[FILE_NB];
uint64_t ZobristCastlingKeys[CASTLING_NB];
uint64_t ZobristTurnKey;

uint64_t rand64() {
    static uint64_t seed = 0xCAFEull;

    seed ^= seed >> 12;
    seed ^= seed << 25;
    seed ^= seed >> 27;

    return seed * 2685821657736338717ull;
}
void initZobrist() {
    for (int pt = PAWN; pt <= KING; pt++)
        for (int color = WHITE; color <= BLACK; color++)
            for (int sq = SQ_A1; sq <= SQ_H8; sq++)
                ZobristKeys[makePiece(pt, color)][sq] = rand64();
    
    for (int file = FILE_A; file <= FILE_H; file++)
        ZobristEnPassantKeys[file] = rand64();

    for (int cr = 0; cr < CASTLING_NB; cr++)
        ZobristCastlingKeys[cr] = rand64();

    ZobristTurnKey = rand64();
}