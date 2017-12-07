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