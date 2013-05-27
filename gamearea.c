#include "gamearea.h"

/***************************************************************
 * GameArea - Área de Jogo                                     *
 ***************************************************************
 * Estrutura geral do projecto. Inicialmente era simplesmente  *
 * uma lista duplamente ligada de linhas com contador de       *
 * linhas.                                                     *
 *                                                             *
 * Devido aos timeouts da segunda parte do projecto, foi       *
 * incluido um mapa de alturas: piora ligeiramente o caso      *
 * médio mas melhora significativamente o pior caso, pois      *
 * auxilia no cálculo da linha inicial da peça.                *
 *                                                             *
 * Com a segunda parte do projecto foi também incluido nela o  *
 * valor da pontuação actual.                                  *
 *                                                             *
 * Na ultima parte do projecto adicionámos também nesta        *
 * estrutura uma lista simplesmente ligada com as linhas       *
 * eliminadas, ordenadas com o uso do algoritmo InsertSort.    *
 **************************************************************/

/***************************************************************
 *  - newGameArea
 *
 * Cria uma nova area de jogo, alocada dinamicamente na memoria
 * e devolve um ponteiro para ela. Inicializa os ponteiros para
 * inicio e fim a NULL, e o numero de linhas e pontuacao a zero
 **************************************************************/
GameArea* newGameArea() {
	GameArea *g = malloc(sizeof(GameArea));
	setGameAreaFirst(g, NULL);
	setGameAreaLast(g, NULL);
	setGameAreaNumLines(g, 0);
	setGameAreaHeightMap(g, newHeightMap());
	setGameAreaDeletedFirst(g, NULL);
	setGameAreaNumDeletedLines(g, 0);
	setGameAreaScore(g, 0);
	return g;
}

/***************************************************************
 *  - clearGameArea
 *
 * Limpa a memoria de todo o conteudo da area de jogo
 * 'gameArea', inclusive todas as linhas nela contidas e a
 * propria estrutura da area de jogo.
 **************************************************************/
void clearGameArea(GameArea *gameArea) {
	Line *line, *aux;
	/* Apagar linhas activas na area de jogo */
	line = getGameAreaFirst(gameArea);
	while(line != NULL) {
		aux = getNextLine(line);
		free(line);
		line = aux;
	}
	/* Apagar mapa de alturas */
	free(getGameAreaHeightMap(gameArea));
	/* Libertar a propria estrutura da area de jogo */
	free(gameArea);
	return;
}

/***************************************************************
 *  - getGameAreaFirst
 *
 * Devolve um ponteiro para a primeira linha da area de jogo
 **************************************************************/
Line* getGameAreaFirst(GameArea *g) {
	return g->gameLineFirst;
}

/***************************************************************
 *  - getGameAreaLast
 *
 * Devolve um ponteiro para a ultima linha da area de jogo
 **************************************************************/
Line* getGameAreaLast(GameArea *g) {
	return g->gameLineLast;
}

/***************************************************************
 *  - getGameAreaNumLines
 *
 * Devolve o numero de linhas existentes na area de jogo
 **************************************************************/
int getGameAreaNumLines(GameArea *g) {
	return g->num_lines;
}

/***************************************************************
 *  - getGameAreaHeightMap
 *
 * Devolve um ponteiro para o mapa de alturas da area de jogo
 **************************************************************/
HeightMap* getGameAreaHeightMap(GameArea *g) {
	return g->heightMap;
}

/***************************************************************
 *  - getGameAreaDeletedFirst
 *
 * Devolve um ponteiro para a primeira linha da lista de linhas
 * eliminadas da area de jogo.
 **************************************************************/
Line* getGameAreaDeletedFirst(GameArea *g) {
	return g->deletedLinesFirst;
}

/***************************************************************
 *  - getGameAreaDeletedLast
 *
 * Devolve um ponteiro para a ultima linha da lista de linhas
 * eliminadas da area de jogo.
 **************************************************************/
Line* getGameAreaDeletedLast(GameArea *g) {
	return g->deletedLinesLast;
}

/***************************************************************
 *  - getGameAreaNumDeletedLines
 *
 * Devolve o numero de linhas apagadas da area de jogo
 **************************************************************/
int getGameAreaNumDeletedLines(GameArea *g) {
	return g->num_deleted_lines;
}

