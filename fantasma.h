#ifndef _FANTASMA_H
#define _FANTASMA_H
#include "mapa.h"

struct fantasmas
{
	int posicaoFantasma[10][2];
	int qntdFantasmas;
    int direcaoFantasma[10];
};

typedef struct fantasmas FANTASMAS;

int encontrarFantasma(MAPA* a);
void fantasmaParaEsquerda(int f1, int* f2, MAPA* a);
void fantasmaParaDireita(int f1, int* f2, MAPA* a);
void fantasmaParaCima(int* f1, int f2, MAPA* a);
void fantasmaParaBaixo(int* f1, int f2, MAPA* a);
void moverFantasma(MAPA *a);
void limparArrayDeInteiros(int array1[10], int array2[10][2]);

#endif