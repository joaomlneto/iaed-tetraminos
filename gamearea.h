#pragma once

#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "constants.h"
#include "functions.h"
#include "heightmap.h"
#include "line.h"
#include "position.h"
#include "tetromino.h"

/*struct GameArea {
	Line *gameLineFirst;
	Line *gameLineLast;
	int num_lines;
	HeightMap *heightMap;
	Line *deletedLinesFirst;
	Line *deletedLinesLast;
	int num_deleted_lines;
	int score;
}*/

GameArea* newGameArea();
void clearGameArea(GameArea *gameArea);

Line* getGameAreaFirst(GameArea *g);
Line* getGameAreaLast(GameArea *g);
int getGameAreaNumLines(GameArea *g);
HeightMap* getGameAreaHeightMap(GameArea *g);
Line* getGameAreaDeletedFirst(GameArea *g);
Line* getGameAreaDeletedLast(GameArea *g);
int getGameAreaNumDeletedLines(GameArea *g);
int getGameAreaScore(GameArea *g);

void setGameAreaFirst(GameArea *g, Line *l);
void setGameAreaLast(GameArea *g, Line *l);
void setGameAreaNumLines(GameArea *g, int n);
void setGameAreaHeightMap(GameArea *gameArea, HeightMap *heightMap);
void setGameAreaDeletedFirst(GameArea *g, Line* l);
void setGameAreaDeletedLast(GameArea *g, Line* l);
void setGameAreaNumDeletedLines(GameArea *g, int n);
void setGameAreaScore(GameArea *g, int score);

Line* getGameLine(GameArea *g, int line_num);

int getGameAreaColumnHeight(GameArea *gameArea, int column);
void setGameAreaColumnHeight(GameArea *gameArea, int column, int height);

void setPosition(GameArea *g, position *position, char contents);
void setPosition2(GameArea *g, int line, int column, char contents);

char getPosition(GameArea *g, position *position);
char getPosition2(GameArea *g, int line, int column);

void increaseScore(GameArea *g, int increment);

void addLine(GameArea *g);
void eraseLine(GameArea *g, int line);
void fixHeightMap(GameArea *gameArea);

void insertPiece(GameArea *g, tetromino *piece);

int minDiversityLine(GameArea *gameArea);

void insertSortDeletedLine(GameArea *gameArea, Line* line);
