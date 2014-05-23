#pragma once

#include <stdlib.h>
#include "common.h"
#include "constants.h"
#include "functions.h"
#include "position.h"
#include "tetromino.h"
#include "t_location.h"

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
int hasAdjacentMonocolors(Line *line);

void setLineT_location(Line *l, t_location *tl);
t_location** getLineT_location(Line *l);
int getLineTLIndex(Line *l);
void setLineTLIndex(Line *l, int i);
