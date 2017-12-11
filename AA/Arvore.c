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
		if(indice < elem->indice){
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
		else{
			*dir = -99;
			return NULL;
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
	if(pai == NULL && *dir == -99){
		return 0;
	}

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

		return -1;
	if(*arvore == NULL)
		return -1;

	int alt_esq = altura_arvore(&((*arvore)->esq));
	int alt_dir = altura_arvore(&((*arvore)->dir));

	if(alt_esq > alt_dir)
		return alt_esq + 1;
	else
		return alt_dir + 1;
}

int fator_balanceamento(Elemento* no){

	return altura_arvore(&(no->esq)) - altura_arvore(&(no->dir));
}

void copia_arvore(Arvore* from, Arvore* to){

	if(from == NULL || to == NULL)
		return;

	Elemento* no = *from;
	if(no != NULL){
		inserir_arvore(to, no->indice, no->site);
		copia_arvore(&((*from)->dir), to);
		copia_arvore(&((*from)->esq), to);
	}
}

void interseccao_arvore(Arvore* from1, Arvore* from2, Arvore* to){

	if(from1 == NULL || from2 == NULL || to == NULL)
		return;

	Elemento* no1 = *from1;
	Elemento* no2 = *from2;
	if(no1 != NULL && no2 != NULL && no1->indice == no2->indice){

		int sorted = rand() % 2;
		if(sorted == 0)
			inserir_arvore(to, no1->indice, no1->site);
		else
			inserir_arvore(to, no2->indice, no2->site);

		interseccao_arvore(&((*from1)->dir), &((*from2)->dir), to);
		interseccao_arvore(&((*from1)->esq), &((*from1)->esq), to);
	}
}

Elemento* consulta_arvore(Arvore* arvore, int indice){

	if(arvore == NULL)
		return NULL;

	if(*arvore == NULL)
		return NULL;

	Elemento* no = *arvore;
	while(no != NULL){

		if(indice == no->indice)
			return no;

		if(indice > no->indice)
			no = no->dir;
		else
			no = no->esq;
	}

	return no;
}

void printa_arvore(Arvore* arvore){

	if(arvore == NULL)
		return;

	if(*arvore == NULL)
		return;

	printf("%i site:%s\n", (*arvore)->indice, (*arvore)->site);
	printa_arvore(&((*arvore)->esq));
	printa_arvore(&((*arvore)->dir));
}