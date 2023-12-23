#pragma once

#include "types.h"

void initAttacks();

uint64_t pawnAttacks(int sq, int color);
uint64_t knightAttacks(int sq);
uint64_t bishopAttacks(int sq, uint64_t occupied);
uint64_t rookAttacks(int sq, uint64_t occupied);
uint64_t queenAttacks(int sq, uint64_t occupied);
uint64_t kingAttacks(int sq);
