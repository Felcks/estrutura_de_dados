#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncDesc.h"

struct elemento {
	struct aluno dados;
	struct elemento *prox;
};
typedef struct elemento Elem;

struct descritor {
	struct elemento *inicio; 
	struct elemento *final;
	int qtd; 
};


Lista* cria_lista(){
	Lista* li = (Lista*)malloc(sizeof(Lista));
	if(li != NULL){
		li->inicio = NULL;
		li->final = NULL;
		li->qtd = 0;
	}

	return li;
}


void libera_lista(Lista* li){
	
	if(li == NULL) return;

	Elem *no;
	while(li->inicio != NULL){
		no = li->inicio;
		li->inicio = no->prox;
		free(no);
	}
	free(li);
}

int insere_lista_inicio(Lista* li, struct aluno al){

	if(li == NULL) return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL)
		return 0;

	no->dados = al;
	no->prox = li->inicio;
	if(li->inicio == NULL)
		li->final = no;

	li->inicio = no;
	li->qtd++;
	return 1;
}

int insere_lista_final(Lista* li, struct aluno al){

	if(li == NULL) return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL)
		return 0;

	no->dados = al;
	no->prox = NULL;
	if(li->final == NULL)
		li->inicio = no;
	else
		li->final->prox = no;

	li->final = no;
	li->qtd++;
	return 1;
}

int remove_lista_inicio(Lista* li){

	if(li == NULL) return 0;

	if(li->inicio == NULL) return 0;

	Elem* no = li->inicio;
	li->inicio = no->prox;
	free(no);

	if(li->inicio == NULL)
		li->final = NULL;

	li->qtd--;
	return 1;
} 

int remove_lista_final(Lista* li){

	if(li == NULL) return 0;

	if(li->inicio == NULL) return 0;

	Elem* no = li->inicio;
	Elem* ant = NULL;
	while(no->prox != NULL){
		ant = no;
		no = no->prox;
	}

	if(ant == NULL){
		li->inicio = NULL;
		li->final = NULL;
	}
	else{
		ant->prox = li->final->prox;
		li->final = ant;
	}

	li->qtd--;
	free(no);
	return 1;
}


void printa_lista(Lista* li){

	if(li == NULL) return;

	Elem* no = li->inicio;
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
