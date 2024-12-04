#include "mapa.h"
#include "fantasma.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>

FANTASMAS f;

void moverFantasma(MAPA* a){
	srand(time(0));

	for(int i = 0; i<f.qntdFantasmas; i++){
		int andou = 0;
		for(int j=0;j<10;j++){
			if(andou==1)break;
			f.direcaoFantasma[i] = rand()%4;
			switch (f.direcaoFantasma[i])
			{
			case 0:
				if(((a->matriz[(f.posicaoFantasma[i][0])][(f.posicaoFantasma[i][1])-1])==VAZIO)||
				((a->matriz[(f.posicaoFantasma[i][0])][(f.posicaoFantasma[i][1])-1])==HEROI)){
				fantasmaParaEsquerda(f.posicaoFantasma[i][0], &f.posicaoFantasma[i][1], a);
				andou = 1;
				}
				break;
			case 1:
				if(((a->matriz[(f.posicaoFantasma[i][0])][(f.posicaoFantasma[i][1])+1])==VAZIO)||
				((a->matriz[(f.posicaoFantasma[i][0])][(f.posicaoFantasma[i][1])+1])==HEROI)){
				fantasmaParaDireita(f.posicaoFantasma[i][0], &f.posicaoFantasma[i][1], a);
				andou = 1;
				}
				break;
			case 2: 
				if(((a->matriz[(f.posicaoFantasma[i][0])+1][(f.posicaoFantasma[i][1])])==VAZIO)||
				((a->matriz[(f.posicaoFantasma[i][0])+1][(f.posicaoFantasma[i][1])])==HEROI)){
				fantasmaParaCima(&f.posicaoFantasma[i][0], f.posicaoFantasma[i][1], a);
				andou = 1;
				}
				break;
			case 3:
				if(((a->matriz[(f.posicaoFantasma[i][0])-1][(f.posicaoFantasma[i][1])])==VAZIO)||
				((a->matriz[(f.posicaoFantasma[i][0])-1][(f.posicaoFantasma[i][1])])==HEROI)){
				fantasmaParaBaixo(&f.posicaoFantasma[i][0], f.posicaoFantasma[i][1], a);
				andou = 1;
				}
				break;
			default:
				break;
			}
		}
	}
}

int encontrarFantasma(MAPA* a){
	int encontrou = 0;
	limparArrayDeInteiros(f.direcaoFantasma, f.posicaoFantasma);
	f.qntdFantasmas = 0;
	int linhasFantasma = 0;
		for(int i = 0; i < a->linhas; i++){
			for (int j = 0; j < a->colunas; j++){
				if(a->matriz[(i)][(j)]==FANTASMA){
					f.posicaoFantasma[linhasFantasma][0]=i;
					f.posicaoFantasma[linhasFantasma][1]=j;
					linhasFantasma++;
					f.qntdFantasmas++;
					encontrou = 1;
					break;
				}
			}
		}
	return encontrou;
}

void fantasmaParaEsquerda(int f1, int* f2, MAPA* a){
	a->matriz[(f1)][*f2] = VAZIO;
	a->matriz[(f1)][(*f2)-1] = FANTASMA;
	(*f2)--;

}

void fantasmaParaDireita(int f1, int* f2, MAPA* a){
	a->matriz[(f1)][*f2] = VAZIO;
	a->matriz[(f1)][(*f2)+1] = FANTASMA;
	(*f2)++;
}

void fantasmaParaCima(int* f1, int f2, MAPA* a){
	a->matriz[(*f1)][f2] = VAZIO;
	a->matriz[(*f1)+1][(f2)] = FANTASMA;
	(*f1)++;
}

void fantasmaParaBaixo(int* f1, int f2, MAPA* a){
	a->matriz[(*f1)][f2] = VAZIO;
	a->matriz[(*f1)-1][(f2)] = FANTASMA;
	(*f1)--;
}