#include "tetromino.h"

/***************************************************************
 *  - newPiece
 *
 * Cria dinamicamente em memoria um tetramino com os atributos
 * especificados pelos argumentos de entrada, e devole um
 * ponteiro para esse tetromino.
 **************************************************************/
tetromino* newPiece(int type, int line, int column, char color) {
	tetromino *t;
	t = malloc(sizeof(tetromino));
	setPieceLine(t, line);
	setPieceColumn(t, column);
	setPieceType(t, type);
	setPieceColor(t, color);
	return t;
}

/***************************************************************
 *  - deletePiece
 *
 * Apaga um tetramino da memoria
 **************************************************************/
void deletePiece(tetromino* piece) {
	free(piece);
}

/***************************************************************
 *  - getPieceLine
 *
 * Devolve a linha em que a posicao superior esquerda do
 * tetramino se encontra
 **************************************************************/
int getPieceLine(tetromino *t) {
	return getLine(&(t->position));
}

/***************************************************************
 *  - getPieceColumn
 *
 * Devolve a coluna em que a posicao superior esquerda do
 * tetramino se encontra
 **************************************************************/
int getPieceColumn(tetromino *t) {
	return getColumn(&(t->position));
}

/***************************************************************
 *  - getPieceType
 *
 * Devolve o tipo do tetramino
 **************************************************************/
int getPieceType(tetromino *t) {
	return t->type;
}

/***************************************************************
 *  - getPieceColor
 *
 * Devolve a cor do tetramino
 **************************************************************/
char getPieceColor(tetromino *t) {
	return t->color;
}

/***************************************************************
 *  - setPieceLine
 *
 * Altera a linha da posicao superior esquerda do tetramino
 * para o valor 'line'
 **************************************************************/
void setPieceLine(tetromino *t, int line) {
	setLine(&(t->position), line);
}

/***************************************************************
 *  - setPieceColumn
 *
 * Altera a coluna da posicao superior esquerda do tetramino
 * para o valor 'line'
 **************************************************************/
void setPieceColumn(tetromino *t, int column) {
	setColumn(&(t->position), column);
}

/***************************************************************
 *  - setPieceType
 *
 * Altera o tipo do tetramino
 **************************************************************/
void setPieceType(tetromino *t, int type) {
	t->type = type;
}

/***************************************************************
 *  - setPieceColor
 *
 * Altera a cor do tetramino
 **************************************************************/
void setPieceColor(tetromino *t, char color) {
	t->color = color;
}

/***************************************************************
 *  - getPositions
 *
 * Devolve um vector com todas as posicoes ocupadas pelo
 * tetramino. O vector tem sempre tamanho PIECE_NUM_POSITIONS
 **************************************************************/
position* getPositions(tetromino *t) {
	int piece_type, piece_line, piece_column;
	position *pos;
	pos = malloc(PIECE_NUM_POSITIONS*sizeof(position));
	piece_type = getPieceType(t);
	piece_line = getPieceLine(t);
	piece_column = getPieceColumn(t);
	switch(piece_type) {
		case TYPE_I: getPositionsI(pos, piece_line, piece_column); break;
		case TYPE_O: getPositionsO(pos, piece_line, piece_column); break;
		case TYPE_N: getPositionsN(pos, piece_line, piece_column); break;
		case TYPE_T: getPositionsT(pos, piece_line, piece_column); break;
		case TYPE_L: getPositionsL(pos, piece_line, piece_column); break;
	}
	return pos;
}

/***************************************************************
 *  - getPositionsI
 *
 * Funcao auxiliar a funcao getPositions. Altera o vector 'pos'
 * com as posicoes ocupadas por uma peca do tipo I cuja posicao
 * superior esquerda se encontra na linha 'line' e coluna
 * 'column'
 **************************************************************/
void getPositionsI(position *pos, int line, int column) {
	pos[0].line = line;
	pos[0].column = column;
	pos[1].line = line;
	pos[1].column = column + 1;
	pos[2].line = line;
	pos[2].column = column + 2;
	pos[3].line = line;
	pos[3].column = column + 3;
	return;
}

/***************************************************************
 *  - getPositionsO
 *
 * Funcao auxiliar a funcao getPositions. Altera o vector 'pos'
 * com as posicoes ocupadas por uma peca do tipo O cuja posicao
 * superior esquerda se encontra na linha 'line' e coluna
 * 'column'
 **************************************************************/
void getPositionsO(position *pos, int line, int column) {
	pos[0].line = line;
	pos[0].column = column;
	pos[1].line = line;
	pos[1].column = column + 1;
	pos[2].line = line - 1;
	pos[2].column = column;
	pos[3].line = line - 1;
	pos[3].column = column + 1;
	return;
}

