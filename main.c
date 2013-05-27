#include "main.h"

/* DEBUG ONLY */
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
/* DEBUG ONLY */

int main() {
	GameArea *gameArea = newGameArea();
	readInput(gameArea);
	writeOutput(gameArea);
	clearGameArea(gameArea);
	return 0;
}

void readInput(GameArea *gameArea) {
	int i, num_pieces;
	char buffer[BUFFER_SIZE];
	tetromino *piece;
	/* Ler numero de pecas a processar */
	fgets(buffer, BUFFER_SIZE, stdin);
	num_pieces = atoi(buffer);
	/* Processamento das peças */
	for(i=0; i<num_pieces; i++) {
		fgets(buffer, BUFFER_SIZE, stdin); /* Ler linha do ficheiro */
		piece = processBuffer(gameArea, buffer); /* Transformar linha num tetromino */
		gravity(gameArea, piece); /* Aplicar gravidade a peca */
		insertPiece(gameArea, piece); /* Inserir a Peca na Area de Jogo */
		updateScore(gameArea, piece); /* BUGGED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
		deleteFilledLines(gameArea, piece); /* INNEFICIENT!!!!!!!!!!!!!!!!!!!!!! */
		deletePiece(piece); /* DeletePiece */
	}
	return;
}

tetromino* processBuffer(GameArea *gameArea, char *buffer) {
	tetromino *t;
	int piece_type;
	int *piece_columns, num_cols;
	int piece_column;
	char piece_color;

	piece_type = atoi(strtok(buffer, " \n\0"));
	piece_column = atoi(strtok(NULL, " \n\0"));
	piece_color = *strtok(NULL, " \n\0");
	t = newPiece(piece_type, 0, piece_column, piece_color);

	piece_columns = getPieceColumns(t);	/* Cria lixo */
	num_cols = getColumnSpan(t);
	for(num_cols = getColumnSpan(t); num_cols > 0; num_cols--) {
		piece_columns[num_cols-1] = getGameAreaColumnHeight(gameArea, piece_columns[num_cols-1]);
	}
	setPieceLine(t, vectorMax(piece_columns, getColumnSpan(t)) + getLineSpan(t));

	free(piece_columns); /* Apaga o lixo! */
	return t;
}

void gravity(GameArea *gameArea, tetromino *t) {
	int i, floor_size;
	position *floor;
	floor_size = getFloorSize(t);
	floor = getFloor(t);
	while(1) {
		for (i=0; i<floor_size; i++) {
			if(getPosition(gameArea, &floor[i]) != EMPTY_SPACE) {
				free(floor);
				return;
			}
			else {
				setLine(&floor[i], getLine(&floor[i])-1);
			}
		}
		setPieceLine(t, getPieceLine(t) - 1);
	}
	return;
}

void updateScore(GameArea *gameArea, tetromino *t) {
	int i;
	int score = getGameAreaScore(gameArea);
	int lines[4];
	Line *line;
	position *cells = getPositions(t);
	vectorInit(lines, 4, 0);
	for (i=0; i<4; i++) {
		if (!(vectorValueExists(lines, 4, getLine(&cells[i])))) {
			lines[i] = getLine(&cells[i]);
		}
	}
	for (i=0; i<4; i++) {
		line = getGameLine(gameArea, lines[i]);
		if(lineFilled(line) && (lineDiversity(line) == 1)) {
			score += 3;
		}
		if(lineFilled(line) && (lineDiversity(line) != 1)) {
			score += 1;
			line = getGameLine(gameArea, lines[i]+1);
			if(lineFilled(line) && (lineDiversity(line) == 1)) {
				score -= 1;
			}
			line = getGameLine(gameArea, lines[i]-1);
			if(lineFilled(line) && (lineDiversity(line) == 1)) {
				score -= 1;
			}
		}
	}
	setGameAreaScore(gameArea, score);
	free(cells);
	return;
}

void deleteFilledLines(GameArea *gameArea, tetromino *t) {
	int i;
	int list[10];
	int listptr = 0;
	int lines[4];
	Line *line;
	position *cells = getPositions(t);
	vectorInit(list, 10, 0);
	vectorInit(lines, 4, 0);
	for (i=0; i<4; i++) {
		lines[i] = getLine(&cells[i]);
	}
	for (i=0; i<4; i++) {
		line = getGameLine(gameArea, lines[i]);
		if(lineFilled(line)) {
			if(!(vectorValueExists(list, 10, lines[i]))) {
				list[listptr++] = lines[i];
			}
			if(lineDiversity(line) == 1) {
				if(!(vectorValueExists(list, 10, lines[i]+1))) {
					list[listptr++] = lines[i]+1;
					line = getGameLine(gameArea, lines[i]+1);
				}
				if(!(vectorValueExists(list, 10, lines[i]-1))) {
					list[listptr++] = lines[i]-1;
					line = getGameLine(gameArea, lines[i]-1);
				}
			}
		}
	}
	bubbleSortDesc(list, listptr);
	for (i=0; i<listptr; i++) {
		eraseLine(gameArea, list[i]);
	}
	free(cells);
}

void writeOutput(GameArea *gameArea) {
	int i, j, num_lines, median;
	Line* line = getGameAreaLast(gameArea);
	num_lines = getGameAreaNumLines(gameArea);
	printf("%d\n", getGameAreaNumLines(gameArea));
	printf("%d\n", getGameAreaScore(gameArea));
	printf("\n"); /* Espacamento entre os valores e a matriz */

	/* Imprimir as linhas, a comecar na ultima ate a primeira */
	for (i=num_lines; i>=1; i--) {
		printf("|");
		for (j=0; j<NUM_COLUNAS; j++) {
			printf("%c", getLineColumn(line)[j]);
		}
		printf("| %d\n", i);
		line = getPreviousLine(line);
	}

	/* Imprimir tracinhos por baixo da area de jogo */
	printf(" ");
	for(i=0; i<NUM_COLUNAS; i++) {
		printf("-");
	}

	printf("\n");

	/* Verificar lista de linhas apagadas */
	if(getGameAreaNumDeletedLines(gameArea) == 0)
		/* Nao ha linhas, mostrar mensagem */
		printf("No eliminations");
	else {
		/* Ha linhas, calcular posicao mediana da lista */
		median = (int)ceil((double)getGameAreaNumDeletedLines(gameArea)/2);
		/* Fazer fetch da linha dessa posicao */
		line = getGameAreaDeletedFirst(gameArea);
		while((median--) > 1)
			line = getNextLine(line);
		/* Mostrar a linha */
		for(i=0; i<NUM_COLUNAS; i++) {
			printf("%c", getLineColumn(line)[i]);
		}
	}

	printf("\n");
	return;
}

void debugInfo(GameArea *gameArea) {
	Line* line;
	int i;
	system("clear");
	/*writeOutput(gameArea);*/
	printf("| ");
	for(i=1; i<=NUM_COLUNAS; i++) {
		printf("%2d|", getGameAreaColumnHeight(gameArea, i));
	}
	printf("\n");
	printf("LISTA DE LINHAS APAGADAS:\n");
	line = getGameAreaDeletedFirst(gameArea);
	while(line != NULL) {
		for(i=0; i<NUM_COLUNAS; i++) {
			printf("%c", getLineColumn(line)[i]);
		}
		printf("\n");
		line = getNextLine(line);
	}
	sleep(3);
}