/***************************************************************
 *  - getGameAreaScore
 *
 * Devolve o valor da pontuacao da area de jogo
 **************************************************************/
int getGameAreaScore(GameArea *g) {
	return g->score;
}

/***************************************************************
 *  - setGameAreaFirst
 *
 * Altera o ponteiro para a primeira linha da area de jogo,
 * fazendo-o apontar para uma outra linha
 **************************************************************/
void setGameAreaFirst(GameArea *g, Line *l) {
	g->gameLineFirst = l;
	return;
}

/***************************************************************
 *  - setGameAreaLast
 *
 * Altera o ponteiro para a ultima linha da area de jogo,
 * fazendo-o apontar para uma outra linha
 **************************************************************/
void setGameAreaLast(GameArea *g, Line *l) {
	g->gameLineLast = l;
	return;
}

/***************************************************************
 *  - setGameAreaNumLines
 * 
 * Altera o valor do numero de linhas da area de jogo
 **************************************************************/
void setGameAreaNumLines(GameArea *g, int n) {
	g->num_lines = n;
	return;
}

/***************************************************************
 *  - setGameAreaHeightMap
 *
 * Altera o ponteiro para o mapa de alturas da area de jogo,
 * fazendo-o apontar para um outro mapa de alturas.
 **************************************************************/
void setGameAreaHeightMap(GameArea *gameArea, HeightMap *heightMap) {
	gameArea->heightMap = heightMap;
	return;
}

/***************************************************************
 *  - setGameAreaDeletedFirst
 *
 * Altera o ponteiro para a primeira linha da lista de linhas
 * eliminadas, fazendo-o apontar para uma outra linha.
 **************************************************************/
void setGameAreaDeletedFirst(GameArea *gameArea, Line *l) {
	gameArea->deletedLinesFirst = l;
	return;
}

/***************************************************************
 *  - setGameAreaDeletedLast
 *
 * Altera o ponteiro para a ultima linha da lista de linhas
 * eliminadas, fazendo-o apontar para uma outra linha.
 **************************************************************/
void setGameAreaDeletedLast(GameArea *gameArea, Line *l) {
	gameArea->deletedLinesLast = l;
	return;
}

/***************************************************************
 *  - setGameAreaNumDeletedLines
 *
 * Altera o valor do numero de linhas apagadas da area de jogo
 **************************************************************/
void setGameAreaNumDeletedLines(GameArea *gameArea, int n) {
	gameArea->num_deleted_lines = n;
	return;
}

/***************************************************************
 *  - setGameAreaScore
 *
 * Altera o valor da pontuacao da area de jogo
 **************************************************************/
void setGameAreaScore(GameArea *g, int score) {
	g->score = score;
	return;
}

/***************************************************************
 *  - getGameLine
 *
 * Devolve um ponteiro para a linha numero 'line_num' da area
 * de jogo. Caso esta nao exista, devolve NULL.
 **************************************************************/
Line* getGameLine(GameArea *g, int line_num) {
	int i;
	int num_lines = getGameAreaNumLines(g);
	Line *line;
	if (line_num > num_lines) {
		return NULL;
	}
	if((line_num <= (num_lines/2))) {
		line = getGameAreaFirst(g);
		for (i=1; (i<line_num && line != NULL); i++) {
			line = getNextLine(line);
		}
	}
	else {
		line = getGameAreaLast(g);
		for (i=num_lines; i>line_num && line != NULL; i--) {
			line = getPreviousLine(line);
		}
	}
	return line;
}

/***************************************************************
 *  - getGameAreaColumnHeight
 *
 * Devolve a altura de uma coluna da area de jogo.
 **************************************************************/
int getGameAreaColumnHeight(GameArea *gameArea, int column) {
	HeightMap *heightMap = getGameAreaHeightMap(gameArea);
	return getColumnHeight(heightMap, column);
}

/***************************************************************
 *  - setGameAreaColumnHeight
 *
 * Modifica o valor da altura de uma coluna da area de jogo
 **************************************************************/
void setGameAreaColumnHeight(GameArea *gameArea, int column, int height) {
	HeightMap *heightMap = getGameAreaHeightMap(gameArea);
	setColumnHeight(heightMap, column, height);
	return ;
}