/***************************************************************
 *  - getPositionsN
 *
 * Funcao auxiliar a funcao getPositions. Altera o vector 'pos'
 * com as posicoes ocupadas por uma peca do tipo N cuja posicao
 * superior esquerda se encontra na linha 'line' e coluna
 * 'column'
 **************************************************************/
void getPositionsN(position *pos, int line, int column) {
	pos[0].line = line;
	pos[0].column = column;
	pos[1].line = line;
	pos[1].column = column + 1;
	pos[2].line = line - 1;
	pos[2].column = column + 1;
	pos[3].line = line - 1;
	pos[3].column = column + 2;
	return;
}

/***************************************************************
 *  - getPositionsT
 *
 * Funcao auxiliar a funcao getPositions. Altera o vector 'pos'
 * com as posicoes ocupadas por uma peca do tipo T cuja posicao
 * superior esquerda se encontra na linha 'line' e coluna
 * 'column'
 **************************************************************/
void getPositionsT(position *pos, int line, int column) {
	pos[0].line = line;
	pos[0].column = column;
	pos[1].line = line;
	pos[1].column = column + 1;
	pos[2].line = line;
	pos[2].column = column + 2;
	pos[3].line = line - 1;
	pos[3].column = column + 1;
	return;
}

/***************************************************************
 *  - getPositionsL
 *
 * Funcao auxiliar a funcao getPositions. Altera o vector 'pos'
 * com as posicoes ocupadas por uma peca do tipo L cuja posicao
 * superior esquerda se encontra na linha 'line' e coluna
 * 'column'
 **************************************************************/
void getPositionsL(position *pos, int line, int column) {
	pos[0].line = line;
	pos[0].column = column;
	pos[1].line = line;
	pos[1].column = column + 1;
	pos[2].line = line;
	pos[2].column = column + 2;
	pos[3].line = line - 1;
	pos[3].column = column;
	return;
}

/* MODIFICAR PROGRAMA PARA NAO USAR ESTA FUNCAO */
/***************************************************************
 *  - getFloorSize
 *
 * Devolve o numero de posicoes existentes por baixo das
 * posicoes do tetramino que nao pertencem ao proprio
 * tetramino. Depende apenas do seu tipo
 **************************************************************/
int getFloorSize(tetromino *t) {
	int piece_type = getPieceType(t);
	switch(piece_type) {
		case TYPE_I: return 4;
		case TYPE_O: return 2;
		case TYPE_N: return 3;
		case TYPE_T: return 3;
		case TYPE_L: return 3;
	}
	return 0;
}

/***************************************************************
 *  - getFloor
 *
 * Devolve um vector alocado dinamicamente com as posicoes
 * existentes imediatamente por baixo das posicoes do tetramino
 * que nao pertencem ao proprio tetramino.
 **************************************************************/
position* getFloor(tetromino *t) {
	int piece_type, piece_line, piece_column, floor_size;
	position *floor_pos;
	floor_size = getColumnSpan(t);
	floor_pos = malloc(floor_size*sizeof(position));
	piece_type = getPieceType(t);
	piece_line = getPieceLine(t);
	piece_column = getPieceColumn(t);
	switch(piece_type) {
		case TYPE_I: getFloorI(floor_pos, piece_line, piece_column); break;
		case TYPE_O: getFloorO(floor_pos, piece_line, piece_column); break;
		case TYPE_N: getFloorN(floor_pos, piece_line, piece_column); break;
		case TYPE_T: getFloorT(floor_pos, piece_line, piece_column); break;
		case TYPE_L: getFloorL(floor_pos, piece_line, piece_column); break;
	}
	return floor_pos;
}

/***************************************************************
 *  - getFloorI
 *
 * Funcao auxiliar a funcao getFloor. Devolve um vector de
 * posicoes imediatamente abaixo das posicoes do tetramino de
 * tipo I que nao pertencem ao proprio tetramino.
 **************************************************************/
void getFloorI(position *pos, int line, int column) {
	pos[0].line = line - 1;
	pos[0].column = column;
	pos[1].line = line - 1;
	pos[1].column = column + 1;
	pos[2].line = line - 1;
	pos[2].column = column + 2;
	pos[3].line = line - 1;
	pos[3].column = column + 3;
	return;
}

/***************************************************************
 *  - getFloorO
 *
 * Funcao auxiliar a funcao getFloor. Devolve um vector de
 * posicoes imediatamente abaixo das posicoes do tetramino de
 * tipo O que nao pertencem ao proprio tetramino.
 **************************************************************/
