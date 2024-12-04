#ifndef _MAPA_H
#define _MAPA_H

#define HEROI '@'
#define VAZIO '.'
#define FANTASMA 'F'
#define PILULA 'P'
#define PAREDE_HORIZONTAL '_'
#define PAREDE_VERTICAL '|'

struct mapa
{
    int linhas;
    int colunas;
    char** matriz;
};

typedef struct mapa MAPA;
void liberaMapa(MAPA* a);
void leMapa(MAPA* a);
void alocaMapa(MAPA* a);

#endif