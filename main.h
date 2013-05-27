#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "common.h"
#include "constants.h"
#include "functions.h"
#include "position.h"
#include "tetromino.h"
#include "gamearea.h"
#include "heightmap.h"


void readInput(GameArea *gameArea);
tetromino* processBuffer(GameArea *gameArea, char *buffer);
void gravity(GameArea *gameArea, tetromino *t);
void updateScore(GameArea *gameArea, tetromino *t);
void deleteFilledLines(GameArea *gameArea, tetromino *t);
void writeOutput(GameArea *gameArea);
void debugInfo(GameArea *gameArea);
