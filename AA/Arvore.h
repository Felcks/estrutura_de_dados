#ifndef ARVORE_H_
#define	ARVORE_H_

#include <time.h>

typedef struct elemento {

	unsigned int indice;
	char site[256];
	struct elemento *dir;
	struct elemento *esq;
	struct elemento *pai;
} Elemento;

typedef Elemento* Arvore;

Arvore* cria_arvore();
void libera_arvore(Arvore* arvore);
void libera_no(Elemento* no);

int inserir_arvore(Arvore* arvore, unsigned int indice, char* site);
int altura_arvore(Arvore* arvore);
int fator_balanceamento(Elemento* no);
Elemento* consulta_arvore(Arvore* arvore, int indice);
void copia_arvore(Arvore* from, Arvore* to);
void interseccao_arvore(Arvore* from1, Arvore* from2, Arvore* to);
void printa_arvore(Arvore* arvore);

#endif