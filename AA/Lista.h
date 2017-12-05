#ifndef LISTA_H_
#define	LISTA_H_

#include "Arvore.h"

typedef struct elementoLista {

	unsigned int indice;
	void *prox;
	Arvore *arvore;
} ElementoLista;

typedef ElementoLista* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);

#endif