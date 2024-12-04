#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mapa.h"

void liberaMapa(MAPA* a){
	for(int i = 0; i < a->linhas; i ++){
		free(a->matriz[i]);
	}
	free(a->matriz);
}

void leMapa(MAPA* a){
	FILE* f;
	f = fopen("mapas.txt", "r");
	if(f == 0){
		printf("Desculpe, mapa indisponivel!\n");
		exit(1);
	}
	fscanf(f, "%d %d", &a->linhas, &a->colunas);
	alocaMapa(a);
	for(int i = 0; i < a->linhas; i++){
		fscanf(f, "%s", a->matriz[i]);
	}
	fclose(f);
}

void alocaMapa(MAPA* a){
	a->matriz = malloc(sizeof(char*) * a->linhas);
	for(int i = 0; i < a->linhas; i++){
		a->matriz[i] = malloc(sizeof(char)*(a->colunas + 1));
	}

}


