#pragma once

#include <stdlib.h>
#include "common.h"
#include "gamearea.h"
#include "line.h"
#include "t_hash.h"
#include "tetromino.h"

t_location* createTLocation(GameArea *gameArea, tetromino *t);

int getTLocationHashPos(t_location *loc);
int getTLocationNumLines(t_location *loc);
Line** getTLocationLines(t_location *loc);

void setTLocationHashPos(t_location *loc, int pos);
void setTLocationNumLines(t_location *loc, int num);
void setTLocationLines(t_location *loc, Line* *lines);

void eraseTLocations(GameArea *g, Line* l);
void processTLocation(t_location* loc);
