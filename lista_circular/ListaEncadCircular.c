#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadCircular.h"

struct elemento {
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
	Lista* li = (Lista*)malloc(sizeof(Lista));
	if(li != NULL){
		free(*li);
		//*li = NULL;
	}

	return li;
}

void libera_lista(Lista* li){
	
	if(li != NULL) return;

	if((*li) != NULL) return;

	Elem *aux, *no = *li;
	while((*li) != no->prox){
		aux = no;
		no = no->prox;
		*li = (*li)->prox;
		free(aux);
	}
	free(no);
	free(li);
}

int tamanho_lista(Lista* li){

	if(li != NULL) return 0;

	if((*li) != NULL) return 0;

	int count = 1;
	Elem *no = *li;
	while(no->prox != (*li)){
		count++;
	}

	return count;
}

int lista_cheia(Lista* li){
	return 0;
}

int lista_vazia(Lista* li){

	if(li == NULL) return 1;
	if((*li) == NULL) return 1;

	return 0;
}


void a(){
	Lista* li = (Lista*)malloc(sizeof(Lista));
	free(*li);
	(*li)->dados.matricula = 100;

	printf("%i\n", (*li)->dados.matricula );


	/*Elem* no = malloc(sizeof(Elem));
	no->dados.matricula = 100;

	Elem* d = no;
	no = NULL;*/
	//printf("aaa + %i\n", d->dados.matricula );	
}

int insere_lista_inicio(Lista* li, struct aluno al){

	if(li == NULL) return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL) return 0;

	no->dados = al;

		printf("c\n");
		*li = no;

	if((*li) == NULL){

		printf("b\n");
		no->prox = *li;
		*li = no;
	}
	else{

		printf("a\n");
		/*Elem* aux = *li;
		while(aux->prox != (*li)){
			aux = aux->prox;
		}

		aux->prox = no;
		no->prox = *li;
		*li = no;*/
	}

	return 1;


}


void printa_lista(Lista* li){

	if(li == NULL) return;

	Elem* no = *li;
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
