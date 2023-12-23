#pragma once

#include "types.h"

enum {
    FILE_ABB = 0x0101010101010101ull,
    FILE_BBB = 0x0202020202020202ull,
    FILE_CBB = 0x0404040404040404ull,
    FILE_DBB = 0x0808080808080808ull,
    FILE_EBB = 0x1010101010101010ull,
    FILE_FBB = 0x2020202020202020ull,
    FILE_GBB = 0x4040404040404040ull,
    FILE_HBB = 0x8080808080808080ull,

    RANK_1BB = 0x00000000000000FFull,
    RANK_2BB = 0x000000000000FF00ull,
    RANK_3BB = 0x0000000000FF0000ull,
    RANK_4BB = 0x00000000FF000000ull,
    RANK_5BB = 0x000000FF00000000ull,
    RANK_6BB = 0x0000FF0000000000ull,
    RANK_7BB = 0x00FF000000000000ull,
    RANK_8BB = 0xFF00000000000000ull,

    WHITE_SQUARES = 0x55AA55AA55AA55AAull,
    BLACK_SQUARES = 0xAA55AA55AA55AA55ull,

    LEFT_WING = FILE_ABB | FILE_BBB | FILE_CBB | FILE_DBB,
    RIGHT_WING = FILE_EBB | FILE_FBB | FILE_GBB | FILE_HBB,

    PROMOTION_RANKS = RANK_1BB | RANK_8BB
};

extern const uint64_t FilesBB[FILE_NB];
extern const uint64_t RanksBB[RANK_NB];

int popcount(uint64_t bb);
int getlsb(uint64_t bb);
int getmsb(uint64_t bb);
int poplsb(uint64_t *bb);
bool several(uint64_t bb);
bool onlyOne(uint64_t bb);

void setBit(uint64_t *bb, int sq);
void clearBit(uint64_t *bb, int sq);
bool testBit(uint64_t bb, int sq);

void printBitboard(uint64_t bb);
