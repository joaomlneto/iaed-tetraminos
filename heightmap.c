#include "heightmap.h"

HeightMap* newHeightMap() {
	HeightMap *heightMap = malloc(sizeof(HeightMap));
	resetHeightMap(heightMap);
	return heightMap;
}

void deleteHeightMap(HeightMap *heightMap) {
	free(heightMap);
	return;
}

void resetHeightMap(HeightMap *heightMap) {
	vectorInit(heightMap->columns, NUM_COLUNAS, 0);
}

int getHeightMapMax(HeightMap *heightMap) {
	return vectorMax(heightMap->columns, NUM_COLUNAS);
}

int getColumnHeight(HeightMap *heightMap, int column) {
	return (heightMap->columns)[column-1];
}

void setColumnHeight(HeightMap *heightMap, int column, int height) {
	(heightMap->columns)[column-1] = height;
	return;
}
