#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "time.h"
#include <string.h>
#include "pacman.h"
#include "ui.h"
#include "fantasma.h"

MAPA a;
POSICAO xy;

int temPilula;
int vitoria;

void limparArrayDeInteiros(int array1[10], int array2[10][2]){
	for(int i=0;i<10;i++){
		array1[i] = 0;
		array2[i][0] = 0;
		array2[i][1] = 0;
	}
}


int encontrarHeroi(){
	int achou = 0;
	for(int i = 0; i < a.linhas; i++){
		for(int j = 0; j < a.colunas; j ++){
			if(a.matriz[i][j] == HEROI){
				(xy.x) = i;
				(xy.y) = j;
				break;
			}
		}
		if(a.matriz[(xy.x)][(xy.y)] == HEROI){
			achou = 1;
			break;
		}
	}

	return achou;
}

void moverParaCima(){
	system("cls");
	if(a.matriz[(xy.x)-1][(xy.y)] == VAZIO){
		a.matriz[(xy.x)-1][(xy.y)] = HEROI;
		a.matriz[(xy.x)][(xy.y)] = VAZIO;
	}else if(a.matriz[(xy.x)-1][(xy.y)] == FANTASMA){
		a.matriz[(xy.x)-1][(xy.y)] = FANTASMA;
		a.matriz[(xy.x)][(xy.y)] = VAZIO;
	}else if(a.matriz[(xy.x)-1][(xy.y)] == PILULA){
		a.matriz[(xy.x)-1][(xy.y)] = HEROI;
		a.matriz[(xy.x)][(xy.y)] = VAZIO;
		temPilula = 1;
	}
	(xy.x)--;
}

void moverParaBaixo(){
	system("cls");
	if(a.matriz[(xy.x)+1][(xy.y)] == VAZIO){
		a.matriz[(xy.x)+1][(xy.y)] = HEROI;
		a.matriz[(xy.x)][(xy.y)] = VAZIO;
	}else if(a.matriz[(xy.x)+1][(xy.y)] == FANTASMA){
		a.matriz[(xy.x)+1][(xy.y)] = FANTASMA;
		a.matriz[(xy.x)][(xy.y)] = VAZIO;
	}else if(a.matriz[(xy.x)+1][(xy.y)] == PILULA){
		a.matriz[(xy.x)+1][(xy.y)] = HEROI;
		a.matriz[(xy.x)][(xy.y)] = VAZIO;
		temPilula = 1;
	}
	(xy.x)++;
}

void moverParaEsquerda(){
	system("cls");
	if(a.matriz[(xy.x)][(xy.y)-1] == VAZIO){
		a.matriz[(xy.x)][(xy.y)-1] = HEROI;
		a.matriz[(xy.x)][(xy.y)] = VAZIO;
	}else if(a.matriz[(xy.x)][(xy.y)-1] == FANTASMA){
		a.matriz[(xy.x)][(xy.y)-1] = FANTASMA;
		a.matriz[(xy.x)][(xy.y)] = VAZIO;
	}else if(a.matriz[(xy.x)][(xy.y)-1] == PILULA){
		a.matriz[(xy.x)][(xy.y)-1] = HEROI;
		a.matriz[(xy.x)][(xy.y)] = VAZIO;
		temPilula = 1;
	}
	(xy.y)--;
}

void moverParaDireita(){
	system("cls");
	if(a.matriz[(xy.x)][(xy.y)+1] == VAZIO){
			a.matriz[(xy.x)][(xy.y)+1] = HEROI;
			a.matriz[(xy.x)][(xy.y)] = VAZIO;
		}else if(a.matriz[(xy.x)][(xy.y)+1] == FANTASMA){
			a.matriz[(xy.x)][(xy.y)+1] = FANTASMA;
			a.matriz[(xy.x)][(xy.y)] = VAZIO;
		}else if(a.matriz[(xy.x)][(xy.y)+1] == PILULA){
			a.matriz[(xy.x)][(xy.y)+1] = HEROI;
			a.matriz[(xy.x)][(xy.y)] = VAZIO;
			temPilula = 1;
		}
	(xy.y)++;
}

void explodePilula(int x, int y){
	system("cls");
	printf("Explodiu a bomba!\n");
	int linhas[2] = {x, x};
	int colunas[2] = {y, y};

	for(int i=1;i<=4;i++){
		if((a.matriz[(x)][colunas[0]-1])==FANTASMA){
			a.matriz[(x)][(colunas[0])-1] = VAZIO;
			colunas[0]--;
		}
		if((a.matriz[(x)][colunas[1]+1])==FANTASMA){
			a.matriz[(x)][(colunas[1])+1] = VAZIO;
			colunas[1]++;
		}
		if((a.matriz[linhas[0]-1][y])==FANTASMA){
			a.matriz[(linhas[0]-1)][(y)] = VAZIO;
			linhas[0]--;
		}
		if((a.matriz[(linhas[1]+i)][y])==FANTASMA){
			a.matriz[linhas[1]+i][(y)] = VAZIO;
			linhas[1]++;
		}
	}

	encontrarFantasma(&a);

	temPilula = 0;
}

