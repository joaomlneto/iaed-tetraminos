#include "functions.h"

/***************************************************************
 *  - vectorInit
 * 
 * Inicializa o vector de inteiros 'v', de tamanho 'size', com
 * o valor 'value' em todas as suas posicoes.
 **************************************************************/
void vectorInit(int *v, int size, int value) {
	int i;
	for (i=0; i<size; i++) {
		v[i] = value;
	}
	return;
}

/***************************************************************
 *  - vectorSum
 *
 * Devolve a soma de todos os elementos do vector de inteiros
 * 'v' de tamanho 'size'.
 **************************************************************/
int vectorSum(int *v, int size) {
	int i, total=0;
	for (i=0; i<size; i++) {
		total += v[i];
	}
	return total;
}

/***************************************************************
 *  - vectorMax
 *
 * Devolve o valor maximo de todos os elementos do vector de
 * inteiros 'v' de tamanho 'size'.
 */
int vectorMax(int *v, int size) {
	int i, max=v[0];
	for (i=1; i<size; i++) {
		if (v[i] > max) {
			max = v[i];
		}
	}
	return max;
}

/***************************************************************
 *  - vectorMaxPos
 *
 * Devolve a posicao na qual ocorre o elemento maximo do vector
 * de inteiros 'v' de tamanho 'size'.
 **************************************************************/
int vectorMaxPos(int *v, int size) {
	int i, maxPos=0, maxValue=v[0];
	for (i=1; i<size; i++) {
		if (v[i] > maxValue) {
			maxValue = v[i];
			maxPos = i;
		}
	}
	return maxPos;
}

/***************************************************************
 *  - vectorValueExists
 * 
 * Determina se o inteiro 'value' ocorre no vector de inteiros
 * 'v' de tamanho 'size'
 **************************************************************/
int vectorValueExists(int *v, int size, int value) {
	int i;
	for (i=0; i<size; i++) {
		if (v[i] == value) {
			return 1;
		}
	}
	return 0;
}

/***************************************************************
 *  - bubbleSortDesc
 *
 * Recebe um vector de inteiros 'v', de tamanho 'size', e
 * ordena-o por ordem decrescente de valor, utilizando o
 * algoritmo de ordenacao BubbleSort.
 **************************************************************/
void bubbleSortDesc(int *v, int size) {
	int i, j, tmp;
	for (i=0; i<size; i++) {
		for (j=i+1; j<size; j++) {
			if (v[i] < v[j]) {
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
	return;
}

/***************************************************************
 *  - vectorCharInit
 *
 * Recebe um vector de caracteres 'v', de tamanho 'size', e
 * inicializa todas as suas posicoes com o caracter 'value'
 **************************************************************/
void vectorCharInit(char *v, int size, char value) {
        int i;
        for (i=0; i<size; i++) {
                v[i] = value;
        }
        return;
}
