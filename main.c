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

/***************************************************************
 *  -readInput
 *
 * Efectua o processamento do input, peca a peca
 **************************************************************/
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
		deleteFilledLines(gameArea, piece); /* Eliminar linhas e actualizar pontuacao */
		deletePiece(piece); /* DeletePiece */
	}
	return;
}

/***************************************************************
 *  - processBuffer
 *
 * Recebe uma string e devolve uma peca com os atributos
 * descritos na string
 **************************************************************/
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

/***************************************************************
 *  - gravity
 *
 * Efectua a arrumacao de uma peca (deslocando-a para baixo)
 **************************************************************/
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

/***************************************************************
 *  - deleteFilledLines
 *
 * Responsavel por detectar linhas completas e elimina-las, bem
 * como a actualizacao da pontuacao.
 **************************************************************/
void deleteFilledLines(GameArea *gameArea, tetromino *t) {
	int* lines = getPieceLines(t);
	int linespan = getLineSpan(t);
	int i;
	Line* line;
	for(i=0; i<linespan; i++) {
		line = getGameLine(gameArea, lines[i]);
		if(lineFilled(line)) {
			if(hasAdjacentMonocolors(line)) {
				if(lineDiversity(line) == 1) {
					increaseScore(gameArea, 3);
					eraseLine(gameArea, lines[i]);
				}
			}
			else {
				if(lineDiversity(line) == 1) {
					increaseScore(gameArea, 3);
					eraseLine(gameArea, lines[i]+1);
					eraseLine(gameArea, lines[i]);
					eraseLine(gameArea, lines[i]-1);
				}
				else {
					increaseScore(gameArea, 1);
					eraseLine(gameArea, lines[i]);
				}
			}
		}
	}
	free(lines);
	return;
}

/***************************************************************
 *  - writeOutput
 *
 * Escreve no Standard Output o resultado do processamento
 **************************************************************/
void writeOutput(GameArea *gameArea) {
	int i, j, num_lines, *num_pieces, median, color, type;
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

	printf("\n\n");

	/* Numero de pecas completas em jogo */
	printf("%d\n", vectorSum(getGameAreaPieceCounts(gameArea), NUM_TYPES*NUM_CORES));

	/* Imprimir tipo e cor das pecas completas em jogo, ordenadas */
	num_pieces = getGameAreaPieceCounts(gameArea); /* hashtable */
	for(i=0; i<(NUM_CORES*NUM_TYPES); i++) {
		color = (i % NUM_CORES) + 1;
		type = (i / NUM_CORES) + 1;
		for(j=0; j<num_pieces[i]; j++) {
			printf("%d %c\n", type, int2color(color));
		}
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
		for(i=0; i<NUM_COLUNAS && getLineColumn(line)[i] != EMPTY_SPACE; i++) {
			printf("%c", getLineColumn(line)[i]);
		}
	}

	printf("\n");
	return;
}
