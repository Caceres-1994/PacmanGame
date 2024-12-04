#include <stdio.h>
#include "mapa.h"

char desenhoParede[4][7] = {
    {"......"},
    {"......"},
    {"......"},
    {"......"}
};

char desenhoFantasma[4][7] = {
    {".---. "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}
};

char desenhoHeroi[4][7] = {
    {" .--. "},
    {"/ _.-'"},
    {"\\  '-."},
    {" '--' "}
};

char desenhoPilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhoVazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void imprimeParte(char desenho[4][7], int parte){
    printf("%s", desenho[parte]);
}

void imprimeMapa(MAPA* a){
	for(int i = 0; i < (a->linhas); i++){
		for(int partes=0;partes<4;partes++){
            for(int j=0;j<(a->colunas);j++){
                switch(a->matriz[i][j]){
                    case FANTASMA:
                        imprimeParte(desenhoFantasma, partes);
                        break;
                    case HEROI:
                        imprimeParte(desenhoHeroi, partes);
                        break;
                    case PILULA:
                        imprimeParte(desenhoPilula, partes);
                        break;
                    case PAREDE_HORIZONTAL:
                    case PAREDE_VERTICAL:
                        imprimeParte(desenhoParede, partes);
                        break;
                    case VAZIO:
                        imprimeParte(desenhoVazio, partes);
                        break;
                    default:
                        break;
                }
            }
            printf("\n");
        }
	}
}