void getFloorO(position *pos, int line, int column) {
	pos[0].line = line - 2;
	pos[0].column = column;
	pos[1].line = line - 2;
	pos[1].column = column + 1;
	return;
}

/***************************************************************
 *  - getFloorN
 *
 * Funcao auxiliar a funcao getFloor. Devolve um vector de
 * posicoes imediatamente abaixo das posicoes do tetramino de
 * tipo N que nao pertencem ao proprio tetramino.
 **************************************************************/
void getFloorN(position *pos, int line, int column) {
	pos[0].line = line - 1;
	pos[0].column = column;
	pos[1].line = line - 2;
	pos[1].column = column + 1;
	pos[2].line = line - 2;
	pos[2].column = column + 2;
	return;
}

/***************************************************************
 *  - getFloorT
 *
 * Funcao auxiliar a funcao getFloor. Devolve um vector de
 * posicoes imediatamente abaixo das posicoes do tetramino de
 * tipo T que nao pertencem ao proprio tetramino.
 **************************************************************/
void getFloorT(position *pos, int line, int column) {
	pos[0].line = line - 1;
	pos[0].column = column;
	pos[1].line = line - 1;
	pos[1].column = column + 2;
	pos[2].line = line - 2;
	pos[2].column = column + 1;
	return;
}

/***************************************************************
 *  - getFloorL
 *
 * Funcao auxiliar a funcao getFloor. Devolve um vector de
 * posicoes imediatamente abaixo das posicoes do tetramino de
 * tipo L que nao pertencem ao proprio tetramino.
 **************************************************************/
void getFloorL(position *pos, int line, int column) {
	pos[0].line = line - 2;
	pos[0].column = column;
	pos[1].line = line - 1;
	pos[1].column = column + 1;
	pos[2].line = line - 1;
	pos[2].column = column + 2;
	return;
}

/***************************************************************
 *  getColumnSpan
 *
 * Funcao que devolve a quantidade de colunas ocupadas pelas
 * componentes de um determinado tetramino.
 **************************************************************/
int getColumnSpan(tetromino *t) {
	int piece_type = getPieceType(t);
	switch(piece_type) {
		case TYPE_I: return 4;
		case TYPE_O: return 2;
		case TYPE_N: return 3;
		case TYPE_T: return 3;
		case TYPE_L: return 3;
	}
	return 0;
}

/***************************************************************
 *  getLineSpan
 *
 * Funcao que devolve a quantidade de linhas ocupadas pelas
 * componentes de um determinado tetramino.
 **************************************************************/
int getLineSpan(tetromino *t) {
	int piece_type = getPieceType(t);
	switch(piece_type) {
		case TYPE_I: return 1;
		case TYPE_O: return 2;
		case TYPE_N: return 2;
		case TYPE_T: return 2;
		case TYPE_L: return 2;
	}
	return 0;
}

/***************************************************************
 *  getPieceColumns
 *
 * Devolve uma lista com os numeros das colunas ocupadas pelas
 * componentes de um determinado tetramino.
 **************************************************************/
int* getPieceColumns(tetromino *t) {
	int size = getColumnSpan(t);
	int *columns = malloc(size*sizeof(int));
	int c = getPieceColumn(t);
	int i;
	for(i=0; i<size; i++) {
		columns[i] = c;
		c++;
	}
	return columns;
}

/***************************************************************
 *  getPieceLines
 *
 * Devolve uma lista com os numeros das linhas ocupadas pelas
 * componentes de um determinado tetramino.
 **************************************************************/
int* getPieceLines(tetromino *t) {
	int size = getLineSpan(t);
	int *lines = malloc(size*sizeof(int));
	int l = getPieceLine(t);
	int i;
	for(i=0; i<size; i++) {
		lines[i] = l;
		l--;
	}
	return lines;
}

/***************************************************************
 *  - color2int
 *
 * Transforma o caracter correspondente a uma cor em um inteiro
 * Se aquele caracter nao corresponder uma cor, devolve 0.
 **************************************************************/
int color2int(char color) {
	switch(color) {
		case 'B': return 1;
		case 'G': return 2;
		case 'O': return 3;
		case 'R': return 4;
		case 'V': return 5;
		case 'Y': return 6;
	}
	return 0;
}

/***************************************************************
 *  - int2color
 *
 * Transforma um inteiro no caracter correspondente a uma cor.
 * Se aquele numero nao corresponder uma cor, devolve 0.
 **************************************************************/
char int2color(int color) {
	switch(color) {
		case 1: return 'B';
		case 2: return 'G';
		case 3: return 'O';
		case 4: return 'R';
		case 5: return 'V';
		case 6: return 'Y';
	}
	return 0;
}