/***************************************************************
 *  - setPosition
 *
 * Altera a posicao 'position' da area de jogo 'gameArea',
 * colocando la o valor 'contents'
 **************************************************************/
void setPosition(GameArea *gameArea, position *position, char contents) {
	setPosition2(gameArea, getLine(position), getColumn(position), contents);
	return;
}

/***************************************************************
 *  - setPosition2
 *
 * Similar a funcao setPosition, com a diferenca de receber
 * dois inteiros 'line' e 'column', em vez de uma estrutura
 * posicao.
 **************************************************************/
void setPosition2(GameArea *g, int line, int column, char contents) {
	int i, num_lines;
	Line *l;
	num_lines = getGameAreaNumLines(g);
	for(i=num_lines; i<line; i++) {
		addLine(g);
	}
	l = getGameLine(g, line);
	setLineColumn(l, column, contents);
	return;
}

/***************************************************************
 *  - getPosition
 *
 * Devolve o conteudo da posicao 'position' da area de jogo
 **************************************************************/
char getPosition(GameArea *g, position *position) {
	return getPosition2(g, getLine(position), getColumn(position));
}

/***************************************************************
 *  - getPosition2
 *
 * Similar a funcao getPosition, com a diferenca de receber
 * dois inteiros 'line' e 'column' em vez de uma estrutura
 * posicao.
 **************************************************************/
char getPosition2(GameArea *g, int line, int column) {
	Line *l = getGameLine(g, line);
	if (line < 1) {
		return GAMEAREA_FLOOR;
	}
	if (l == NULL) {
		return EMPTY_SPACE;
	}
	return ((getLineColumn(l))[column-1]);
}

/***************************************************************
 *  - increaseScore
 *
 * Aumenta em 'increment' o valor da pontuacao da area de jogo
 **************************************************************/
void increaseScore(GameArea *gameArea, int increment) {
	int score = getGameAreaScore(gameArea);
	setGameAreaScore(gameArea, score + increment);
	return;
}

/***************************************************************
 *  - addLine
 *
 * Adiciona uma nova linha no cimo da area de jogo, com todas
 * as suas posicoes inicializadas a <espaco>
 **************************************************************/
void addLine(GameArea *g) {
	Line *l = newLine();
	Line *last = getGameAreaLast(g);
	int num_lines = getGameAreaNumLines(g);
	if (last == NULL) {
		setGameAreaFirst(g, l);
		setGameAreaLast(g, l);
	}
	else {
		setNextLine(last, l);
		setPreviousLine(l, last);
	}
	setGameAreaLast(g, l);
	setGameAreaNumLines(g, ++num_lines);
	return;
}

/***************************************************************
 *  - eraseLine
 *
 * Apaga a linha numero 'line' da area de jogo e reduz em um
 * o valor da altura das colunas no mapa de alturas.
 **************************************************************/
void eraseLine(GameArea *g, int line) {
	Line *l = getGameLine(g, line);
	Line *next;
	Line *previous;
	int num_lines = getGameAreaNumLines(g);
	/* Verificar se linha existe */
	if (l != NULL) {
		next = getNextLine(l);
		previous = getPreviousLine(l);
	}
	else {
		return;
	}
	/* Verificar se a proxima linha existe */
	if (next != NULL) {
		setPreviousLine(next, previous);
	}
	else {
		setGameAreaLast(g, previous);
	}
	/* Verificar se a linha anterior existe */
	if (previous != NULL) {
		setNextLine(previous, next);
	}
	else {
		setGameAreaFirst(g, next);
	}
	/* Decrementar numero de linhas!! */
	setGameAreaNumLines(g, --num_lines);
	/* Corrigir mapa de alturas */
	fixHeightMap(g);
	/* Inserir linha na lista de linhas eliminadas */
	insertSortDeletedLine(g, l);
	return;	
}

/***************************************************************
 *  - fixHeightMap
 *
 * Funcao que corrige a informacao contida no mapa de alturas
 * da area de jogo, apos a eliminacao de uma linha.
 **************************************************************/
