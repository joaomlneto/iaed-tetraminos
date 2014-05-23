#include "t_hash.h"

/***************************************************************
 *  - newTHash
 *
 * Devolve um ponteiro para uma nova tabela de contadores de
 * pecas completas alocada dinamicamente em memoria.
 **************************************************************/
int* newTHash() {
	int *hash = malloc(NUM_TYPES*NUM_CORES*sizeof(int));
	vectorInit(hash, NUM_TYPES*NUM_CORES, 0);
	return hash;
}

/***************************************************************
 *  - getTHashPos
 *
 * Recebe um tetramino e devolve qual a posicao na tabela a que
 * corresponde
 **************************************************************/
int getTHashPos(tetromino *t) {
	int type = getPieceType(t);
	char color = getPieceColor(t);
	return (NUM_CORES*(type-1) + color2int(color) - 1);
}
