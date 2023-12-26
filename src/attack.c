#include "attack.h"
#include "bitboard.h"

uint64_t pawnAttacksTable[COLOR_NB][SQUARE_NB];
uint64_t knightAttacksTable[SQUARE_NB];
uint64_t kingAttacksTable[SQUARE_NB];

const int pawnDelta[2][2] = {{1, 1}, {-1, 1}};
const int knightDelta[8][2] = {{2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}};
const int bishopDelta[4][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
const int rookDelta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int kingDelta[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

static void setSquare(uint64_t *bb, int file, int rank){
    if (validCoord(file, rank))
        setBit(bb, makeSquare(file, rank));
}

uint64_t slidingPieceSlow(int sq, uint64_t occupied, const int delta[4][2]) {
    uint64_t result = 0ull;
    int f, r, df, dr;
    for (int i = 0; i < 4; i++) {
        df = delta[i][0]; dr = delta[i][1];
        for (f = fileOf(sq) + df, r = rankOf(sq) + dr; validCoord(f, r); f += df, r += dr) {
            setBit(&result, makeSquare(f, r));
            if (testBit(occupied, makeSquare(f, r)))
                break;
        }
    }
    return result;
}

void initAttacks() {
    for (int sq = 0; sq < 64; sq++) {
        for (int dir = 0; dir < 2; dir++){
            setSquare(&pawnAttacksTable[WHITE][sq], fileOf(sq) + pawnDelta[dir][0], rankOf(sq) + pawnDelta[dir][1]);
            setSquare(&pawnAttacksTable[BLACK][sq], fileOf(sq) - pawnDelta[dir][0], rankOf(sq) - pawnDelta[dir][1]);
        }
        for (int dir = 0; dir < 8; dir++) {
            setSquare(&knightAttacksTable[sq], fileOf(sq) + knightDelta[dir][0], rankOf(sq) + knightDelta[dir][1]);
            setSquare(&kingAttacksTable[sq], fileOf(sq) + kingDelta[dir][0], rankOf(sq) + kingDelta[dir][1]);
        }
    }
}

uint64_t pawnAttack(int sq, int color) { return pawnAttacksTable[color][sq]; }
uint64_t knightAttack(int sq) { return knightAttacksTable[sq]; }
uint64_t bishopAttack(int sq, uint64_t occupied) { return slidingPieceSlow(sq, occupied, bishopDelta); }
uint64_t rookAttack(int sq, uint64_t occupied) { return slidingPieceSlow(sq, occupied, rookDelta); }
uint64_t queenAttack(int sq, uint64_t occupied) { return bishopAttack(sq, occupied) | rookAttack(sq, occupied); }
uint64_t kingAttack(int sq) { return kingAttacksTable[sq]; }
