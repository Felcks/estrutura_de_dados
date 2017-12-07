#ifndef ARVORE_H_
#define	ARVORE_H_

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
void printa_arvore(Arvore* arvore);

#endif