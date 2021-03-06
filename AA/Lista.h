#ifndef LISTA_H_
#define	LISTA_H_

#include "Arvore.h"

typedef struct elementoLista {

	unsigned int indice;
	struct elementoLista *prox;
	Arvore *arvore;
} ElementoLista;

typedef ElementoLista* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int remove_lista(Lista* li, int indice);

ElementoLista* cria_elemento_lista(unsigned int indice);
int insere_lista_final(Lista* li, ElementoLista* no);
ElementoLista* consulta_lista(Lista* li, int indice);


#endif