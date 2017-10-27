#include "Arvore.h"
#include <stdlib.h>
#include <stdio.h>

Arvore* cria_arvore(){

	Arvore* arvore;
	arvore = (Arvore*)malloc(sizeof(Arvore));
	if(arvore != NULL)
		*arvore = NULL;

	return arvore;
}

void libera_no(Elemento* no){
	if(no == NULL)
		return;

	libera_no(no->esq);
	libera_no(no->dir);
	free(no);
	no = NULL;
}

void libera_arvore(Arvore* arvore){
	if(arvore == NULL)
		return;

	libera_no(*arvore);
	free(arvore);
}

int arvore_vazia(Arvore* arvore){
	if(arvore == NULL)
		return 1;

	if(*arvore == NULL)
		return 1;

	return 0;
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


int qtd_nos_arvore(Arvore* arvore){
	if(arvore == NULL)
		return 0;
	if(*arvore == NULL)
		return 0;

	int alt_esq = qtd_nos_arvore(&(*arvore)->esq);
	int alt_dir = qtd_nos_arvore(&(*arvore)->dir);
	return alt_esq + alt_dir + 1;
}

Elemento* inserir(Arvore* arvore, Elemento* elem, int dados, int* dir){

	if(elem != NULL){
		if(dados <= elem->dados){
			if(elem->esq == NULL){
				*dir = 0;
				return elem;
			}
			else
				return inserir(arvore, elem->esq, dados, dir);
		}
		else if(dados > elem->dados){
			if(elem->dir == NULL){
				*dir = 1;
				return elem;
			}
			else
				return inserir(arvore, elem->dir, dados, dir);
		}
	}
	else{
		return (Elemento*)*arvore;
	}

}

int inserir_arvore(Arvore* arvore, int dados){

	if(arvore == NULL)
		return 0;

	int *dir = calloc(1, sizeof(int));
	Elemento* pai = inserir(arvore, *arvore, dados, dir);
	Elemento* filho = (Elemento*)malloc(sizeof(Elemento));
	filho->dados = dados;
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

Elemento* remove_atual(Elemento* atual){

	Elemento *no, *no2;
	if(atual->esq == NULL){
		no2 = atual->dir;
		free(atual);
		return no2;
	}

	no = atual;
	no2 = atual->esq;
	while(no2->dir != NULL){
		no = no2;
		no2 = no2->dir;
	}

	if(no != atual){
		no->dir = no2->esq;
		no2->esq = atual->esq;
	}
	no2->dir = atual->dir;
	free(atual);
	return no2;
}

int remove_arvore(Arvore* arvore, int dados){

	if(arvore == NULL)
		return 0;
	if(*arvore == NULL)
		return 0;

	Elemento* atual = *arvore;
	Elemento* ant = NULL;

	while(atual != NULL){

		if(dados == atual->dados){
			if(atual == *arvore)
				*arvore = remove_atual(atual);
			else{
				if(ant->dir == atual)
					ant->dir = remove_atual(atual);
				else
					ant->esq = remove_atual(atual);
			}
			return 1;
		}

		ant = atual;
		if(dados > atual->dados)
			atual = atual->dir;
		else
			atual = atual->esq;
	}

	return 0;
}

int consulta_arvore(Arvore* arvore, int dados){

	if(arvore == NULL)
		return 0;

	if(*arvore == NULL)
		return 0;

	Elemento* no = *arvore;
	while(no != NULL){

		if(dados == no->dados)
			return 1;

		if(dados > no->dados)
			no = no->dir;
		else
			no = no->esq;
	}

	return 0;
}

int fator_balanceamento(Elemento* no){

	return altura_arvore(&(no->esq)) - altura_arvore(&(no->dir));
}

void rotacao_esquerda(Arvore* arvore, Elemento* no){

	//pegar elemento mais a esquerda do elemento a direita
	Elemento* dir = no->dir;
	Elemento* mais_esq = dir->esq;
	
	dir->esq = no;
	no->dir = mais_esq;
	*arvore = dir;
}

void rotacao_direita(Arvore* arvore, Elemento* no){

	Elemento* esq = no->esq;
	Elemento* mais_dir = esq->dir;
	
	esq->dir = no;
	no->esq = mais_dir;
	*arvore = esq;
}

void printa_arvore(Arvore* arvore){

	if(arvore == NULL)
		return;

	if(*arvore == NULL)
		return;

	printf("%i\n", (*arvore)->dados);
	printa_arvore(&((*arvore)->esq));
	printa_arvore(&((*arvore)->dir));

}