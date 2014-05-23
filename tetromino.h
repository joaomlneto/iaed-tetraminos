#pragma once

#include <stdlib.h>
#include "common.h"
#include "constants.h"
#include "functions.h"
#include "position.h"

tetromino* newPiece(int type, int line, int column, char color);
void deletePiece(tetromino* piece);

int getPieceLine(tetromino *t);
int getPieceColumn(tetromino *t);
int getPieceType(tetromino *t);
char getPieceColor(tetromino *t);

void setPieceLine(tetromino *t, int line);
void setPieceColumn(tetromino *t, int column);
void setPieceType(tetromino *t, int type);
void setPieceColor(tetromino *t, char color);

position* getPositions(tetromino *t);
void getPositionsI(position *pos, int line, int column);
void getPositionsO(position *pos, int line, int column);
void getPositionsN(position *pos, int line, int column);
void getPositionsT(position *pos, int line, int column);
void getPositionsL(position *pos, int line, int column);

int getFloorSize(tetromino *t);
position* getFloor(tetromino *t);
void getFloorI(position *pos, int line, int column);
void getFloorO(position *pos, int line, int column);
void getFloorN(position *pos, int line, int column);
void getFloorT(position *pos, int line, int column);
void getFloorL(position *pos, int line, int column);

int getColumnSpan(tetromino *t);
int getLineSpan(tetromino *t);

int* getPieceColumns(tetromino *t);
int* getPieceLines(tetromino *t);

int color2int(char color);
char int2color(int color);
