#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstatica.h"

struct pilha {
	int qtd;
	struct aluno dados[MAX];
};

Pilha* cria_pilha(){

	Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
	if(pi != NULL){
		pi->qtd = 0;

	}
	return pi;
}

void libera_pilha(Pilha* pi){

	free(pi);
}

int tamanho_pilha(Pilha* pi){

	if(pi == NULL) return -1;

	return pi->qtd;
}

int pilha_cheia(Pilha* pi){

	if(pi == NULL) return -1;

	return pi->qtd == MAX;
}

int pilha_vazia(Pilha* pi){

	if(pi == NULL) return -1;

	return pi->qtd == 0;
}

int insere_pilha(Pilha* pi, struct aluno al){

	if(pi == NULL) return 0;
	if(pilha_cheia(pi)) return 0;

	pi->dados[pi->qtd] = al;
	pi->qtd++;

	return 1;
}

int remove_pilha(Pilha* pi){

	if(pi == NULL) return 0;
	if(pilha_vazia(pi)) return 0;

	pi->qtd--;
	return 1;
}

int consulta_pilha(Pilha* pi, struct aluno *al){

	if(pi == NULL) return 0;
	if(pilha_vazia(pi)) return 0;

	*al = pi->dados[pi->qtd - 1];
	return 1;
}

void printa_pilha(Pilha* pi){

	if(pi == NULL) return;

	printf("%i\n", pi->qtd);
	int i = pi->qtd - 1;
	for(i; i >= 0; i--){
		printf("%i \n", pi->dados[i].matricula);
	}
}

struct aluno* cria_aluno(int matricula){
	struct aluno* al = (struct aluno*)malloc(sizeof(struct aluno));
	al->matricula = matricula;

	return al; 
} 