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