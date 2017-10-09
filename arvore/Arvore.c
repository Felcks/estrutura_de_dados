#include "Arvore.h"
#include <stdlib.h>
#include <stdio.h>

Arvore* criar_arvore(){

	Arvore* arvore;
	arvore = (Arvore*)malloc(sizeof(Arvore));
	if(arvore != NULL)
		*arvore = NULL;

	return arvore;
}

Elemento* inserir(Arvore* arvore, Elemento* elem, int dados, int* dir){

	if(elem != NULL){
		if(dados <= elem->dados){
			if(elem->esq == NULL){
				return elem;
				*dir = 0;
			}
			else
				return inserir(arvore, elem->esq, dados, dir);
		}
		else if(dados > elem->dados){
			if(elem->dir == NULL){
				return elem;
				*dir = 1;
			}
			else
				return inserir(arvore, elem->dir, dados, dir);
		}
	}
	else{
		printf("bb\n");
		return (Elemento*)*arvore;
	}

}

int inserir_arvore(Arvore* arvore, int dados){

	if(arvore == NULL)
		return 0;

	int *dir = calloc(1, sizeof(int));
	Elemento* pai = inserir(arvore, *arvore, dados, dir);
	printf("dd\n");
	Elemento* filho = (Elemento*)malloc(sizeof(Elemento));
	filho->dados = dados;
	filho->esq = NULL;
	filho->dir = NULL;
	filho->pai = pai;
	printf("ee\n");

	if(pai != NULL){
		if(dir == 0){
			pai->esq = filho;
		}
		else
			pai->dir = filho;	
		
	}

	return 1;
}