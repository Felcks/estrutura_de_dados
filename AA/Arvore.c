#include "Arvore.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Arvore* cria_arvore(){

	Arvore* arvore;
	arvore = (Arvore*)malloc(sizeof(Arvore));
	if(arvore != NULL)
		*arvore = NULL;

	return arvore;
}

void libera_arvore(Arvore* arvore){
	if(arvore == NULL)
		return;

	libera_no(*arvore);
	free(arvore);
}

void libera_no(Elemento* no){
	if(no == NULL)
		return;

	libera_no(no->esq);
	libera_no(no->dir);
	free(no);
	no = NULL;
}

Elemento* inserir(Arvore* arvore, Elemento* elem, int indice, int* dir){

	if(elem != NULL){
		if(indice <= elem->indice){
			if(elem->esq == NULL){
				*dir = 0;
				return elem;
			}
			else
				return inserir(arvore, elem->esq, indice, dir);
		}
		else if(indice > elem->indice){
			if(elem->dir == NULL){
				*dir = 1;
				return elem;
			}
			else
				return inserir(arvore, elem->dir, indice, dir);
		}
	}
	else{
		return (Elemento*)*arvore;
	}

}

int inserir_arvore(Arvore* arvore, unsigned int indice, char* site){

	if(arvore == NULL)
		return 0;

	int *dir = calloc(1, sizeof(int));
	Elemento* pai = inserir(arvore, *arvore, indice, dir);
	Elemento* filho = (Elemento*)malloc(sizeof(Elemento));
	filho->indice = indice;
	strcpy(filho->site, site);
	filho->esq = NULL;
	filho->dir = NULL;
	filho->pai = pai;

	if(pai != NULL){
		if(*dir == 0){
			pai->esq = filho;
		}
		else{
			pai->dir = filho;	
		}
		
	}
	else{
		*arvore = filho;
	}

	return 1;
}

int altura_arvore(Arvore* arvore){
	if(arvore == NULL)

		return -2;
	if(*arvore == NULL)
		return -2;

	int alt_esq = altura_arvore(&((*arvore)->esq));
	int alt_dir = altura_arvore(&((*arvore)->dir));

	if(alt_esq > alt_dir)
		return alt_esq + 1;
	else
		return alt_dir + 1;
}

void printa_arvore(Arvore* arvore){

	if(arvore == NULL)
		return;
	if(*arvore == NULL)
		return;

	printf("%i\n", (*arvore)->indice);
	printa_arvore(&((*arvore)->esq));
	printa_arvore(&((*arvore)->dir));
}