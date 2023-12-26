#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum { MAX_PLY = 128, MAX_MOVES = 256 };
enum { WHITE, BLACK, COLOR_NB = 2 };
enum { NO_TYPE, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, PIECE_TYPE_NB = 7 };
enum {
    NO_PIECE,
    W_PAWN = 1, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
    B_PAWN = 9, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING,

    PIECE_NB = 16
};
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NB = 8 };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NB = 8 };
enum {
    SQ_A1, SQ_B1, SQ_C1, SQ_D1, SQ_E1, SQ_F1, SQ_G1, SQ_H1,
    SQ_A2, SQ_B2, SQ_C2, SQ_D2, SQ_E2, SQ_F2, SA_G2, SQ_H2,
    SQ_A3, SQ_B3, SQ_C3, SQ_D3, SQ_E3, SQ_F3, SA_G3, SQ_H3,
    SQ_A4, SQ_B4, SQ_C4, SQ_D4, SQ_E4, SQ_F4, SQ_G4, SQ_H4,
    SQ_A5, SQ_B5, SQ_C5, SQ_D5, SQ_E5, SQ_F5, SA_G5, SQ_H5,
    SQ_A6, SQ_B6, SQ_C6, SQ_D6, SQ_E6, SQ_F6, SA_G6, SQ_H6,
    SQ_A7, SQ_B7, SQ_C7, SQ_D7, SQ_E7, SQ_F7, SA_G7, SQ_H7,
    SQ_A8, SQ_B8, SQ_C8, SQ_D8, SQ_E8, SQ_F8, SA_G8, SQ_H8,
    SQ_NONE = -1,

    SQUARE_NB = 64
};
enum { MG, EG, PHASE_NB = 2 };
enum {
    MATE = 32000,
    MATE_IN_MAX = MATE - MAX_PLY,
    MATED_IN_MAX = -MATE_IN_MAX,
    VALUE_INF = 32001
};
enum {
    WHITE_OO = 1, WHITE_OOO = 2,
    BLACK_OO = 4, BLACK_OOO = 8,
    CASTLING_NB = 16
};

static inline int pieceType(int piece) { return piece % 8; }
static inline int pieceColor(int piece) { return piece / 8; }
static inline int makePiece(int pieceType, int color) { return pieceType + color * 8; }

static inline int fileOf(int square) { return square % 8; }
static inline int rankOf(int square) { return square / 8; }
static inline int makeSquare(int file, int rank) { return file + rank * 8; }
static inline bool validCoord(int file, int rank) { return FILE_A <= file && file <= FILE_H && RANK_1 <= rank && rank <= RANK_8; }

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))

typedef struct Board Board;
typedef struct Undo Undo;
typedef struct MovePicker MovePicker;
typedef struct Thread Thread;
typedef struct EvalInfo EvalInfo;
typedef struct SearchInfo SearchInfo;
typedef struct PVariation PVariation;
typedef struct TTEntry TTEntry;
typedef struct TTBucket TTBucket;
typedef struct TTable TTable;
typedef struct Limits Limits;
typedef struct ThreadsGo ThreadsGo;

typedef int KillerTable[MAX_PLY][2];
typedef int CounterMoveTable[COLOR_NB][SQUARE_NB][SQUARE_NB];
typedef int HistoryTable[COLOR_NB][SQUARE_NB][SQUARE_NB];
