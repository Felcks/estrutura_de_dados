#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>

Arvore* cria_arvore(){

	Arvore* arvore;
	arvore = (Arvore*)malloc(sizeof(Arvore));
	if(arvore != NULL)
		*arvore = NULL;

	return arvore;
}

void libera_arvore(Arvore* arvore){
	if(arvore == NULL)
		return;

	libera_no(*arvore);
	free(arvore);
}

void libera_no(Elemento* no){
	if(no == NULL)
		return;

	libera_no(no->esq);
	libera_no(no->dir);
	free(no);
	no = NULL;
}