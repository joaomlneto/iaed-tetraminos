#pragma once

#include <stdlib.h>
#include "common.h"
#include "constants.h"
#include "functions.h"

#include <stdio.h>

HeightMap* newHeightMap();
void deleteHeightMap(HeightMap *heightMap);

void resetHeightMap(HeightMap *heightMap);

int getHeightMapMax(HeightMap *heightMap);

int getColumnHeight(HeightMap *heightMap, int column);
void setColumnHeight(HeightMap *heightMap, int column, int height);