void mover(){
	char direcao;
	if(a.matriz[(xy.x)][(xy.y)]!= HEROI){
		encontrarHeroi();
	}
	if(!encontrarHeroi())return;
	direcao = getch();
	direcao = tolower(direcao);
	switch (direcao)
	{
	case CIMA:
		moverParaCima();
		break;
	case BAIXO:
		moverParaBaixo();
		break;
	case ESQUERDA:
		moverParaEsquerda();
		break;
	case DIREITA:
		moverParaDireita();
		break;
	case BOMBA:
		if(temPilula)explodePilula(xy.x, xy.y);
		break;
	default:
		system("cls");
		break;
	}
	moverFantasma(&a);
}

int acabou(){
	if(!(encontrarHeroi())) return 1;
	if(!(encontrarFantasma(&a))) {
		vitoria = 1;
		return 1;
	}
	return 0;
}

void mensagemFim(){
	if(!(encontrarHeroi())){
		system("cls");
		printf("\nO fantasma te pegou!\n");
		printf("		     .... NÃO! ... ... MNO! ...							\n");
		printf("   ..... NÃO!! ...................... MNNOO! ...				\n");
		printf(" ..... MM NÃO! ......................... MNNOO!! .				\n");
		printf(".... MNOONNOO! MMMMMMMMMMPPPOII! MNNO!!!! .						\n");
		printf(" ... !O! NÃO! MMMMMMMMMMMMMPPPOOOII!! NÃO! ....					\n");
		printf("    ...... ! MMMMMMMMMMMMMPPPPOOOOIII! ! ...					\n");
		printf("   ........MMMMMMMMMMMPPPPPOOOOOOII!! .....						\n");
		printf("   ........ MMMMMOOOOOOPPPPPPPOOOOMII! ...						\n");  
		printf("    ....... MMMMM.. OPPMMP., OMI! ....							\n");
		printf("     ...... MMMM:: o.,OPMP,.o ::Eu!! ...						\n");
		printf("         ....NNM:::.,,OOPM!P,.::::!! ....						\n");
		printf("          .. MMNNNNNOOOOPMO!!IIPPO!!O! .....					\n");
		printf("         ...MMMMMNNNNOO:!!:!!IPPPPOO! ....						\n");
		printf("           .. MMMMMNNOOMMNNIIIPPPOO!! ......					\n");
		printf("          ...... MMMONNMMNNNIIIOO!..........					\n");
		printf("       ....... MN MÃEMMNNNIIIIIO! OO..........					\n");
		printf("    ......... MNO! IiiiiiiiiiiiiI OOOO ...........				\n");
		printf("  ...... NNN.MNO! . Ó!!!!!!!!!Ó. OON NÃO! ........				\n");
		printf("   .... MNNNNNO! ...OOOOOOOOO. MNN NÃO!........					\n");
		printf("   ...... MNNNNO! .. PPPPPPPPP .. MMNON!........				\n");
		printf("      ...... OH! ................. SOBRE! .......				\n");
		printf("         ................................						\n");
	}
	if(!(encontrarFantasma(&a))){
		system("cls");
		printf("\nParabens! Voce matou todos os fantasmas!!											\n");
		printf("		     ___________															\n");
		printf("                             .---'::' `---.											\n");
		printf("                            (::::::' )												\n");
		printf("                            |`-----._______.-----'|									\n");
		printf("                            | :::::::|												\n");
		printf("                           .| ::::::!-.												\n");
		printf("                           \\| :::::/|/												\n");
		printf("                            | ::::::|												\n");
		printf("                            | Prêmio PACMAN        :|								\n");
		printf("                            | PARABENS!!::::|										\n");
		printf("                            | ::::::|												\n");
		printf("                            | .::::::|												\n");
		printf("                            J :::::::FILE											\n");
		printf("                             \\ :::::::/											\n");
		printf("                              `. .:::::::'											\n");
		printf("                                `-._ .::::::-'										\n");
		printf("____________________________________| \"\"|\"_______________________________________\n");
		printf("                                    | :::|											\n");
		printf("                                    F ::J 											\n");
		printf("                                   / ::\\                                        	\n");
		printf("                              __.-' :::`-.__										\n");
		printf("                             (_ ::::::_)											\n");
		printf("                               `\"\"\"---------\"\"\"'								\n");
	}

	system("pause");
}

int main(){
	leMapa(&a);
	temPilula = 0;
	vitoria = 0;
	int fim = 0;
	encontrarFantasma(&a);
	do{
		fim = acabou();
		imprimeMapa(&a);
		mover();
	}while(!fim);
	mensagemFim();
	liberaMapa(&a);	
}