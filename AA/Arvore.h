#ifndef ARVORE_H_
#define	ARVORE_H_

typedef struct elemento {

	unsigned int indice;
	char site[256];
	void *dir;
	void *esq;
} Elemento;

typedef Elemento* Arvore;

Arvore* cria_arvore();
void libera_arvore(Arvore* arvore);
void libera_no(Elemento* no);


#endif