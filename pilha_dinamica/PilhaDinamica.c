#include <stdio.h>
#include <stdlib.h>
#include "PilhaDinamica.h"

struct elemento {
	struct aluno dados;
	struct elemento* prox;
};
typedef struct elemento Elem;

Pilha* cria_pilha(){

	Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
	if(pi != NULL){
		*pi = NULL;
	}

	return pi;
}

void libera_pilha(Pilha* pi){

	if(pi == NULL) return;

	while(*pi != NULL){
		Elem* no = *pi;
		*pi = (*pi)->prox;
		free(no);
	}

	free(pi);
}

int tamanho_pilha(Pilha* pi){

	if(pi == NULL) return -1;

	int count = 0;
	Elem* no = *pi;
	while(no != NULL){
		count++;
		no = no->prox;
	}

	return count;
}

int pilha_cheia(Pilha* pi){

	if(pi == NULL) return -1;

	return 0;
}

int pilha_vazia(Pilha* pi){

	if(pi == NULL) return -1;

	return *pi == NULL;
}

int insere_pilha(Pilha* pi, struct aluno al){

	if(pi == NULL) return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL) return 0;

	no->dados = al;
	no->prox = *pi;
	*pi = no;

	return 1;
}

int remove_pilha(Pilha* pi){

	if(pi == NULL) return 0;

	if(*pi == NULL) return 0;

	Elem* no = *pi;
	*pi = no->prox;
	free(no);
	return 1;
}

void printa_pilha(Pilha* pi){

	if(pi == NULL) return;

	Elem* no = *pi;
	while(no != NULL){
		printf("%i\n", no->dados.matricula);
		no = no->prox;
	}
}

struct aluno* cria_aluno(int matricula){
	struct aluno* al = (struct aluno*)malloc(sizeof(struct aluno));
	al->matricula = matricula;

	return al; 
} 