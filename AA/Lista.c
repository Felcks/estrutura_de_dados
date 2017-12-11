#include "Lista.h"
#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>

Lista* cria_lista(){

	Lista* li = (Lista*)malloc(sizeof(Lista));
	if(li != NULL)
		*li = NULL;

	return li;
}

void libera_lista(Lista* li){
	if(li != NULL){
		ElementoLista* no;
		while((*li) != NULL){
			no = *li;
			libera_arvore((*li)->arvore);
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}
}

int remove_lista(Lista* li, int indice){

	if(li == NULL) return 0;

	ElementoLista *ant, *no = *li;
	while(no != NULL && no->indice != indice){
		ant = no;
		no = no->prox;
	}

	if(no == NULL) return 0;

	if(no == *li){
		*li = no->prox;
	}
	else{
		ant->prox = no->prox;
	}

	libera_arvore(no->arvore);
	free(no);

	return 1;
}

int insere_lista_final(Lista* li, ElementoLista* no){
	if(li == NULL) return 0;

	no->prox = NULL;

	if((*li) == NULL){ //Lista vazia
		*li = no;
	}
	else{
		ElementoLista* aux = *li;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = no;
	}

	return 1;
}

ElementoLista* cria_elemento_lista(unsigned int indice){

	ElementoLista* elementoLista = (ElementoLista*)malloc(sizeof(ElementoLista));
	elementoLista->indice = indice;

	return elementoLista;
}

ElementoLista* consulta_lista(Lista* li, int indice){
	
	if(li == NULL) return NULL;

	ElementoLista* no = *li;
	while(no != NULL && no->indice != indice){
		no = no->prox;
	}

	return no;
}
