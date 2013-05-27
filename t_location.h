#pragma once

#include <stdlib.h>
#include "common.h"
#include "gamearea.h"
#include "line.h"
#include "t_hash.h"
#include "tetromino.h"

/*struct t_location {
	int hash_pos;
	int num_lines;
	Line* *lines;
}*/

t_location* createTLocation(GameArea *gameArea, tetromino *t);

int getTLocationHashPos(t_location *loc);
int getTLocationNumLines(t_location *loc);
Line** getTLocationLines(t_location *loc);

void setTLocationHashPos(t_location *loc, int pos);
void setTLocationNumLines(t_location *loc, int num);
void setTLocationLines(t_location *loc, Line* *lines);
