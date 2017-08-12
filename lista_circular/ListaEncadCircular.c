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
		*li = NULL;
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

	if(li == NULL) return 0;

	if((*li) == NULL) return 0;

	int count = 0;
	Elem *no = *li;
	do{
		count++;
		no = no->prox;
	}
	while(no != (*li));
		

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

int insere_lista_inicio(Lista* li, struct aluno al){

	if(li == NULL) return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL) return 0;

	no->dados = al;

	if((*li) == NULL){
		*li = no;
		no->prox = no;
	}
	else{

		Elem* aux = *li;
		while(aux->prox != (*li)){
			aux = aux->prox;
		}

		aux->prox = no;
		no->prox = *li;
		*li = no;
	}

	return 1;
}

int insere_lista_final(Lista* li, struct aluno al){

	if(li == NULL) return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL) return 0;

	no->dados = al;

	if((*li) == NULL){
		*li = no;
		no->prox = no;
	}
	else{

		Elem* aux = *li;
		while(aux->prox != (*li)){
			aux = aux->prox;
		}

		aux->prox = no;
		no->prox = *li;
	}
}

int insere_lista_ordenada(Lista* li, struct aluno al){

	if(li == NULL) return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL) return 0;

	no->dados = al;

	if((*li) == NULL){
		*li = no;
		no->prox = no;
	}
	else{

		Elem* aux = *li;
		Elem* ant = NULL;

		while(aux->prox != (*li) && aux->dados.matricula < al.matricula){
			ant = aux;
			aux = aux->prox;
		}

		if(ant != NULL){ 
			//Meio ou fim
			no->prox = aux;
			ant->prox = no;
		}
		else{ 
			if(al.matricula > aux->dados.matricula){
				//Lista Unitaria - segundo elemento
				no->prox = aux->prox;
				aux->prox = no;
			}
			else{
				//Lista Unitaria - primeiro elemento
				no->prox = aux;
				aux->prox = no;
				*li = no;
			}
		}
	}

	return 1;
}

int remove_lista_inicio(Lista* li){

	if(li == NULL) return 0;

	if(*li == NULL) return 0;

	if((*li)->prox == *li){
		free(*li);
		*li = NULL;
		return 1;
	}

	Elem* no =  *li;
	while(no->prox != *li){
		no = no->prox;
	}

	Elem* rm = *li;
	no->prox = rm->prox;
	*li = rm->prox;

	free(rm);

	return 1;
}

int remove_lista_final(Lista* li){

	if(li == NULL) return 0;

	if(*li == NULL) return 0;

	if((*li)->prox == *li){
		free(*li);
		*li = NULL;
		return 1;
	}

	Elem* no = *li;
	Elem* ant;
	while(no->prox != (*li)){
		ant = no;
		no = no->prox;
	}

	ant->prox = *li;
	free(no);

	return 1;
}

int remove_lista(Lista* li, int mat){

	if(li == NULL) return 0;

	if(*li == NULL) return 0;

	Elem *no = *li;
	Elem *ant = NULL;

	if(no->dados.matricula == mat){

		if(no->prox != *li){
			*li = no->prox;

			Elem* aux = no;
			while(aux->prox != no){
				aux = aux->prox;
			}

			aux->prox = no->prox;
		}
		else
			*li = NULL;

		free(no);
		return 1;
	}

	do{
		if(mat == no->dados.matricula){
			break;
		}

		ant = no;
		no = no->prox;
	}
	while(no != *li);

	if(no == *li) return 0;

	ant->prox = no->prox;

	free(no);
	return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){

	if(li == NULL) return 0;

	if(*li == NULL) return 0;

	if(pos <= 0) return 0;

	if(pos == 1){
		*al = (*li)->dados;
		return 1;
	}


	Elem* no = (*li)->prox;
	int count = 2;
	while(no != *li && count < pos){
		count++;
		no = no->prox;
	}

	if(no == *li)
		return 0;

	*al = no->dados;
	return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){

	if(li == NULL) return 0;

	if(*li == NULL) return 0;

	if(mat == (*li)->dados.matricula){
		*al = (*li)->dados;
		return 1;
	}

	Elem* no = (*li)->prox;
	while(no != *li){
		if(no->dados.matricula == mat)
			break;

		no = no->prox;
	}

	if(no == *li)
		return 0;

	*al = no->dados;
	return 1;
}

void printa_lista(Lista* li){

	if(li == NULL) return;
	if(*li == NULL) return;

	Elem* no = *li;
	
	do{
		printf("%i\n", no->dados.matricula );
		no = no->prox;
	} while(no != *li);
}

struct aluno* cria_aluno(int matricula){
	struct aluno* al = (struct aluno*)malloc(sizeof(struct aluno));
	al->matricula = matricula;

	return al; 
}
