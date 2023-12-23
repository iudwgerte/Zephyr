#include "attack.h"

uint64_t pawnAttacksTable[COLOR_NB][SQUARE_NB];
uint64_t knightAttacksTable[SQUARE_NB];
uint64_t kingAttacksTable[SQUARE_NB];

void initAttacks();

uint64_t pawnAttacks(int sq, int color) { return pawnAttacksTable[color][sq]; }
uint64_t knightAttacks(int sq) { return knightAttacksTable[sq]; }
uint64_t bishopAttacks(int sq, uint64_t occupied);
uint64_t rookAttacks(int sq, uint64_t occupied);
uint64_t queenAttacks(int sq, uint64_t occupied) { return bishopAttacks(sq, occupied) | rookAttacks(sq, occupied); }
uint64_t kingAttacks(int sq) { return kingAttacksTable[sq]; }
