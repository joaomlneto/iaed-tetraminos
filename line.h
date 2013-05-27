#pragma once

#include <stdlib.h>
#include "common.h"
#include "constants.h"
#include "functions.h"
#include "position.h"
#include "tetromino.h"
#include "t_location.h"

/*
struct Line {
	struct Line* previous;
	struct Line* next;
	char column[NUM_COLUNAS];
	struct t_location* *pieces;
}*/

Line* newLine();
void deleteLine(Line *line);

Line* getNextLine(Line *l);
Line* getPreviousLine(Line *l);
char* getLineColumn(Line *l);

void setNextLine(Line *line, Line *next_line);
void setPreviousLine(Line *line, Line *previous_line);
void setLineColumn(Line *l, int c, char contents);

int lineDiversity(Line *line);
int lineFilled(Line *line);
