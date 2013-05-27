#include "position.h"

/***************************************************************
 *  - getLine
 *
 * Devolve a componente LINHA de uma estrutura posicao
 **************************************************************/
int getLine(position *pos) {
	return pos->line;
}

/***************************************************************
 *  - getColumn
 *
 * Devolve a componente COLUNA de uma estrutura posicao
 **************************************************************/
int getColumn(position *pos) {
	return pos->column;
}

/***************************************************************
 *  - setLine
 *
 * Altera a componente LINHA de uma estrutura posicao para o
 * valor 'line'.
 **************************************************************/
void setLine(position *pos, int line) {
	pos->line = line;
}

/***************************************************************
 *  - setColumn
 *
 * Altera a componente COLUNA de uma estrutura posicao para o
 * valor 'column'.
 **************************************************************/
void setColumn(position *pos, int column) {
	pos->column = column;
}
