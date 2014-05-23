#include "t_location.h"

/***************************************************************
 *  - createTLocation
 *
 * Devolve um ponteiro para uma estrutura do tipo t_location
 * inicializada, alocada dinamicamente em memoria, que reflecte
 * as caracteristicas de um tetramino, recebido como argumento
 **************************************************************/
t_location* createTLocation(GameArea *gameArea, tetromino *t) {
	t_location *loc = malloc(sizeof(t_location));
	int i;
	setTLocationHashPos(loc, getTHashPos(t));
	setTLocationNumLines(loc, getLineSpan(t));
	setTLocationLines(loc, malloc(getLineSpan(t)*sizeof(Line*)));
	for(i=0; i<getLineSpan(t); i++) {
		getTLocationLines(loc)[i] = getGameLine(gameArea, getPieceLine(t) - i);
		setLineT_location(getTLocationLines(loc)[i], loc);
	}
	return loc;
}

/***************************************************************
 *  - getTLocationHashPos
 *
 * Devolve a posicao da tabela de contadores a que corresponde a
 * informacao da peca.
 **************************************************************/
int getTLocationHashPos(t_location *loc) {
	return loc->hash_pos;
}

/***************************************************************
 *  - getTLocationNumLines
 *
 * Devolve o numero de linhas que a peca ocupa
 **************************************************************/
int getTLocationNumLines(t_location *loc) {
	return loc->num_lines;
}

/***************************************************************
 *  - getTLocationLines
 *
 * Devolve um vector de ponteiros para as linhas ocupadas pela
 * peca
 **************************************************************/
Line** getTLocationLines(t_location *loc) {
	return loc->lines;
}

/***************************************************************
 *  - setTLocationHashPos
 *
 * Altera a posicao na tabela de contadores a que corresponde a
 * peca.
 **************************************************************/
void setTLocationHashPos(t_location *loc, int pos) {
	loc->hash_pos = pos;
	return;
}

/***************************************************************
 *  - setTLocationNumLines
 *
 * Altera o valor do numero de linhas ocupadas pela peca
 **************************************************************/
void setTLocationNumLines(t_location *loc, int num) {
	loc->num_lines = num;
	return;
}

/***************************************************************
 *  - setTLocationLines
 *
 * Altera o vector de ponteiros para linhas ocupadas pela peca
 **************************************************************/
void setTLocationLines(t_location *loc, Line* *lines) {
	loc->lines = lines;
	return;
}

/***************************************************************
 *  - eraseTLocations
 *
 * Funcao que recebe uma linha e apaga todas as pecas nela
 * incluidas dos vectores de pecas das linhas da area de jogo e
 * da tabela de contadores de pecas completas na area de jogo
 **************************************************************/
void eraseTLocations(GameArea *g, Line* l) {
	int i, index, hashpos;
	index = getLineTLIndex(l);
	for(i=0; i<index; i++) {
		if(getLineT_location(l)[i] != NULL) {
			hashpos = getTLocationHashPos(getLineT_location(l)[i]);
			getGameAreaPieceCounts(g)[hashpos] -= 1;
			processTLocation(getLineT_location(l)[i]);
		}
	}
	return;
}

/***************************************************************
 *  - processTLocation
 *
 * Efectua a remocao de uma peca de jogo, alterando a tabela de
 * contadores de pecas completas de jogo e os vectores de pecas
 * nas linhas.
 **************************************************************/
void processTLocation(t_location* loc) {
	int i, j, num_lines, line_num_pieces, found;
	Line* line;
	num_lines = getTLocationNumLines(loc);
	for(i=0; i<num_lines; i++) {
		line = getTLocationLines(loc)[i];
		line_num_pieces = getLineTLIndex(line);
		found = 0;
		for(j=0; j<line_num_pieces && (!found); j++) {
			if(getLineT_location(line)[j] == loc) {
				getLineT_location(line)[j] = NULL;
				found = 1;
			}
		}
	}
	free(getTLocationLines(loc));
	free(loc);
}
