#include <stdio.h>
#include "Arvore.h"

int main(void){
	
	Arvore* arvore = cria_arvore();

	//rotação dupla direita (esquerda depois direita)
	int b = inserir_arvore(arvore, 8);
	int c = inserir_arvore(arvore, 4);
	int d = inserir_arvore(arvore, 10);
	int e = inserir_arvore(arvore, 2);
	int f = inserir_arvore(arvore, 6);
	int g = inserir_arvore(arvore, 5);
	
	//rotação a direita simples
	/*int b = inserir_arvore(arvore, 8);
	int c = inserir_arvore(arvore, 4);
	int d = inserir_arvore(arvore, 10);
	int e = inserir_arvore(arvore, 9);
	int f = inserir_arvore(arvore, 15);
	int g = inserir_arvore(arvore, 12);*/

	//printf("%i", consulta_arvore(arvore, 2));
	//printa_arvore(arvore);
	
	int fb = fator_balanceamento(*arvore);
	printf("fator balanceamento: %i\n", fb);

	if(fb == -2){

		int fb_filho = fator_balanceamento((*arvore)->esq);
		printf("fator filho %i\n", fb_filho);

		if(fb_filho == -1)
			rotacao_esquerda(arvore, *arvore);
		else{
			rotacao_direita( &((*arvore)->dir), (*arvore)->dir);
			rotacao_esquerda(arvore, *arvore);
		}
	}
	else if(fb == 2){
		
		int fb_filho = fator_balanceamento((*arvore)->esq);
		printf("fator filho %i\n", fb_filho);
		if(fb_filho == 1){
			rotacao_direita(arvore, *arvore);
		}
		else{
			rotacao_esquerda( &((*arvore)->esq), (*arvore)->esq);
			rotacao_direita(arvore, *arvore);
		}
	}


	printa_arvore(arvore);
	return 0;
}