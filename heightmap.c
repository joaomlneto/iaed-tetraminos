#include "heightmap.h"

/***************************************************************
 *  - newHeightMap
 *
 * Devolve um ponteiro para um mapa de alturas alocado
 * dinamicamente em memoria.
 **************************************************************/
HeightMap* newHeightMap() {
	HeightMap *heightMap = malloc(sizeof(HeightMap));
	resetHeightMap(heightMap);
	return heightMap;
}

/***************************************************************
 *  - deleteHeightMap
 *
 * Apaga da memoria o mapa de alturas
 **************************************************************/
void deleteHeightMap(HeightMap *heightMap) {
	free(heightMap);
	return;
}

/***************************************************************
 *  - resetHeightMap
 *
 * Efectua a inicializacao do mapa de alturas a zero
 **************************************************************/
void resetHeightMap(HeightMap *heightMap) {
	vectorInit(heightMap->columns, NUM_COLUNAS, 0);
}

/***************************************************************
 *  - getHeightMapMax
 *
 * Devolve a altura maxima do mapa de alturas
 **************************************************************/
int getHeightMapMax(HeightMap *heightMap) {
	return vectorMax(heightMap->columns, NUM_COLUNAS);
}

/***************************************************************
 *  - getColumnHeight
 *
 * Devolve a altura da coluna 'column' da area de jogo
 **************************************************************/
int getColumnHeight(HeightMap *heightMap, int column) {
	return (heightMap->columns)[column-1];
}

/***************************************************************
 *  - setColumnHeight
 *
 * Altera o valor da altura de uma coluna da area de jogo
 **************************************************************/
void setColumnHeight(HeightMap *heightMap, int column, int height) {
	(heightMap->columns)[column-1] = height;
	return;
}
