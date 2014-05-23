#pragma once

#include "constants.h"

/****************************
 * Estruturas do codigo ... *
 ***************************/

typedef struct Line {
	struct Line* previous;
	struct Line* next;
	char column[NUM_COLUNAS];
	struct t_location* *pieces;
	int num_t_locations;
} Line;

typedef struct HeightMap {
	int columns[NUM_COLUNAS];
} HeightMap;

typedef struct GameArea {
	Line *gameLineFirst;
	Line *gameLineLast;
	int num_lines;
	HeightMap *heightMap;
	Line *deletedLinesFirst;
	Line *deletedLinesLast;
	int num_deleted_lines;
	int score;
	int* piece_count;
} GameArea;

typedef struct position {
	int line;
	int column;
} position;

typedef struct tetromino {
	position position;
	int type;
	char color;
} tetromino;

typedef struct t_location {
	int hash_pos;
	int num_lines;
	Line* *lines;
} t_location;