void fixHeightMap(GameArea *gameArea) {
	int i, height;
	for (i=1; i<=NUM_COLUNAS; i++) {
		height = getGameAreaColumnHeight(gameArea, i);
		while(getPosition2(gameArea, height, i) == EMPTY_SPACE) {
			height--;
		}
		setGameAreaColumnHeight(gameArea, i, height);
	}
	return;
}

/***************************************************************
 *  - insertPiece
 *
 * Insere uma peca na area de jogo. Caso a peca seja
 * colocadas em linhas inexistentes, a funcao adiciona linhas
 * de forma a estas passarem a existir.
 **************************************************************/
void insertPiece(GameArea *g, tetromino *piece) {
	position *pos;
	int i;
	int line;
	int column;
	pos = getPositions(piece); /* Cria lixo na memória */
	for (i=0; i<4; i++) {
		/* Inserir na area de jogo */
		setPosition(g, &pos[i], getPieceColor(piece));
		/* Actualizar mapa de alturas */
		line = getLine(&pos[i]);
		column = getColumn(&pos[i]);
		if(getGameAreaColumnHeight(g, column) < line)
			setGameAreaColumnHeight(g, column, line);
	}
	free(pos); /* Apaga o lixo da memória :) yay! */
	return;
}

/***************************************************************
 *  - minDiversityLine
 *
 * Devolve o numero da linha de menor indice com maior
 * variedade de cores nas suas colunas
 **************************************************************/
int minDiversityLine(GameArea *gameArea) {
	int i, num_lines, *line_diversity;
	Line *line;
	num_lines = getGameAreaNumLines(gameArea);
	line_diversity = malloc(num_lines*sizeof(int));
	line = getGameAreaFirst(gameArea);
	for (i=0; i < num_lines; i++) {
		line_diversity[i] = lineDiversity(line);
		line = getNextLine(line);
	}
	return vectorMaxPos(line_diversity, num_lines) + 1;
}

/***************************************************************
 *  - insertSortDeletedLine
 *
 * Insere na lista de linhas eliminadas, uma nova linha,
 * ordenando a lista utilizando o algoritmo InsertSort.
 **************************************************************/
void insertSortDeletedLine(GameArea *gameArea, Line* line) {
	char columns[NUM_COLUNAS], *ptr;
	int i;
	Line* aux;

	/* remover associacoes anteriores */
	setPreviousLine(line, NULL);
	setNextLine(line, NULL);

	/* Eliminar posicoes vazias das colunas shift left */
	vectorCharInit(columns, NUM_COLUNAS, EMPTY_SPACE);
	ptr = columns;
	for(i=0; i<NUM_COLUNAS; i++) {
		if(getLineColumn(line)[i] != EMPTY_SPACE) {
			*(ptr++) = getLineColumn(line)[i];
		}
	}
	strncpy(getLineColumn(line), columns, NUM_COLUNAS);

	/* Incrementar contador de linhas eliminadas */
	i = getGameAreaNumDeletedLines(gameArea) + 1;
	setGameAreaNumDeletedLines(gameArea, i);

	/* OK, ja podemos inserir a linha na lista */
	/* Verificar se a lista esta vazia */
	if(getGameAreaDeletedFirst(gameArea) == NULL) {
		setGameAreaDeletedFirst(gameArea, line);
		setGameAreaDeletedLast(gameArea, line);
		return;
	}

	aux = getGameAreaDeletedFirst(gameArea);

	while(aux != NULL && strncmp(getLineColumn(aux), getLineColumn(line), NUM_COLUNAS) < 0) {
		aux = getNextLine(aux);
	}

	/* Inserir no fim? */
	if(aux == NULL) {
		setNextLine(getGameAreaDeletedLast(gameArea), line);
		setPreviousLine(line, getGameAreaDeletedLast(gameArea));
		setGameAreaDeletedLast(gameArea, line);
		return;
	}

	/* Inserir no inicio? */
	if(getPreviousLine(aux) == NULL) {
		setPreviousLine(getGameAreaDeletedFirst(gameArea), line);
		setNextLine(line, getGameAreaDeletedFirst(gameArea));
		setGameAreaDeletedFirst(gameArea, line);
		return;
	}

	/* Inserir algures no meio da lista */
	setNextLine(getPreviousLine(aux), line);
	setPreviousLine(line, getPreviousLine(aux));
	setNextLine(line, aux);
	setPreviousLine(aux, line);
	return;
}
