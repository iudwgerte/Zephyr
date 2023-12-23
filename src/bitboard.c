#include "bitboard.h"

const uint64_t FilesBB[FILE_NB] = { FILE_ABB, FILE_BBB, FILE_CBB, FILE_DBB, FILE_EBB, FILE_FBB, FILE_GBB, FILE_HBB };
const uint64_t RanksBB[RANK_NB] = { RANK_1BB, RANK_2BB, RANK_3BB, RANK_4BB, RANK_5BB, RANK_6BB, RANK_7BB, RANK_8BB };

int popcount(uint64_t bb) { return __builtin_popcountll(bb); }
int getlsb(uint64_t bb) { return __builtin_ctzll(bb); }
int getmsb(uint64_t bb) { return 63 - __builtin_clzll(bb); }
int poplsb(uint64_t *bb) { int lsb = getlsb(*bb); *bb &= *bb - 1; return lsb; }
bool several(uint64_t bb) { return bb & (bb - 1); }
bool onlyOne(uint64_t bb) { return bb && !several(bb); }

void setBit(uint64_t *bb, int sq) { *bb |= 1ull << sq; }
void clearBit(uint64_t *bb, int sq) { *bb &= ~(1ull << sq); }
bool testBit(uint64_t bb, int sq) { return bb & (1ull << sq); }

void printBitboard(uint64_t bb) {
    for (int r = RANK_8; r >= RANK_1; r--){
        for (int f = FILE_A; f <= FILE_H; f++) {
            if (testBit(bb, makeSquare(f, r)))
                printf("X ");
            else printf(". ");
        }
        printf("\n");
    }
}
