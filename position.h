#pragma once

#include <stdlib.h>
#include "common.h"
/*
struct position {
	int line;
	int column;
}*/

int getLine(position *pos);
int getColumn(position *pos);
void setLine(position *pos, int line);
void setColumn(position *pos, int column);
