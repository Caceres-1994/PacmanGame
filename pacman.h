#ifndef _PACMAN_H
#define _PACMAN_H
struct posicao
{
    int x; 
    int y;
};

typedef struct posicao POSICAO;


#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'

int acabou();
void mover();
int encontrarHeroi();
void moverParaCima();
void moverParaBaixo();
void moverParaEsquerda();
void moverParaDireita();
void mensagemFim();
void explodePilula(int, int);

#endif