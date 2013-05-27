#include "t_hash.h"

int* newTHash() {
	int *hash = malloc(NUM_TYPES*NUM_CORES*sizeof(int));
	vectorInit(hash, NUM_TYPES*NUM_CORES, 0);
	return hash;
}

int getTHashPos(tetromino *t) {
	int type = getPieceType(t);
	char color = getPieceColor(t);
	return (NUM_CORES*(type-1) + color2int(color) - 1);
}
