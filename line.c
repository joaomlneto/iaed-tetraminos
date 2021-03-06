#include "line.h"

/***************************************************************
 *  - newLine
 *
 * Cria dinamicamente em memoria uma linha, e devolve um
 * ponteiro para ela. Inicializa os ponteiros para a linha
 * anterior e linha seguinte a NULL, e inicializa todas as
 * suas colunas com <espaco>.
 **************************************************************/
Line* newLine() {
	Line *l = malloc(sizeof(Line));
	setNextLine(l, NULL);
	setPreviousLine(l, NULL);
	vectorCharInit(getLineColumn(l), NUM_COLUNAS, EMPTY_SPACE);
	setLineTLIndex(l, 0);
	l->pieces = NULL;
	return l;
}

/***************************************************************
 *  - deleteLine
 *
 * Apaga a linha recebida como argumento da memoria
 **************************************************************/
void deleteLine(Line *line) {
	if(line != NULL) {
		if(getLineT_location(line) != NULL)
			free(getLineT_location(line));
		free(line);
	}
}

/***************************************************************
 *  - getNextLine
 *
 * Devolve um ponteiro para a linha seguinte
 **************************************************************/
Line* getNextLine(Line *l) {
	return l->next;
}

/***************************************************************
 *  - getPreviousLine
 *
 * Devolve um ponteiro para a linha anterior
 **************************************************************/
Line* getPreviousLine(Line *l) {
	return l->previous;
}

/***************************************************************
 *  - getLineColumn
 *
 * Devolve um ponteiro para o vector das colunas da linha
 **************************************************************/
char* getLineColumn(Line *l) {
	return l->column;
}

/***************************************************************
 *  - setNextLine
 *
 * Altera o valor do ponteiro para a linha seguinte
 **************************************************************/
void setNextLine(Line *line, Line *next_line) {
	line->next = next_line;
}

/***************************************************************
 *  - setPreviousLine
 *
 * Altera o valor do ponteiro para a linha anterior
 **************************************************************/
void setPreviousLine(Line *line, Line *previous_line) {
	line->previous = previous_line;
}

/***************************************************************
 *  - setLineColumn
 *
 * Altera o conteudo da coluna 'c' da linha 'l', colocando la o
 * valor 'contents'.
 **************************************************************/
void setLineColumn(Line *l, int c, char contents) {
	l->column[c-1] = contents;
}

/***************************************************************
 *  - lineDiversity
 *
 * Devolve o numero de cores diferentes existentes na linha.
 * Posicoes vazias nao contam como cor.
 **************************************************************/
int lineDiversity(Line *line) {
	char *column;
	int i, diversityMap[NUM_COLUNAS];
	if (line == NULL) {
		return 0;
	}
	column = getLineColumn(line);
	vectorInit(diversityMap, NUM_COLUNAS, 0);
	for (i=0; i<NUM_COLUNAS; i++) {
		switch(column[i]) {
			case 'R': diversityMap[0] = 1; break;
			case 'Y': diversityMap[1] = 1; break;
			case 'B': diversityMap[2] = 1; break;
			case 'G': diversityMap[3] = 1; break;
			case 'O': diversityMap[4] = 1; break;
			case 'V': diversityMap[5] = 1; break;
		}
	}
	return vectorSum(diversityMap, NUM_CORES);
}

/***************************************************************
 *  - lineFilled
 *
 * Verifica se uma linha esta preenchida ou nao. Devolve 1
 * em caso afirmativo, 0 caso contrario. Caso a linha nao
 * exista, devolve 1.
 **************************************************************/
int lineFilled(Line *line) {
	int i;
	char *col;
	if (line == NULL) {
		return 0;
	}
	col = getLineColumn(line);
	for (i=0; i<NUM_COLUNAS; i++) {
		if (col[i] == EMPTY_SPACE) {
			return 0;
		}
	}
	return 1;
}

/***************************************************************
 *  - hasAdjacentMonocolors
 *
 * Devolve 1 caso pelo menos uma das linhas adjacentes esteja
 * completa e seja monocor. Devolve 0 caso contrario.
 **************************************************************/
int hasAdjacentMonocolors(Line *line) {
	Line *aux;
	aux = getNextLine(line);
	if(aux != NULL && lineFilled(aux) && (lineDiversity(aux) == 1))
		return 1;
	aux = getPreviousLine(line);
	if(aux != NULL && lineFilled(aux) && (lineDiversity(aux) == 1))
		return 1;
	return 0;
}

/***************************************************************
* - setLineT_location

* insere um ponteiro para t_location no array de t_locations de 
* uma linha
***************************************************************/
void setLineT_location(Line *l, t_location *tl) {
	int i;
	t_location* *aux;
	i = getLineTLIndex(l)+1;
	setLineTLIndex(l, i);
	aux = getLineT_location(l);
	aux = realloc(aux, i*sizeof(t_location));
	l->pieces = aux;
	(l->pieces)[i - 1] = tl;
}

/***************************************************************
* - getLineT_location

* Devolve o vector de ponteiros para t_location relativo a uma 
* linha.
***************************************************************/
t_location** getLineT_location(Line *l) {
	return  (l->pieces);
}

/***************************************************************
* - 

* devolve 
***************************************************************/
int getLineTLIndex(Line *l) {
	return l->num_t_locations;
}

/***************************************************************
* - 

*
***************************************************************/
void setLineTLIndex(Line *l, int i) {
	(l->num_t_locations) = i;
}


