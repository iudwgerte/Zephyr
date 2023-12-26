#pragma once

#include "types.h"

void initAttacks();

uint64_t pawnAttack(int sq, int color);
uint64_t knightAttack(int sq);
uint64_t bishopAttack(int sq, uint64_t occupied);
uint64_t rookAttack(int sq, uint64_t occupied);
uint64_t queenAttack(int sq, uint64_t occupied);
uint64_t kingAttack(int sq);
