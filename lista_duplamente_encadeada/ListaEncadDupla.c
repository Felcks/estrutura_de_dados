#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadDupla.h"

struct elemento {
	struct elemento *ant;
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
	Lista* li = (Lista*)malloc(sizeof(Lista));
	if(li != NULL){
		*li = NULL;
	}

	return li;
}


void libera_lista(Lista* li){
	
	if(li != NULL){
		Elem* no = *li;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}	
}


int tamanho_lista(Lista* li){

	if(li == NULL) return 0;

	int count = 0;
	Elem* no = *li;
	while(no != NULL){
		count++;
		no = no->prox;
	}
	return count;
}

int lista_cheia(Lista* li){
	return 0;
}

int lista_vazia(Lista* li){
	if(li == NULL) return 1;

	if(*li == NULL) return 1;

	return 0;
}


int insere_lista_inicio(Lista* li, struct aluno al){

	if(li == NULL) return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL) return 0;

	no->dados = al;
	no->prox = *li;
	no->ant = NULL;


	if(*li != NULL)
		(*li)->ant = no;

	*li = no;

	return 1;
}


int insere_lista_final(Lista* li, struct aluno al){
	
	if(li == NULL) return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL) return 0;

	no->dados = al;
	no->prox = NULL;

	
	if(*li != NULL){
		Elem* aux = *li;
		while(aux->prox != NULL){
			aux = aux->prox;
		}

		no->ant = aux;
		aux->prox = no;
	}
	else{
		no->ant = NULL;
		*li = no;
	}
		
	return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){

	if(li == NULL) return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL) return 0;

	no->dados = al;
	if(*li == NULL){
		no->prox = NULL;
		no->ant = NULL;
		*li = no;
		return 1;
	}
	else{
		Elem* aux = *li;
		Elem* ant;
		while(aux != NULL && aux->dados.matricula < al.matricula){
			ant = aux;
			aux = aux->prox;
		}

		if(aux == *li){
			//Insere inicio
			no->ant = NULL;
			no->prox = *li;
			(*li)->ant = no;
			*li = no;
		}
		else{
			//Insere meio ou fim
			no->prox = aux;
			no->ant = ant;
			ant->prox = no;
			if(aux != NULL)
				aux->ant = no;
		}
	}

	return 1;
}

int remove_lista_inicio(Lista* li){

	if(li == NULL) return 0;

	if(*li == NULL) return 0;

	Elem* no = *li;
	*li = no->prox;
	if(no->prox != NULL)
		no->prox->ant = NULL;

	free(no);
	return 1;
}

int remove_lista_final(Lista* li){

	if(li == NULL) return 0;

	if(*li == NULL) return 0;

	Elem* no = *li;
	while(no->prox != NULL){
		no = no->prox;
	}

	if(no == *li){
		*li = no->prox;
	}
	else{
		no->ant->prox = NULL;
	}

	free(no);
	return 1;
}

int remove_lista(Lista* li, int mat){

	if(li == NULL) return 0;

	if(*li == NULL) return 0;

	Elem* no = *li;
	Elem* ant;
	while(no != NULL){
		if(no->dados.matricula == mat){
			break;
		}

		ant = no;
		no = no->prox;
	}

	if(no == NULL) return 0;

	if(no == (*li)){
		*li = no->prox;
	}
	else if(no != NULL){
		ant->prox = no->prox;

		if(no->prox != NULL)
			no->prox->ant = ant;
	}


	free(no);
	return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
	if(li == NULL) return 0;

	if(*li == NULL) return 0;

	int count = 1;
	Elem* no = *li;
	while(count < pos && no != NULL){
		no = no->prox;
		count++;
	}

	if(no == NULL) return 0;

	*al = no->dados;

	return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
	if(li == NULL) return 0;

	if(*li == NULL) return 0;

	Elem* no = *li;
	while(no != NULL){
		if(no->dados.matricula == mat){
			break;
		}

		no = no->prox;
	}

	if(no == NULL) return 0;

	*al = no->dados;

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
