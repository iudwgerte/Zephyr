#include "attack.h"
#include "bitboard.h"
#include "types.h"
#include "zobrist.h"

int main() {
    initAttacks();
    initZobrist();
    printBitboard(bishopAttack(SQ_D2, 0ull));
    return 0;
}
